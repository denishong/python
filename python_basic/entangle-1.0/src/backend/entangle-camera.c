/*
 *  Entangle: Tethered Camera Control & Capture
 *
 *  Copyright (C) 2009-2017 Daniel P. Berrange
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <glib.h>
#include <glib/gi18n.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gphoto2.h>
#include <string.h>
#include <math.h>

#include "entangle-debug.h"
#include "entangle-camera.h"
#include "entangle-camera-enums.h"
#include "entangle-control-button.h"
#include "entangle-control-choice.h"
#include "entangle-control-date.h"
#include "entangle-control-group.h"
#include "entangle-control-range.h"
#include "entangle-control-text.h"
#include "entangle-control-toggle.h"

#define ENTANGLE_CAMERA_GET_PRIVATE(obj)                                \
    (G_TYPE_INSTANCE_GET_PRIVATE((obj), ENTANGLE_TYPE_CAMERA, EntangleCameraPrivate))

#if GLIB_CHECK_VERSION(2, 31, 0)
#define g_mutex_new() g_new0(GMutex, 1)
#define g_mutex_free(m) g_free(m)
#define g_cond_new() g_new0(GCond, 1)
#define g_cond_free(c) g_free(c)
#endif

struct _EntangleCameraPrivate {
    GMutex *lock;
    GCond *jobCond;
    gboolean jobActive;

    GPContext *ctx;
    CameraAbilitiesList *caps;
    GPPortInfoList *ports;
    Camera *cam;


    CameraWidget *widgets;
    EntangleControlGroup *controls;
    GHashTable *controlPaths;

    EntangleProgress *progress;

    char *lastError;

    char *model;  /* R/O */
    char *port;   /* R/O */

    char *manual;
    char *summary;
    char *driver;

    gboolean hasCapture;
    gboolean hasPreview;
    gboolean hasSettings;
    gboolean hasViewfinder;
};

G_DEFINE_TYPE(EntangleCamera, entangle_camera, G_TYPE_OBJECT);

enum {
    PROP_0,
    PROP_MODEL,
    PROP_PORT,
    PROP_MANUAL,
    PROP_SUMMARY,
    PROP_DRIVER,
    PROP_PROGRESS,
    PROP_HAS_CAPTURE,
    PROP_HAS_PREVIEW,
    PROP_HAS_SETTINGS,
    PROP_HAS_VIEWFINDER,
};

#define ENTANGLE_CAMERA_ERROR entangle_camera_error_quark ()

static GQuark entangle_camera_error_quark(void)
{
    return g_quark_from_static_string("entangle-camera-error");
}


static EntangleControl *do_build_controls(EntangleCamera *cam,
                                          const char *path,
                                          CameraWidget *widget,
                                          GError **error);
static gboolean do_load_controls(EntangleCamera *cam,
                                 const char *path,
                                 CameraWidget *widget,
                                 GError **error);

struct EntangleCameraEventData {
    EntangleCamera *cam;
    GObject *arg;
    char *signame;
};


static gboolean entangle_camera_emit_idle(gpointer opaque)
{
    struct EntangleCameraEventData *data = opaque;

    g_signal_emit_by_name(data->cam, data->signame, data->arg);

    g_free(data->signame);
    g_object_unref(data->cam);
    if (data->arg)
        g_object_unref(data->arg);
    g_free(data);
    return FALSE;
}


static void entangle_camera_emit_deferred(EntangleCamera *cam,
                                          const char *signame,
                                          GObject *arg)
{
    struct EntangleCameraEventData *data = g_new0(struct EntangleCameraEventData, 1);
    data->cam = cam;
    data->arg = arg;
    data->signame = g_strdup(signame);
    g_object_ref(cam);
    if (arg)
        g_object_ref(arg);

    g_idle_add(entangle_camera_emit_idle, data);
}


static void entangle_camera_begin_job(EntangleCamera *cam)
{
    EntangleCameraPrivate *priv = cam->priv;

    g_object_ref(cam);

    while (priv->jobActive) {
        g_cond_wait(priv->jobCond, priv->lock);
    }

    priv->jobActive = TRUE;
    g_free(priv->lastError);
    priv->lastError = NULL;
    g_mutex_unlock(priv->lock);
}


static void entangle_camera_end_job(EntangleCamera *cam)
{
    EntangleCameraPrivate *priv = cam->priv;

    priv->jobActive = FALSE;
    g_cond_broadcast(priv->jobCond);
    g_mutex_lock(priv->lock);
    g_object_unref(cam);
}


static void entangle_camera_get_property(GObject *object,
                                         guint prop_id,
                                         GValue *value,
                                         GParamSpec *pspec)
{
    EntangleCamera *cam = ENTANGLE_CAMERA(object);
    EntangleCameraPrivate *priv = cam->priv;

    switch (prop_id)
        {
        case PROP_MODEL:
            g_value_set_string(value, priv->model);
            break;

        case PROP_PORT:
            g_value_set_string(value, priv->port);
            break;

        case PROP_MANUAL:
            g_value_set_string(value, priv->manual);
            break;

        case PROP_SUMMARY:
            g_value_set_string(value, priv->summary);
            break;

        case PROP_DRIVER:
            g_value_set_string(value, priv->driver);
            break;

        case PROP_PROGRESS:
            g_value_set_object(value, priv->progress);
            break;

        case PROP_HAS_CAPTURE:
            g_value_set_boolean(value, priv->hasCapture);
            break;

        case PROP_HAS_PREVIEW:
            g_value_set_boolean(value, priv->hasPreview);
            break;

        case PROP_HAS_SETTINGS:
            g_value_set_boolean(value, priv->hasSettings);
            break;

        case PROP_HAS_VIEWFINDER:
            g_value_set_boolean(value, priv->hasViewfinder);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
        }
}

static void entangle_camera_set_property(GObject *object,
                                         guint prop_id,
                                         const GValue *value,
                                         GParamSpec *pspec)
{
    EntangleCamera *cam = ENTANGLE_CAMERA(object);
    EntangleCameraPrivate *priv = cam->priv;

    switch (prop_id)
        {
        case PROP_MODEL:
            g_free(priv->model);
            priv->model = g_value_dup_string(value);
            break;

        case PROP_PORT:
            g_free(priv->port);
            priv->port = g_value_dup_string(value);
            break;

        case PROP_PROGRESS:
            entangle_camera_set_progress(cam, g_value_get_object(value));
            break;

        case PROP_HAS_CAPTURE:
            priv->hasCapture = g_value_get_boolean(value);
            ENTANGLE_DEBUG("Set has capture %d", priv->hasCapture);
            break;

        case PROP_HAS_PREVIEW:
            priv->hasPreview = g_value_get_boolean(value);
            ENTANGLE_DEBUG("Set has preview %d", priv->hasPreview);
            break;

        case PROP_HAS_SETTINGS:
            priv->hasSettings = g_value_get_boolean(value);
            ENTANGLE_DEBUG("Set has settings %d", priv->hasSettings);
            break;

        case PROP_HAS_VIEWFINDER:
            priv->hasViewfinder = g_value_get_boolean(value);
            ENTANGLE_DEBUG("Set has viewfinder %d", priv->hasViewfinder);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
        }
}


static void entangle_camera_finalize(GObject *object)
{
    EntangleCamera *cam = ENTANGLE_CAMERA(object);
    EntangleCameraPrivate *priv = cam->priv;

    ENTANGLE_DEBUG("Finalize camera %p", object);

    if (priv->progress)
        g_object_unref(priv->progress);
    if (priv->cam) {
        gp_camera_exit(priv->cam, priv->ctx);
        gp_camera_free(priv->cam);
    }
    if (priv->widgets)
        gp_widget_unref(priv->widgets);
    if (priv->controls)
        g_object_unref(priv->controls);
    if (priv->controlPaths)
        g_hash_table_unref(priv->controlPaths);
    if (priv->ports)
        gp_port_info_list_free(priv->ports);
    if (priv->caps)
        gp_abilities_list_free(priv->caps);
    gp_context_unref(priv->ctx);
    g_free(priv->driver);
    g_free(priv->summary);
    g_free(priv->manual);
    g_free(priv->model);
    g_free(priv->port);
    g_free(priv->lastError);
    g_mutex_free(priv->lock);
    g_cond_free(priv->jobCond);

    G_OBJECT_CLASS(entangle_camera_parent_class)->finalize(object);
}


static void entangle_camera_class_init(EntangleCameraClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS(klass);

    object_class->finalize = entangle_camera_finalize;
    object_class->get_property = entangle_camera_get_property;
    object_class->set_property = entangle_camera_set_property;


    g_signal_new("camera-file-added",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__OBJECT,
                 G_TYPE_NONE,
                 1,
                 ENTANGLE_TYPE_CAMERA_FILE);

    g_signal_new("camera-file-captured",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__OBJECT,
                 G_TYPE_NONE,
                 1,
                 ENTANGLE_TYPE_CAMERA_FILE);

    g_signal_new("camera-file-previewed",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__OBJECT,
                 G_TYPE_NONE,
                 1,
                 ENTANGLE_TYPE_CAMERA_FILE);

    g_signal_new("camera-file-downloaded",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__OBJECT,
                 G_TYPE_NONE,
                 1,
                 ENTANGLE_TYPE_CAMERA_FILE);

    g_signal_new("camera-file-deleted",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__OBJECT,
                 G_TYPE_NONE,
                 1,
                 ENTANGLE_TYPE_CAMERA_FILE);

    g_signal_new("camera-connected",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__VOID,
                 G_TYPE_NONE,
                 0);

    g_signal_new("camera-disconnected",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__VOID,
                 G_TYPE_NONE,
                 0);

    g_signal_new("camera-controls-changed",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__VOID,
                 G_TYPE_NONE,
                 0);


    g_object_class_install_property(object_class,
                                    PROP_MODEL,
                                    g_param_spec_string("model",
                                                        "Camera model",
                                                        "Model name of the camera",
                                                        NULL,
                                                        G_PARAM_READWRITE |
                                                        G_PARAM_CONSTRUCT_ONLY |
                                                        G_PARAM_STATIC_NAME |
                                                        G_PARAM_STATIC_NICK |
                                                        G_PARAM_STATIC_BLURB));
    g_object_class_install_property(object_class,
                                    PROP_PORT,
                                    g_param_spec_string("port",
                                                        "Camera port",
                                                        "Device port of the camera",
                                                        NULL,
                                                        G_PARAM_READWRITE |
                                                        G_PARAM_CONSTRUCT_ONLY |
                                                        G_PARAM_STATIC_NAME |
                                                        G_PARAM_STATIC_NICK |
                                                        G_PARAM_STATIC_BLURB));

    g_object_class_install_property(object_class,
                                    PROP_SUMMARY,
                                    g_param_spec_string("summary",
                                                        "Camera summary",
                                                        "Camera summary",
                                                        NULL,
                                                        G_PARAM_READABLE |
                                                        G_PARAM_STATIC_NAME |
                                                        G_PARAM_STATIC_NICK |
                                                        G_PARAM_STATIC_BLURB));

    g_object_class_install_property(object_class,
                                    PROP_MANUAL,
                                    g_param_spec_string("manual",
                                                        "Camera manual",
                                                        "Camera manual",
                                                        NULL,
                                                        G_PARAM_READABLE |
                                                        G_PARAM_STATIC_NAME |
                                                        G_PARAM_STATIC_NICK |
                                                        G_PARAM_STATIC_BLURB));

    g_object_class_install_property(object_class,
                                    PROP_DRIVER,
                                    g_param_spec_string("driver",
                                                        "Camera driver info",
                                                        "Camera driver information",
                                                        NULL,
                                                        G_PARAM_READABLE |
                                                        G_PARAM_STATIC_NAME |
                                                        G_PARAM_STATIC_NICK |
                                                        G_PARAM_STATIC_BLURB));

    g_object_class_install_property(object_class,
                                    PROP_PROGRESS,
                                    g_param_spec_object("progress",
                                                        "Progress updater",
                                                        "Operation progress updater",
                                                        ENTANGLE_TYPE_PROGRESS,
                                                        G_PARAM_READWRITE |
                                                        G_PARAM_STATIC_NAME |
                                                        G_PARAM_STATIC_NICK |
                                                        G_PARAM_STATIC_BLURB));

    g_object_class_install_property(object_class,
                                    PROP_HAS_CAPTURE,
                                    g_param_spec_boolean("has-capture",
                                                         "Capture supported",
                                                         "Whether image capture is supported",
                                                         FALSE,
                                                         G_PARAM_READWRITE |
                                                         G_PARAM_CONSTRUCT_ONLY |
                                                         G_PARAM_STATIC_NAME |
                                                         G_PARAM_STATIC_NICK |
                                                         G_PARAM_STATIC_BLURB));
    g_object_class_install_property(object_class,
                                    PROP_HAS_PREVIEW,
                                    g_param_spec_boolean("has-preview",
                                                         "Preview supported",
                                                         "Whether image preview is supported",
                                                         FALSE,
                                                         G_PARAM_READWRITE |
                                                         G_PARAM_CONSTRUCT_ONLY |
                                                         G_PARAM_STATIC_NAME |
                                                         G_PARAM_STATIC_NICK |
                                                         G_PARAM_STATIC_BLURB));
    g_object_class_install_property(object_class,
                                    PROP_HAS_SETTINGS,
                                    g_param_spec_boolean("has-settings",
                                                         "Settings supported",
                                                         "Whether camera settings configuration is supported",
                                                         FALSE,
                                                         G_PARAM_READWRITE |
                                                         G_PARAM_CONSTRUCT_ONLY |
                                                         G_PARAM_STATIC_NAME |
                                                         G_PARAM_STATIC_NICK |
                                                         G_PARAM_STATIC_BLURB));
    g_object_class_install_property(object_class,
                                    PROP_HAS_VIEWFINDER,
                                    g_param_spec_boolean("has-viewfinder",
                                                         "Viewfinder supported",
                                                         "Whether camera viewfinder configuration is supported",
                                                         FALSE,
                                                         G_PARAM_READWRITE |
                                                         G_PARAM_CONSTRUCT_ONLY |
                                                         G_PARAM_STATIC_NAME |
                                                         G_PARAM_STATIC_NICK |
                                                         G_PARAM_STATIC_BLURB));
    ENTANGLE_DEBUG("install prog done");

    g_type_class_add_private(klass, sizeof(EntangleCameraPrivate));
}


EntangleCamera *entangle_camera_new(const char *model,
                                    const char *port,
                                    gboolean hasCapture,
                                    gboolean hasPreview,
                                    gboolean hasSettings)
{
    return ENTANGLE_CAMERA(g_object_new(ENTANGLE_TYPE_CAMERA,
                                        "model", model,
                                        "port", port,
                                        "has-capture", hasCapture,
                                        "has-preview", hasPreview,
                                        "has-settings", hasSettings,
                                        NULL));
}


static void entangle_camera_init(EntangleCamera *cam)
{
    cam->priv = ENTANGLE_CAMERA_GET_PRIVATE(cam);
    cam->priv->lock = g_mutex_new();
    cam->priv->jobCond = g_cond_new();
}


/**
 * entangle_camera_get_model:
 * @cam: (transfer none): the camera
 *
 * Get the camera model name
 *
 * Returns: (transfer none): the model name
 */
const char *entangle_camera_get_model(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    EntangleCameraPrivate *priv = cam->priv;
    return priv->model;
}


/**
 * entangle_camera_get_port:
 * @cam: (transfer none): the camera
 *
 * Get the camera port name
 *
 * Returns: (transfer none): the port name
 */
const char *entangle_camera_get_port(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    EntangleCameraPrivate *priv = cam->priv;
    return priv->port;
}

struct EntangleCameraProgressData {
    EntangleCamera *cam;
    enum {
        ENTANGLE_CAMERA_PROGRESS_START,
        ENTANGLE_CAMERA_PROGRESS_UPDATE,
        ENTANGLE_CAMERA_PROGRESS_STOP
    } op;
    float value;
    char *msg;
};

static gboolean entangle_camera_progress_idle(gpointer opaque)
{
    struct EntangleCameraProgressData *data = opaque;

    if (data->cam->priv->progress) {
        switch (data->op) {
        case ENTANGLE_CAMERA_PROGRESS_START:
            entangle_progress_start(data->cam->priv->progress,
                                    data->value,
                                    data->msg);
            break;

        case ENTANGLE_CAMERA_PROGRESS_UPDATE:
            entangle_progress_update(data->cam->priv->progress,
                                     data->value);
            break;

        case ENTANGLE_CAMERA_PROGRESS_STOP:
            entangle_progress_stop(data->cam->priv->progress);
            break;

        default:
            break;
        }
    }

    if (data->op == ENTANGLE_CAMERA_PROGRESS_START)
        g_free(data->msg);
    g_object_unref(data->cam);
    g_free(data);

    return FALSE;
}

static unsigned int do_entangle_camera_progress_start(GPContext *ctx G_GNUC_UNUSED,
                                                      float target,
                                                      const char *msg,
                                                      void *opaque)
{
    EntangleCamera *cam = opaque;
    struct EntangleCameraProgressData *data = g_new0(struct EntangleCameraProgressData, 1);

    data->cam = g_object_ref(cam);
    data->op = ENTANGLE_CAMERA_PROGRESS_START;
    data->value = target;
    data->msg = g_strdup(msg);

    g_idle_add(entangle_camera_progress_idle, data);

    return 0; /* XXX what is this actually useful for ? */
}

static void do_entangle_camera_progress_update(GPContext *ctx G_GNUC_UNUSED,
                                               unsigned int id G_GNUC_UNUSED,
                                               float current,
                                               void *opaque)
{
    EntangleCamera *cam = opaque;
    struct EntangleCameraProgressData *data = g_new0(struct EntangleCameraProgressData, 1);

    data->cam = g_object_ref(cam);
    data->op = ENTANGLE_CAMERA_PROGRESS_UPDATE;
    data->value = current;

    g_idle_add(entangle_camera_progress_idle, data);
}

static void do_entangle_camera_progress_stop(GPContext *ctx G_GNUC_UNUSED,
                                             unsigned int id G_GNUC_UNUSED,
                                             void *opaque)
{
    EntangleCamera *cam = opaque;
    struct EntangleCameraProgressData *data = g_new0(struct EntangleCameraProgressData, 1);

    data->cam = g_object_ref(cam);
    data->op = ENTANGLE_CAMERA_PROGRESS_STOP;

    g_idle_add(entangle_camera_progress_idle, data);
}

static void do_entangle_camera_error(GPContext *ctx G_GNUC_UNUSED,
                                     const char *msg,
                                     void *data)
{
    EntangleCamera *cam = data;
    EntangleCameraPrivate *priv = cam->priv;

    g_free(priv->lastError);
    priv->lastError = g_strdup(msg);
    ENTANGLE_DEBUG("Got error %s", priv->lastError);
}


/**
 * entangle_camera_connect:
 * @cam: (transfer none): the camera
 *
 * Attempt to connect to and initialize the camera. This
 * may fail if the camera is in use by another application,
 * has gone to sleep or has been disconnected from the port.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if the camera is connected, FALSE on error
 */
gboolean entangle_camera_connect(EntangleCamera *cam,
                                 GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    int i;
    GPPortInfo port;
    CameraAbilities cap;
    CameraText txt;
    int err;
    gboolean ret = FALSE;

    ENTANGLE_DEBUG("Conencting to cam");

    g_mutex_lock(priv->lock);

    if (priv->cam != NULL) {
        ret = TRUE;
        goto cleanup;
    }

    priv->ctx = gp_context_new();

    if (gp_abilities_list_new(&priv->caps) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Cannot initialize gphoto2 abilities"));
        goto cleanup;
    }

    if (gp_abilities_list_load(priv->caps, priv->ctx) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Cannot load gphoto2 abilities"));
        goto cleanup;
    }

    if (gp_port_info_list_new(&priv->ports) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Cannot initialize gphoto2 ports"));
        goto cleanup;
    }

    if (gp_port_info_list_load(priv->ports) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Cannot load gphoto2 ports"));
        goto cleanup;
    }

    gp_context_set_error_func(priv->ctx,
                              do_entangle_camera_error,
                              cam);
    gp_context_set_progress_funcs(priv->ctx,
                                  do_entangle_camera_progress_start,
                                  do_entangle_camera_progress_update,
                                  do_entangle_camera_progress_stop,
                                  cam);

    i = gp_port_info_list_lookup_path(priv->ports, priv->port);
    gp_port_info_list_get_info(priv->ports, i, &port);

    i = gp_abilities_list_lookup_model(priv->caps, priv->model);
    gp_abilities_list_get_abilities(priv->caps, i, &cap);

    gp_camera_new(&priv->cam);
    gp_camera_set_abilities(priv->cam, cap);
    gp_camera_set_port_info(priv->cam, port);

    entangle_camera_begin_job(cam);
    err = gp_camera_init(priv->cam, priv->ctx);
    entangle_camera_end_job(cam);

    if (err != GP_OK) {
        gp_camera_unref(priv->cam);
        priv->cam = NULL;
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to initialize camera: %s"), priv->lastError);
        goto cleanup;
    }

    /* Update capabilities as a sanity-check against orignal constructor */
    priv->hasCapture = priv->hasPreview = priv->hasSettings = FALSE;
    if (cap.operations & GP_OPERATION_CAPTURE_IMAGE)
        priv->hasCapture = TRUE;
    if (cap.operations & GP_OPERATION_CAPTURE_PREVIEW)
        priv->hasPreview = TRUE;
    if (cap.operations & GP_OPERATION_CONFIG)
        priv->hasSettings = TRUE;
    priv->hasViewfinder = FALSE;

    gp_camera_get_summary(priv->cam, &txt, priv->ctx);
    priv->summary = g_strdup(txt.text);

    gp_camera_get_manual(priv->cam, &txt, priv->ctx);
    priv->manual = g_strdup(txt.text);

    gp_camera_get_about(priv->cam, &txt, priv->ctx);
    priv->driver = g_strdup(txt.text);

    ENTANGLE_DEBUG("ok");
    ret = TRUE;

 cleanup:
    g_mutex_unlock(priv->lock);
    if (ret)
        entangle_camera_emit_deferred(cam, "camera-connected", NULL);
    return ret;
}


static void entangle_camera_connect_helper(GTask *task,
                                           gpointer object,
                                           gpointer task_data G_GNUC_UNUSED,
                                           GCancellable *cancellable G_GNUC_UNUSED)
{
    GError *error = NULL;

    if (!entangle_camera_connect(ENTANGLE_CAMERA(object), &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_connect_async:
 * @cam: (transfer none): the camera
 *
 * Attempt to connect to and initialize the camera. This
 * may fail if the camera is in use by another application,
 * has gone to sleep or has been disconnected from the port.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_connect_finish
 * can be used to check the status
 */
void entangle_camera_connect_async(EntangleCamera *cam,
                                   GCancellable *cancellable,
                                   GAsyncReadyCallback callback,
                                   gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_task_run_in_thread(task,
                         entangle_camera_connect_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_connect_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_connect_async
 *
 * Returns: TRUE if the camera is connected, FALSE on error
 */
gboolean entangle_camera_connect_finish(EntangleCamera *cam,
                                        GAsyncResult *result,
                                        GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


/**
 * entangle_camera_disconnect:
 * @cam: (transfer none): the camera
 *
 * Disconnect from the camera, enabling it to be used by
 * other applications.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if the camera is disconnected, FALSE on error
 */
gboolean entangle_camera_disconnect(EntangleCamera *cam,
                                    GError **error G_GNUC_UNUSED)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret = FALSE;

    ENTANGLE_DEBUG("Disconnecting from cam");

    g_mutex_lock(priv->lock);

    if (priv->cam == NULL) {
        ret = TRUE;
        goto cleanup;
    }

    entangle_camera_begin_job(cam);
    gp_camera_exit(priv->cam, priv->ctx);
    entangle_camera_end_job(cam);

    if (priv->widgets) {
        gp_widget_unref(priv->widgets);
        priv->widgets = NULL;
    }
    if (priv->controls) {
        g_object_unref(priv->controls);
        priv->controls = NULL;
    }
    if (priv->controlPaths) {
        g_hash_table_unref(priv->controlPaths);
        priv->controlPaths = NULL;
    }

    g_free(priv->driver);
    g_free(priv->manual);
    g_free(priv->summary);
    priv->driver = priv->manual = priv->summary = NULL;

    if (priv->ports) {
        gp_port_info_list_free(priv->ports);
        priv->ports = NULL;
    }
    if (priv->caps) {
        gp_abilities_list_free(priv->caps);
        priv->caps = NULL;
    }
    gp_context_unref(priv->ctx);
    priv->ctx = NULL;

    gp_camera_unref(priv->cam);
    priv->cam = NULL;
    priv->hasViewfinder = FALSE;

    ret = TRUE;
 cleanup:
    g_mutex_unlock(priv->lock);
    if (ret)
        entangle_camera_emit_deferred(cam, "camera-disconnected", NULL);
    return ret;
}


static void entangle_camera_disconnect_helper(GTask *task,
                                              gpointer object,
                                              gpointer task_data G_GNUC_UNUSED,
                                              GCancellable *cancellable G_GNUC_UNUSED)
{
    GError *error = NULL;

    if (!entangle_camera_disconnect(ENTANGLE_CAMERA(object), &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_disconnect_async:
 * @cam: (transfer none): the camera
 *
 * Disconnect from the camera, enabling it to be used by
 * other applications.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_connect_async
 * can be used to check the status
 */
void entangle_camera_disconnect_async(EntangleCamera *cam,
                                      GCancellable *cancellable,
                                      GAsyncReadyCallback callback,
                                      gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_task_run_in_thread(task,
                         entangle_camera_disconnect_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_disconnect_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_disconnect_async
 *
 * Returns: TRUE if the camera is disconnected, FALSE on error
 */
gboolean entangle_camera_disconnect_finish(EntangleCamera *cam,
                                           GAsyncResult *result,
                                           GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


/**
 * entangle_camera_get_connected:
 * @cam: (transfer none): the camera
 *
 * Determine if the camera is currently connected
 *
 * Returns: TRUE if the camera is connected, FALSE otherwise
 */
gboolean entangle_camera_get_connected(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret;

    g_mutex_lock(priv->lock);
    ret = priv->cam != NULL ? TRUE : FALSE;
    g_mutex_unlock(priv->lock);
    return ret;
}


/**
 * entangle_camera_get_summary:
 * @cam: (transfer none): the camera
 *
 * Get the camera summary text. This is only available
 * while the camera is connected
 *
 * Returns: (transfer full): the camera summary
 */
char *entangle_camera_get_summary(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    EntangleCameraPrivate *priv = cam->priv;
    char *ret;

    g_mutex_lock(priv->lock);
    ret = g_strdup(priv->summary);
    g_mutex_unlock(priv->lock);

    return ret;
}



/**
 * entangle_camera_get_manual:
 * @cam: (transfer none): the camera
 *
 * Get the camera manual text. This is only available
 * while the camera is connected
 *
 * Returns: (transfer full): the camera manual
 */
char *entangle_camera_get_manual(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    EntangleCameraPrivate *priv = cam->priv;
    char *ret;

    g_mutex_lock(priv->lock);
    ret = g_strdup(priv->manual);
    g_mutex_unlock(priv->lock);

    return ret;
}


/**
 * entangle_camera_get_driver:
 * @cam: (transfer none): the camera
 *
 * Get the camera driver information text. This is only available
 * while the camera is connected
 *
 * Returns: (transfer full): the camera driver information
 */
char *entangle_camera_get_driver(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    EntangleCameraPrivate *priv = cam->priv;
    char *ret;

    g_mutex_lock(priv->lock);
    ret = g_strdup(priv->driver);
    g_mutex_unlock(priv->lock);

    return ret;
}


/**
 * entangle_camera_capture_image:
 * @cam: (transfer none): the camera
 *
 * Trigger the camera shutter and download the first resulting
 * image. If the camera is shooting in multiple formats (eg JPEG
 * and RAW) this method will only return the first format captured
 * The caller should watch for signal notifications to detect any
 * additional images
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: (transfer full): the captured image or NULL
 */
EntangleCameraFile *entangle_camera_capture_image(EntangleCamera *cam,
                                                  GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    EntangleCameraPrivate *priv = cam->priv;
    CameraFilePath camerapath;
    EntangleCameraFile *file = NULL;
    int err;

    g_mutex_lock(priv->lock);

    if (!priv->cam) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Cannot capture image while not connected"));
        goto cleanup;
    }

    ENTANGLE_DEBUG("Starting capture");
    entangle_camera_begin_job(cam);
    err = gp_camera_capture(priv->cam,
                            GP_CAPTURE_IMAGE,
                            &camerapath,
                            priv->ctx);
    entangle_camera_end_job(cam);
    if (err!= GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to capture image: %s"), priv->lastError);
        goto cleanup;
    }

    file = entangle_camera_file_new(camerapath.folder,
                                    camerapath.name);

    entangle_camera_emit_deferred(cam, "camera-file-captured", G_OBJECT(file));

 cleanup:
    g_mutex_unlock(priv->lock);
    return file;
}


static void entangle_camera_capture_image_helper(GTask *task,
                                                 gpointer object,
                                                 gpointer task_data G_GNUC_UNUSED,
                                                 GCancellable *cancellable G_GNUC_UNUSED)
{
    EntangleCameraFile *file;
    GError *error = NULL;

    if (!(file = entangle_camera_capture_image(ENTANGLE_CAMERA(object), &error))) {
        g_task_return_error(task, error);
    } else {
        g_task_return_pointer(task, file, g_object_unref);
    }
}


/**
 * entangle_camera_capture_image_async:
 * @cam: (transfer none): the camera
 *
 * Trigger the camera shutter and download the first resulting
 * image. If the camera is shooting in multiple formats (eg JPEG
 * and RAW) this method will only return the first format captured
 * The caller should watch for signal notifications to detect any
 * additional images
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_capture_image_finish
 * can be used to check the status
 */
void entangle_camera_capture_image_async(EntangleCamera *cam,
                                         GCancellable *cancellable,
                                         GAsyncReadyCallback callback,
                                         gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_task_run_in_thread(task,
                         entangle_camera_capture_image_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_capture_image_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_capture_image_async.
 *
 * Returns: (transfer full): the captured image or NULL
 */
EntangleCameraFile *entangle_camera_capture_image_finish(EntangleCamera *cam,
                                                         GAsyncResult *result,
                                                         GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    return g_task_propagate_pointer(G_TASK(result), error);
}


/**
 * entangle_camera_preview_image:
 * @cam: (transfer none): the camera
 *
 * Enable "live view", if not already enabled, and capture a
 * low resolution preview image. The "live view" mode will
 * remain enabled after execution.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: (transfer full): the captured image or NULL
 */
EntangleCameraFile *entangle_camera_preview_image(EntangleCamera *cam,
                                                  GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    EntangleCameraPrivate *priv = cam->priv;
    EntangleCameraFile *file = NULL;
    CameraFile *datafile = NULL;
    const char *mimetype = NULL;
    GByteArray *data = NULL;
    const char *rawdata;
    unsigned long int rawdatalen;
    const char *name;
    int err;

    g_mutex_lock(priv->lock);

    if (!priv->cam) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Cannot preview image while not connected"));
        goto cleanup;
    }

    gp_file_new(&datafile);

    ENTANGLE_DEBUG("Starting preview");
    entangle_camera_begin_job(cam);
    err = gp_camera_capture_preview(priv->cam,
                                    datafile,
                                    priv->ctx);
    entangle_camera_end_job(cam);

    if (err != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to capture preview: %s"), priv->lastError);
        goto cleanup;
    }


    if (gp_file_get_data_and_size(datafile, &rawdata, &rawdatalen) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to get file data: %s"), priv->lastError);
        goto cleanup;
    }

    if (gp_file_get_name(datafile, &name) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to get filename: %s"), priv->lastError);
        goto cleanup;
    }

    file = entangle_camera_file_new(NULL, NULL);

    if (gp_file_get_mime_type(datafile, &mimetype) == GP_OK)
        entangle_camera_file_set_mimetype(file, mimetype);

    data = g_byte_array_new();
    g_byte_array_append(data, (const guint8 *)rawdata, rawdatalen);

    entangle_camera_file_set_data(file, data);
    g_byte_array_unref(data);

    entangle_camera_emit_deferred(cam, "camera-file-previewed", G_OBJECT(file));

 cleanup:
    if (datafile)
        gp_file_unref(datafile);
    g_mutex_unlock(priv->lock);
    return file;
}


static void entangle_camera_preview_image_helper(GTask *task,
                                                 gpointer object,
                                                 gpointer task_data G_GNUC_UNUSED,
                                                 GCancellable *cancellable G_GNUC_UNUSED)
{
    EntangleCameraFile *file;
    GError *error = NULL;

    if (!(file = entangle_camera_preview_image(ENTANGLE_CAMERA(object), &error))) {
        g_task_return_error(task, error);
    } else {
        g_task_return_pointer(task, file, g_object_unref);
    }
}


/**
 * entangle_camera_preview_image_async:
 * @cam: (transfer none): the camera
 *
 * Enable "live view", if not already enabled, and capture a
 * low resolution preview image. The "live view" mode will
 * remain enabled after execution.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_preview_image_finish
 * can be used to check the status
 */
void entangle_camera_preview_image_async(EntangleCamera *cam,
                                         GCancellable *cancellable,
                                         GAsyncReadyCallback callback,
                                         gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_task_run_in_thread(task,
                         entangle_camera_preview_image_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_preview_image_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_preview_image_async.
 *
 * Returns: (transfer full): the captured image or NULL
 */
EntangleCameraFile *entangle_camera_preview_image_finish(EntangleCamera *cam,
                                                         GAsyncResult *result,
                                                         GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    return g_task_propagate_pointer(G_TASK(result), error);
}


/**
 * entangle_camera_download_file:
 * @cam: (transfer none): the camera
 * @file: (transfer none): the file whose contents to download
 *
 * Download the data associated with @file and set the data
 * on @file.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if the file was downloaded, FALSE on error
 */
gboolean entangle_camera_download_file(EntangleCamera *cam,
                                       EntangleCameraFile *file,
                                       GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);
    g_return_val_if_fail(ENTANGLE_IS_CAMERA_FILE(file), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    CameraFile *datafile = NULL;
    const char *data;
    unsigned long int datalen;
    GByteArray *filedata;
    gboolean ret = FALSE;
    int err;

    g_mutex_lock(priv->lock);

    if (!priv->cam) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Cannot download file while not connected"));
        goto cleanup;
    }

    ENTANGLE_DEBUG("Downloading '%s' from '%s'",
                   entangle_camera_file_get_name(file),
                   entangle_camera_file_get_folder(file));

    gp_file_new(&datafile);

    ENTANGLE_DEBUG("Getting file data");
    entangle_camera_begin_job(cam);
    err = gp_camera_file_get(priv->cam,
                             entangle_camera_file_get_folder(file),
                             entangle_camera_file_get_name(file),
                             GP_FILE_TYPE_NORMAL,
                             datafile,
                             priv->ctx);
    g_usleep(1000*100);
    entangle_camera_end_job(cam);

    if (err != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to get camera file: %s"), priv->lastError);
        goto cleanup;
    }

    ENTANGLE_DEBUG("Fetching data");
    if (gp_file_get_data_and_size(datafile, &data, &datalen) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to get file data: %s"), priv->lastError);
        goto cleanup;
    }

    filedata = g_byte_array_new();
    g_byte_array_append(filedata, (const guint8*)data, datalen);

    entangle_camera_file_set_data(file, filedata);
    g_byte_array_unref(filedata);

    entangle_camera_emit_deferred(cam, "camera-file-downloaded", G_OBJECT(file));

    ret = TRUE;

 cleanup:
    ENTANGLE_DEBUG("Error");
    if (datafile)
        gp_file_unref(datafile);
    g_mutex_unlock(priv->lock);
    return ret;
}


static void entangle_camera_download_file_helper(GTask *task,
                                                 gpointer object,
                                                 gpointer task_data,
                                                 GCancellable *cancellable G_GNUC_UNUSED)
{
    EntangleCameraFile *file = ENTANGLE_CAMERA_FILE(task_data);
    GError *error = NULL;

    if (!entangle_camera_download_file(ENTANGLE_CAMERA(object), file, &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_download_file_async:
 * @cam: (transfer none): the camera
 * @file: (transfer none): the file whose contents to download
 *
 * Download the data associated with @file and set the data
 * on @file.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_download_file_finish
 * can be used to check the status
 */
void entangle_camera_download_file_async(EntangleCamera *cam,
                                         EntangleCameraFile *file,
                                         GCancellable *cancellable,
                                         GAsyncReadyCallback callback,
                                         gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));
    g_return_if_fail(ENTANGLE_IS_CAMERA_FILE(file));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_object_ref(file);
    g_task_set_task_data(task, file, g_object_unref);

    g_task_run_in_thread(task,
                         entangle_camera_download_file_helper);
    g_object_unref(task);

}

/**
 * entangle_camera_download_file_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_download_file_async.
 *
 * Returns: TRUE if the file was downloaded, FALSE on error
 */
gboolean entangle_camera_download_file_finish(EntangleCamera *cam,
                                              GAsyncResult *result,
                                              GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


/**
 * entangle_camera_delete_file:
 * @cam: (transfer none): the camera
 * @file: (transfer none): the file to delete
 *
 * Delete @file from the camera capture target.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if the file was deleted, FALSE on error
 */
gboolean entangle_camera_delete_file(EntangleCamera *cam,
                                     EntangleCameraFile *file,
                                     GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);
    g_return_val_if_fail(ENTANGLE_IS_CAMERA_FILE(file), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret = FALSE;
    int err;

    g_mutex_lock(priv->lock);

    if (!priv->cam) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Cannot delete file while not connected"));
        goto cleanup;
    }

    ENTANGLE_DEBUG("Deleting '%s' from '%s'",
                   entangle_camera_file_get_name(file),
                   entangle_camera_file_get_folder(file));

    entangle_camera_begin_job(cam);
    err = gp_camera_file_delete(priv->cam,
                                entangle_camera_file_get_folder(file),
                                entangle_camera_file_get_name(file),
                                priv->ctx);
    g_usleep(1000*100);
    entangle_camera_end_job(cam);

    if (err != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to delete file: %s"), priv->lastError);
        goto cleanup;
    }

    entangle_camera_emit_deferred(cam, "camera-file-deleted", G_OBJECT(file));

    ret = TRUE;

 cleanup:
    g_mutex_unlock(priv->lock);
    return ret;
}


static void entangle_camera_delete_file_helper(GTask *task,
                                               gpointer object,
                                               gpointer task_data,
                                               GCancellable *cancellable G_GNUC_UNUSED)
{
    EntangleCameraFile *file = ENTANGLE_CAMERA_FILE(task_data);
    GError *error = NULL;

    if (!entangle_camera_delete_file(ENTANGLE_CAMERA(object), file, &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_delete_file_async:
 * @cam: (transfer none): the camera
 * @file: (transfer none): the file to delete
 *
 * Delete @file from the camera capture target.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_delete_file_finish
 * can be used to check the status
 */
void entangle_camera_delete_file_async(EntangleCamera *cam,
                                       EntangleCameraFile *file,
                                       GCancellable *cancellable,
                                       GAsyncReadyCallback callback,
                                       gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));
    g_return_if_fail(ENTANGLE_IS_CAMERA_FILE(file));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_object_ref(file);
    g_task_set_task_data(task, file, g_object_unref);

    g_task_run_in_thread(task,
                         entangle_camera_delete_file_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_delete_file_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_delete_file_async.
 *
 * Returns: TRUE if the file was deleted, FALSE on error
 */
gboolean entangle_camera_delete_file_finish(EntangleCamera *cam,
                                            GAsyncResult *result,
                                            GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


/**
 * entangle_camera_process_events:
 * @cam: (transfer none): the camera
 * @waitms: the number of milliseconds to wait
 *
 * Wait upto @waitms milliseconds for events to arrive from
 * the camera. Signals will be emitted for any interesting
 * events that arrive. Multiple events will be processed
 * until @waitms is exceeded.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if the file was deleted, FALSE on error
 */
gboolean entangle_camera_process_events(EntangleCamera *cam,
                                        guint64 waitms,
                                        GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    CameraEventType eventType = 0;
    void *eventData = NULL;
    GTimeVal tv;
    guint64 startms, endms, donems;
    gboolean ret = FALSE;
    int err;

    g_mutex_lock(priv->lock);

    if (!priv->cam) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Cannot wait for events while not connected"));
        goto cleanup;
    }

    g_get_current_time(&tv);
    startms = (tv.tv_sec * 1000ll) + (tv.tv_usec / 1000ll);

    ENTANGLE_DEBUG("Waiting for events start %llu duration %llu",
                   (unsigned long long)startms,
                   (unsigned long long)waitms);

    donems = 0;
    do {
        entangle_camera_begin_job(cam);
        err = gp_camera_wait_for_event(priv->cam, waitms - donems, &eventType, &eventData, priv->ctx);
        entangle_camera_end_job(cam);

        if (err != GP_OK) {
            /* Some drivers (eg canon native) can't do events, so just do a sleep */
            if (err == GP_ERROR_NOT_SUPPORTED) {
                ENTANGLE_DEBUG("Event wait not supported, using usleep");
                g_usleep((waitms-donems)*1000ll);
                ret = TRUE;
                goto cleanup;
            }
            g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                        _("Unable to wait for events: %s"), priv->lastError);
            goto cleanup;
        }
        ENTANGLE_DEBUG("Event type %d", eventType);
        switch (eventType) {
        case GP_EVENT_UNKNOWN:
            if (eventData &&
                strstr((char*)eventData, "PTP Property") &&
                strstr((char*)eventData, "changed")) {
                ENTANGLE_DEBUG("Config changed '%s'", (char *)eventData);
                /* For some reason, every time we request the camera config
                 * with gp_camera_get_config, it will be followed by an
                 * event with key 'd10d'. So we must ignore that event
                 */
                if (strstr(eventData, "d10d") == NULL)
                    entangle_camera_emit_deferred(cam, "camera-controls-changed", NULL);
            } else {
                ENTANGLE_DEBUG("Unknown event '%s'", (char *)eventData);
            }
            break;

        case GP_EVENT_TIMEOUT:
            ENTANGLE_DEBUG("Wait timed out");
            break;

        case GP_EVENT_FILE_ADDED: {
            CameraFilePath *camerapath = eventData;
            EntangleCameraFile *file;

            ENTANGLE_DEBUG("File added '%s' in '%s'", camerapath->name, camerapath->folder);

            file = entangle_camera_file_new(camerapath->folder,
                                            camerapath->name);

            entangle_camera_emit_deferred(cam, "camera-file-added", G_OBJECT(file));

            g_object_unref(file);
        }   break;

        case GP_EVENT_FOLDER_ADDED: {
            CameraFilePath *camerapath = eventData;

            ENTANGLE_DEBUG("Folder added '%s' in '%s'", camerapath->name, camerapath->folder);
        }   break;

        case GP_EVENT_CAPTURE_COMPLETE:
            ENTANGLE_DEBUG("Capture is complete");
            break;

        default:
            ENTANGLE_DEBUG("Unexpected event received %d", eventType);
            break;
        }

        free(eventData);
        eventData = NULL;
        g_get_current_time(&tv);
        endms = (tv.tv_sec * 1000ll) + (tv.tv_usec / 1000ll);
        donems = endms - startms;
    } while (eventType != GP_EVENT_TIMEOUT &&
             donems < waitms);

    ENTANGLE_DEBUG("Done waiting for events %llu",
                   (unsigned long long)donems);

    ret = TRUE;

 cleanup:
    free(eventData);
    g_mutex_unlock(priv->lock);
    return ret;
}


static void entangle_camera_process_events_helper(GTask *task,
                                                  gpointer object,
                                                  gpointer task_data,
                                                  GCancellable *cancellable G_GNUC_UNUSED)
{
    guint64 *waitptr = task_data;
    GError *error = NULL;

    if (!entangle_camera_process_events(ENTANGLE_CAMERA(object), *waitptr, &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_process_events_async:
 * @cam: (transfer none): the camera
 * @waitms: the number of milliseconds to wait
 *
 * Wait upto @waitms milliseconds for events to arrive from
 * the camera. Signals will be emitted for any interesting
 * events that arrive. Multiple events will be processed
 * until @waitms is exceeded.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_process_events_finish
 * can be used to check the status
 */
void entangle_camera_process_events_async(EntangleCamera *cam,
                                          guint64 waitms,
                                          GCancellable *cancellable,
                                          GAsyncReadyCallback callback,
                                          gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    guint64 *waitptr = g_new0(guint64, 1);
    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    *waitptr = waitms;
    g_task_set_task_data(task, waitptr, g_free);

    g_task_run_in_thread(task,
                         entangle_camera_process_events_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_process_events_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_process_events_async.
 *
 * Returns: TRUE if events were processed, FALSE on error
 */
gboolean entangle_camera_process_events_finish(EntangleCamera *cam,
                                               GAsyncResult *result,
                                               GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


static CameraWidget *
entangle_camera_find_widget(EntangleCamera *cam,
                            const gchar *path)
{
    EntangleCameraPrivate *priv = cam->priv;
    gchar **names = g_strsplit(path, "/", 0);
    CameraWidget *ret = NULL;
    CameraWidget *curr = priv->widgets;
    gsize i;

    for (i = 0; names[i] != NULL; i++) {
        CameraWidget *tmp;

        if (g_str_equal(names[i], "") ||
            g_str_equal(names[i], "main"))
            continue;

        if (gp_widget_get_child_by_name(curr,
                                        names[i],
                                        &tmp) != GP_OK)
            goto cleanup;

        curr = tmp;
    }

    ret = curr;

 cleanup:
    g_strfreev(names);
    return ret;
}


static EntangleControl *do_build_controls(EntangleCamera *cam,
                                          const char *path,
                                          CameraWidget *widget,
                                          GError **error)
{
    EntangleCameraPrivate *priv = cam->priv;
    CameraWidgetType type;
    EntangleControl *ret = NULL;
    const char *name;
    char *fullpath;
    int id;
    const char *label;
    const char *info;
    int ro;

    if (gp_widget_get_type(widget, &type) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget type"));
        return NULL;
    }

    if (gp_widget_get_name(widget, &name) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget name"));
        return NULL;
    }

    gp_widget_get_id(widget, &id);
    gp_widget_get_label(widget, &label);
    gp_widget_get_info(widget, &info);
    gp_widget_get_readonly(widget, &ro);
    if (info == NULL)
        info = label;

    fullpath = g_strdup_printf("%s/%s", path, name);

    switch (type) {
        /* We treat both window and section as just groups */
    case GP_WIDGET_WINDOW:
        {
            EntangleControlGroup *grp;
            ENTANGLE_DEBUG("Add group %s %d %s", fullpath, id, label);
            grp = entangle_control_group_new(fullpath, id, label, info, ro);
            for (int i = 0; i < gp_widget_count_children(widget); i++) {
                CameraWidget *child;
                EntangleControl *subctl;
                const char *childname;
                if (gp_widget_get_child(widget, i, &child) != GP_OK ||
                    gp_widget_get_name(child, &childname) != GP_OK) {
                    g_object_unref(grp);
                    goto error;
                }

                /* Actions are exposed as normal APIs
                 * And "Other ptp properties" 90% dups
                 */
                if (g_str_equal(childname, "actions") ||
                    g_str_equal(childname, "other"))
                    continue;

                if (!(subctl = do_build_controls(cam, fullpath, child, error))) {
                    g_object_unref(grp);
                    goto error;
                }

                entangle_control_group_add(grp, subctl);
            }

            ret = ENTANGLE_CONTROL(grp);
        } break;

    case GP_WIDGET_SECTION:
        {
            EntangleControlGroup *grp;
            ENTANGLE_DEBUG("Add group %s %d %s", fullpath, id, label);
            grp = entangle_control_group_new(fullpath, id, label, info, ro);
            for (int i = 0; i < gp_widget_count_children(widget); i++) {
                CameraWidget *child;
                EntangleControl *subctl;
                if (gp_widget_get_child(widget, i, &child) != GP_OK) {
                    g_object_unref(grp);
                    goto error;
                }
                if (!(subctl = do_build_controls(cam, fullpath, child, error))) {
                    g_object_unref(grp);
                    goto error;
                }

                entangle_control_group_add(grp, subctl);
            }

            ret = ENTANGLE_CONTROL(grp);
        } break;

    case GP_WIDGET_BUTTON:
        {
            ENTANGLE_DEBUG("Add button %s %d %s", fullpath, id, label);
            ret = ENTANGLE_CONTROL(entangle_control_button_new(fullpath, id, label, info, ro));
        } break;

        /* Unclear why these two are the same in libgphoto */
    case GP_WIDGET_RADIO:
    case GP_WIDGET_MENU:
        {
            ENTANGLE_DEBUG("Add menu %s %d %s", fullpath, id, label);
            ret = ENTANGLE_CONTROL(entangle_control_choice_new(fullpath, id, label, info, ro));
        } break;

    case GP_WIDGET_DATE:
        {
            ENTANGLE_DEBUG("Add date %s %d %s", fullpath, id, label);
            ret = ENTANGLE_CONTROL(entangle_control_date_new(fullpath, id, label, info, ro));
        } break;

    case GP_WIDGET_RANGE:
        {
            float min, max, step;
            gp_widget_get_range(widget, &min, &max, &step);
            ENTANGLE_DEBUG("Add range %s %d %s %f %f %f", fullpath, id, label,
                           (double)min, (double)max, (double)step);
            ret = ENTANGLE_CONTROL(entangle_control_range_new(fullpath, id, label, info, ro,
                                                              min, max, step));
        } break;

    case GP_WIDGET_TEXT:
        {
            ENTANGLE_DEBUG("Add date %s %d %s", fullpath, id, label);
            ret = ENTANGLE_CONTROL(entangle_control_text_new(fullpath, id, label, info, ro));
        } break;

    case GP_WIDGET_TOGGLE:
        {
            ENTANGLE_DEBUG("Add date %s %d %s", fullpath, id, label);
            ret = ENTANGLE_CONTROL(entangle_control_toggle_new(fullpath, id, label, info, ro));
        } break;

    default:
        g_warn_if_reached();
        break;
    }

    g_hash_table_insert(priv->controlPaths, g_strdup(fullpath), ret);

 error:
    g_free(fullpath);
    return ret;
}


static gboolean entangle_str_equal_null(gchar *a, gchar *b)
{
    if (!a && !b)
        return TRUE;
    if (!a || !b)
        return FALSE;
    return g_str_equal(a, b);
}


/*
 * XXX this method causes signals to be emitted from controls
 * in non-main threads, if triggered via an _async() method.
 * Investigate if we can fix this to always run in main thread
 * to simplify thread safety for GTK frontend
 */
static gboolean do_load_controls(EntangleCamera *cam,
                                 const char *path,
                                 CameraWidget *widget,
                                 GError **error)
{
    EntangleCameraPrivate *priv = cam->priv;
    CameraWidgetType type;
    EntangleControl *ctrl = NULL;
    const char *name;
    char *fullpath;
    int ro;
    gboolean ret = FALSE;

    if (gp_widget_get_type(widget, &type) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget type"));
        return FALSE;
    }

    if (gp_widget_get_name(widget, &name) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget name"));
        return FALSE;
    }

    gp_widget_get_readonly(widget, &ro);

    fullpath = g_strdup_printf("%s/%s", path, name);
    ctrl = g_hash_table_lookup(priv->controlPaths, fullpath);
    if (!ctrl) {
        ret = TRUE;
        goto cleanup;
    }
    entangle_control_set_readonly(ctrl, ro ? TRUE : FALSE);

    switch (type) {
        /* We treat both window and section as just groups */
    case GP_WIDGET_WINDOW:
    case GP_WIDGET_SECTION:
        for (int i = 0; i < gp_widget_count_children(widget); i++) {
            CameraWidget *child;
            if (gp_widget_get_child(widget, i, &child) == GP_OK)
                if (!do_load_controls(cam, fullpath, child, error))
                    goto cleanup;
        }
        break;

    case GP_WIDGET_BUTTON: {
    }   break;

        /* Unclear why these two are the same in libgphoto */
    case GP_WIDGET_RADIO:
    case GP_WIDGET_MENU: {
        gchar *newValue = NULL;
        gchar *oldValue = NULL;
        g_object_get(ctrl, "value", &oldValue, NULL);
        gp_widget_get_value(widget, &newValue);
        if (!entangle_str_equal_null(newValue, oldValue)) {
            ENTANGLE_DEBUG("Updating value of menu '%s' ('%s') old='%s' new='%s'",
                           entangle_control_get_path(ctrl),
                           entangle_control_get_label(ctrl),
                           oldValue, newValue);
            entangle_control_choice_clear_entries(ENTANGLE_CONTROL_CHOICE(ctrl));
            for (int i = 0; i < gp_widget_count_choices(widget); i++) {
                const char *choice;
                gp_widget_get_choice(widget, i, &choice);
                ENTANGLE_DEBUG("Add choice '%s'", choice);
                entangle_control_choice_add_entry(ENTANGLE_CONTROL_CHOICE(ctrl), choice);
            }
            g_object_set(ctrl, "value", newValue, NULL);
        }
        g_free(oldValue);
    }   break;

    case GP_WIDGET_DATE: {
        int value = 0;
        g_object_set(ctrl, "value", value, NULL);
    }   break;

    case GP_WIDGET_RANGE: {
        float newValue = 0.0;
        float oldValue = 0.0;
        g_object_get(ctrl, "value", &oldValue, NULL);
        gp_widget_get_value(widget, &newValue);
        if (fabs(newValue - oldValue) > 0.0001) {
            ENTANGLE_DEBUG("Updating value of range '%s' ('%s') old='%f' new='%f'",
                           entangle_control_get_path(ctrl),
                           entangle_control_get_label(ctrl),
                           (double)oldValue, (double)newValue);
            g_object_set(ctrl, "value", (double)newValue, NULL);
        }
    }   break;

    case GP_WIDGET_TEXT: {
        gchar *newValue = NULL;
        gchar *oldValue = NULL;
        g_object_get(ctrl, "value", &oldValue, NULL);
        gp_widget_get_value(widget, &newValue);
        if (!entangle_str_equal_null(newValue, oldValue)) {
            ENTANGLE_DEBUG("Updating value of text '%s' ('%s') old='%s' new='%s'",
                           entangle_control_get_path(ctrl),
                           entangle_control_get_label(ctrl),
                           oldValue, newValue);
            g_object_set(ctrl, "value", newValue, NULL);
        }
        g_free(oldValue);
    }   break;

    case GP_WIDGET_TOGGLE: {
        int i;
        gboolean newValue = 0;
        gboolean oldValue = 0;
        g_object_get(ctrl, "value", &oldValue, NULL);
        gp_widget_get_value(widget, &i);
        newValue = i ? TRUE : FALSE;
        if (newValue != oldValue) {
            ENTANGLE_DEBUG("Updating value of toggle '%s' ('%s') old='%d' new='%d'",
                           entangle_control_get_path(ctrl),
                           entangle_control_get_label(ctrl),
                           oldValue, newValue);
            g_object_set(ctrl, "value", newValue, NULL);
        }
    }   break;

    default:
        g_warn_if_reached();
        break;
    }

    entangle_control_set_dirty(ctrl, FALSE);
    ret = TRUE;
 cleanup:
    g_free(fullpath);
    return ret;
}

static gboolean do_save_controls(EntangleCamera *cam,
                                 const char *path,
                                 CameraWidget *widget,
                                 gboolean *dirty,
                                 GError **error)
{
    EntangleCameraPrivate *priv = cam->priv;
    CameraWidgetType type;
    EntangleControl *ctrl = NULL;
    const char *name;
    char *fullpath;
    gboolean ret = FALSE;

    if (gp_widget_get_type(widget, &type) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget type"));
        return FALSE;
    }

    if (gp_widget_get_name(widget, &name) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget name"));
        return FALSE;
    }

    fullpath = g_strdup_printf("%s/%s", path, name);
    ctrl = g_hash_table_lookup(priv->controlPaths, fullpath);
    if (!ctrl) {
        ret = TRUE;
        goto cleanup;
    }

    switch (type) {
        /* We treat both window and section as just groups */
    case GP_WIDGET_WINDOW:
    case GP_WIDGET_SECTION:
        for (int i = 0; i < gp_widget_count_children(widget); i++) {
            CameraWidget *child;
            if (gp_widget_get_child(widget, i, &child) == GP_OK)
                if (!do_save_controls(cam, fullpath, child, dirty, error))
                    goto cleanup;
        }
        break;

    case GP_WIDGET_BUTTON: {
    }   break;

        /* Unclear why these two are the same in libgphoto */
    case GP_WIDGET_RADIO:
    case GP_WIDGET_MENU:
        if (entangle_control_get_dirty(ctrl)) {
            char *value = NULL;
            g_object_get(ctrl, "value", &value, NULL);
            gp_widget_set_value(widget, value);
            g_free(value);
            *dirty = TRUE;
        }
        break;

    case GP_WIDGET_DATE:
        if (entangle_control_get_dirty(ctrl)) {
            int value = 0;
            g_object_get(ctrl, "value", &value, NULL);
            *dirty = TRUE;
        }
        break;

    case GP_WIDGET_RANGE:
        if (entangle_control_get_dirty(ctrl)) {
            float value = 0.0;
            g_object_get(ctrl, "value", &value, NULL);
            gp_widget_set_value(widget, &value);
            *dirty = TRUE;
        }
        break;

    case GP_WIDGET_TEXT:
        if (entangle_control_get_dirty(ctrl)) {
            char *value = NULL;
            g_object_get(ctrl, "value", &value, NULL);
            gp_widget_set_value(widget, value);
            g_free(value);
            *dirty = TRUE;
        }
        break;

    case GP_WIDGET_TOGGLE:
        if (entangle_control_get_dirty(ctrl)) {
            gboolean value = 0;
            int i;
            g_object_get(ctrl, "value", &value, NULL);
            i = value ? 1 : 0;
            gp_widget_set_value(widget, &i);
            *dirty = TRUE;
        }
        break;

    default:
        g_warn_if_reached();
        break;
    }

    ret = TRUE;
 cleanup:
    g_free(fullpath);
    return ret;
}


/**
 * entangle_camera_load_controls:
 * @cam: (transfer none): the camera
 *
 * Loads the configuration controls from the camera.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if the controls were loaded, FALSE on error
 */
gboolean entangle_camera_load_controls(EntangleCamera *cam,
                                       GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret = FALSE;
    int err;

    g_mutex_lock(priv->lock);

    if (priv->cam == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to load controls, camera is not connected"));
        goto cleanup;
    }

    entangle_camera_begin_job(cam);
    ENTANGLE_DEBUG("Loading control values");
    err = gp_camera_get_config(priv->cam, &priv->widgets, priv->ctx);
    if (err != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch camera control configuration: %s"), priv->lastError);
        goto endjob;
    }

    if (priv->controls == NULL) {
        ENTANGLE_DEBUG("Building controls");
        priv->controlPaths = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
        if (!(priv->controls = ENTANGLE_CONTROL_GROUP(do_build_controls(cam, "", priv->widgets, error)))) {
            g_hash_table_unref(priv->controlPaths);
            priv->controlPaths = NULL;
            goto endjob;
        }

        if (entangle_camera_find_widget(cam, "/main/actions/viewfinder") ||
            entangle_camera_find_widget(cam, "/main/actions/eosviewfinder")) {
            ENTANGLE_DEBUG("Found a viewfinder widget");
            priv->hasViewfinder = TRUE;
        } else {
            ENTANGLE_DEBUG("No viewfinder widget");
            priv->hasViewfinder = FALSE;
        }
    }

    ret = do_load_controls(cam, "", priv->widgets, error);

 endjob:
    entangle_camera_end_job(cam);

 cleanup:
    g_mutex_unlock(priv->lock);
    return ret;
}


static void entangle_camera_load_controls_helper(GTask *task,
                                                 gpointer object,
                                                 gpointer task_data G_GNUC_UNUSED,
                                                 GCancellable *cancellable G_GNUC_UNUSED)
{
    GError *error = NULL;

    if (!entangle_camera_load_controls(ENTANGLE_CAMERA(object), &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_load_controls_async:
 * @cam: (transfer none): the camera
 *
 * Loads the configuration controls from the camera.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_load_controls_finish
 * can be used to check the status
 */
void entangle_camera_load_controls_async(EntangleCamera *cam,
                                         GCancellable *cancellable,
                                         GAsyncReadyCallback callback,
                                         gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_task_run_in_thread(task,
                         entangle_camera_load_controls_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_load_controls_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_load_controls_async.
 *
 * Returns: TRUE if the controls were loaded, FALSE on error
 */
gboolean entangle_camera_load_controls_finish(EntangleCamera *cam,
                                              GAsyncResult *result,
                                              GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


/**
 * entangle_camera_save_controls:
 * @cam: (transfer none): the camera
 *
 * Saves the configuration controls to the camera.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if the controls were saved, FALSE on error
 */
gboolean entangle_camera_save_controls(EntangleCamera *cam,
                                       GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret = FALSE;
    gboolean dirty = FALSE;
    int err;

    g_mutex_lock(priv->lock);

    if (priv->cam == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to save controls, camera is not connected"));
        goto cleanup;
    }

    if (priv->controls == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to save controls, camera is not configurable"));
        goto cleanup;
    }

    entangle_camera_begin_job(cam);

    ENTANGLE_DEBUG("Saving controls for %p", cam);

    if (!do_save_controls(cam, "", priv->widgets,
                          &dirty, error))
        goto endjob;

    if (!dirty) {
        ENTANGLE_DEBUG("No widgets dirty, skipping");
        goto done;
    }

    if ((err = gp_camera_set_config(priv->cam, priv->widgets, priv->ctx)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to save camera control configuration: %s"),
                    priv->lastError);
        goto endjob;
    }

    if (!do_load_controls(cam, "", priv->widgets, error))
        goto endjob;

 done:
    ret = TRUE;

 endjob:
    entangle_camera_end_job(cam);

 cleanup:
    g_mutex_unlock(priv->lock);
    return ret;
}



static void entangle_camera_save_controls_helper(GTask *task,
                                                 gpointer object,
                                                 gpointer task_data G_GNUC_UNUSED,
                                                 GCancellable *cancellable G_GNUC_UNUSED)
{
    GError *error = NULL;

    if (!entangle_camera_save_controls(ENTANGLE_CAMERA(object), &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_save_controls_async:
 * @cam: (transfer none): the camera
 *
 * Saves the configuration controls to the camera.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_save_controls_finish
 * can be used to check the status
 */
void entangle_camera_save_controls_async(EntangleCamera *cam,
                                         GCancellable *cancellable,
                                         GAsyncReadyCallback callback,
                                         gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_task_run_in_thread(task,
                         entangle_camera_save_controls_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_save_controls_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_save_controls_async.
 *
 * Returns: TRUE if the controls were saved, FALSE on error
 */
gboolean entangle_camera_save_controls_finish(EntangleCamera *cam,
                                              GAsyncResult *result,
                                              GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


/**
 * entangle_camera_get_controls:
 * @cam: (transfer none): the camera
 *
 * Get the configuration controls associated with the camera.
 *
 * This can only be invoked when the camera is connected.
 *
 * Returns: (transfer full): the controls, or NULL
 */
EntangleControlGroup *entangle_camera_get_controls(EntangleCamera *cam, GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    EntangleCameraPrivate *priv = cam->priv;
    EntangleControlGroup *ret = NULL;

    g_mutex_lock(priv->lock);

    if (priv->cam == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available when camera is disconnected"));
        goto cleanup;
    }

    if (priv->controls == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available for this camera"));
        goto cleanup;
    }

    ret = priv->controls;
    g_object_ref(ret);

 cleanup:
    g_mutex_unlock(priv->lock);
    return ret;
}


/**
 * entangle_camera_set_viewfinder:
 * @cam: (transfer none): the camera
 * @enabled: TRUE to turn on the view finder
 *
 * If @enabled is TRUE, the view finder will be activated
 * allowing preview images to be captured. If @enabled is
 * FALSE, the view finder will be deactivated.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if the viewer finder state was changed, FALSE on error
 */
gboolean entangle_camera_set_viewfinder(EntangleCamera *cam,
                                        gboolean enabled,
                                        GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret = FALSE;
    CameraWidget *widget;
    CameraWidgetType type;
    int value;
    int err;

    g_mutex_lock(priv->lock);
    entangle_camera_begin_job(cam);

    ENTANGLE_DEBUG("Setting viewfinder state %d", enabled);

    if (priv->cam == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available when camera is disconnected"));
        goto cleanup;
    }

    if (priv->widgets == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available for this camera"));
        goto cleanup;
    }

    widget = entangle_camera_find_widget(cam,
                                         "/main/actions/viewfinder");
    if (!widget)
        widget = entangle_camera_find_widget(cam,
                                             "/main/actions/eosviewfinder");
    if (!widget) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Viewfinder control not available with this camera"));
        goto cleanup;
    }

    if ((err = gp_widget_get_type(widget,
                                  &type)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget type"));
        goto cleanup;
    }

    if (type != GP_WIDGET_TOGGLE) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Viewfinder control was not a toggle widget"));
        goto cleanup;
    }

    /*
     * Sigh. gphoto attempts to detect when the value has
     * changed and thus often doesn't apply the change in
     * value we request. We set the value twice, first to
     * the wrong value, then the right value. This ensures
     * gphoto always sees the value as changed.
     */
    value = enabled ? 0 : 1;
    if ((err = gp_widget_set_value(widget, &value)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Failed to set viewfinder state: %s %d"),
                    gp_port_result_as_string(err), err);
        goto cleanup;
    }
    value = enabled ? 1 : 0;
    if ((err = gp_widget_set_value(widget, &value)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Failed to set viewfinder state: %s %d"),
                    gp_port_result_as_string(err), err);
        goto cleanup;
    }

    if ((err = gp_camera_set_config(priv->cam,
                                    priv->widgets,
                                    priv->ctx)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to save camera control configuration: %s"),
                    priv->lastError);
        goto cleanup;
    }

    ret = TRUE;

 cleanup:
    entangle_camera_end_job(cam);
    g_mutex_unlock(priv->lock);
    return ret;
}


static void entangle_camera_set_viewfinder_helper(GTask *task,
                                                  gpointer object,
                                                  gpointer task_data,
                                                  GCancellable *cancellable G_GNUC_UNUSED)
{
    GError *error = NULL;
    gboolean enabled;

    enabled = GPOINTER_TO_INT(task_data) == 1 ? TRUE : FALSE;

    if (!entangle_camera_set_viewfinder(ENTANGLE_CAMERA(object),
                                        enabled,
                                        &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_set_viewfinder_async:
 * @cam: (transfer none): the camera
 * @enabled: TRUE to turn on the view finder
 *
 * If @enabled is TRUE, the view finder will be activated
 * allowing preview images to be captured. If @enabled is
 * FALSE, the view finder will be deactivated.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_set_viewfinder_finish
 * can be used to check the status
 */
void entangle_camera_set_viewfinder_async(EntangleCamera *cam,
                                          gboolean enabled,
                                          GCancellable *cancellable,
                                          GAsyncReadyCallback callback,
                                          gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_task_set_task_data(task, GINT_TO_POINTER(enabled ? 1 : 0), NULL);

    g_task_run_in_thread(task,
                         entangle_camera_set_viewfinder_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_set_viewfinder_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_set_viewfinder_async.
 *
 * Returns: TRUE if the viewfinder state was changed, FALSE on error
 */
gboolean entangle_camera_set_viewfinder_finish(EntangleCamera *cam,
                                               GAsyncResult *result,
                                               GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


/**
 * entangle_camera_autofocus:
 * @cam: (transfer none): the camera
 *
 * Trigger the autofocus mechanism on the camera, waiting
 * until focus is achieved or fails.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if autofocus was achieved, FALSE on error
 */
gboolean entangle_camera_autofocus(EntangleCamera *cam,
                                   GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret = FALSE;
    CameraWidget *widget;
    CameraWidgetType type;
    int value;
    int err;

    g_mutex_lock(priv->lock);
    entangle_camera_begin_job(cam);

    ENTANGLE_DEBUG("Setting autofocus");

    if (priv->cam == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available when camera is disconnected"));
        goto cleanup;
    }

    if (priv->widgets == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available for this camera"));
        goto cleanup;
    }

    widget = entangle_camera_find_widget(cam,
                                         "/main/actions/autofocusdrive");
    if (!widget) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Autofocus control not available with this camera"));
        goto cleanup;
    }

    if ((err = gp_widget_get_type(widget,
                                  &type)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget type"));
        goto cleanup;
    }

    if (type != GP_WIDGET_TOGGLE) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Autofocus control was not a toggle widget"));
        goto cleanup;
    }

    value = 0;
    if ((err = gp_widget_set_value(widget, &value)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Failed to set autofocus state: %s %d"),
                    gp_port_result_as_string(err), err);
        goto cleanup;
    }

    value = 1;
    if ((err = gp_widget_set_value(widget, &value)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Failed to set autofocus state: %s %d"),
                    gp_port_result_as_string(err), err);
        goto cleanup;
    }

    if ((err = gp_camera_set_config(priv->cam,
                                    priv->widgets,
                                    priv->ctx)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to save camera control configuration: %s"),
                    priv->lastError);
        goto cleanup;
    }

    ret = TRUE;

 cleanup:
    entangle_camera_end_job(cam);
    g_mutex_unlock(priv->lock);
    return ret;
}


static void entangle_camera_autofocus_helper(GTask *task,
                                             gpointer object,
                                             gpointer task_data G_GNUC_UNUSED,
                                             GCancellable *cancellable G_GNUC_UNUSED)
{
    GError *error = NULL;

    if (!entangle_camera_autofocus(ENTANGLE_CAMERA(object),
                                   &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_autofocus_async:
 * @cam: (transfer none): the camera
 *
 * Trigger the autofocus mechanism on the camera, waiting
 * until focus is achieved or fails.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_autofocus_finish
 * can be used to check the status
 */
void entangle_camera_autofocus_async(EntangleCamera *cam,
                                     GCancellable *cancellable,
                                     GAsyncReadyCallback callback,
                                     gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_task_run_in_thread(task,
                         entangle_camera_autofocus_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_autofocus_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_autofocus_async.
 *
 * Returns: TRUE if autofocus was performed, FALSE on error
 */
gboolean entangle_camera_autofocus_finish(EntangleCamera *cam,
                                          GAsyncResult *result,
                                          GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


/**
 * entangle_camera_manualfocus:
 * @cam: (transfer none): the camera
 * @step: how much to change focus by
 *
 * Trigger the focus mechanism on the camera, to move
 * by @step.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if autofocus was achieved, FALSE on error
 */
gboolean entangle_camera_manualfocus(EntangleCamera *cam,
                                     EntangleCameraManualFocusStep step,
                                     GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret = FALSE;
    CameraWidget *widget;
    CameraWidgetType type;
    int err;

    g_mutex_lock(priv->lock);
    entangle_camera_begin_job(cam);

    ENTANGLE_DEBUG("Setting manualfocus %d", (int)step);

    if (priv->cam == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available when camera is disconnected"));
        goto cleanup;
    }

    if (priv->widgets == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available for this camera"));
        goto cleanup;
    }

    widget = entangle_camera_find_widget(cam,
                                         "/main/actions/manualfocusdrive");
    if (!widget) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Manual focus control not available with this camera"));
        goto cleanup;
    }

    if ((err = gp_widget_get_type(widget,
                                  &type)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget type"));
        goto cleanup;
    }

    if (type != GP_WIDGET_RANGE &&
        type != GP_WIDGET_RADIO) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Manual focus control was not a range or radio widget"));
        goto cleanup;
    }

    if (type == GP_WIDGET_RANGE) {
        /* Nikon */
        float values[] = {
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_IN_COARSE] = 512,
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_IN_MEDIUM] = 64,
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_IN_FINE] = 8,
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_OUT_COARSE] = -512,
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_OUT_MEDIUM] = -64,
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_OUT_FINE] = -8,
        };

        float value = values[step];
        ENTANGLE_DEBUG("Setting manualfocus range %d", (int)value);
        if ((err = gp_widget_set_value(widget, &value)) != GP_OK) {
            g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                        _("Failed to set manual focus state: %s %d"),
                        gp_port_result_as_string(err), err);
            goto cleanup;
        }
    } else {
        /* Canon */
        int idx[] = {
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_IN_COARSE] = 2,
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_IN_MEDIUM] = 1,
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_IN_FINE] = 0,
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_OUT_COARSE] = 6,
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_OUT_MEDIUM] = 5,
            [ENTANGLE_CAMERA_MANUAL_FOCUS_STEP_OUT_FINE] = 4,
        };
        const gchar *value;
        if ((err = gp_widget_get_choice(widget, idx[step], &value)) != GP_OK) {
            g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                        _("Failed to read manual focus choice %d: %s %d"),
                        step, gp_port_result_as_string(err), err);
            goto cleanup;
        }
        ENTANGLE_DEBUG("Setting manualfocus radio %s", value);
        if ((err = gp_widget_set_value(widget, value)) != GP_OK) {
            g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                        _("Failed to set manual focus state: %s %d"),
                        gp_port_result_as_string(err), err);
            goto cleanup;
        }
    }

    if ((err = gp_camera_set_config(priv->cam,
                                    priv->widgets,
                                    priv->ctx)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to save camera control configuration: %s"),
                    priv->lastError);
        goto cleanup;
    }

    if (type == GP_WIDGET_RANGE) {
        float value = 0;
        if ((err = gp_widget_set_value(widget, &value)) != GP_OK) {
            g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                        _("Failed to set manual focus state: %s %d"),
                        gp_port_result_as_string(err), err);
            goto cleanup;
        }
    } else {
        const gchar *value;
        /* Reset drive to "None" == 3 */
        if ((err = gp_widget_get_choice(widget, 3, &value)) != GP_OK) {
            g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                        _("Failed to read manual focus choice %d: %s %d"),
                        step, gp_port_result_as_string(err), err);
            goto cleanup;
        }
        ENTANGLE_DEBUG("Setting manualfocus radio %s", value);
        if ((err = gp_widget_set_value(widget, value)) != GP_OK) {
            g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                        _("Failed to set manual focus state: %s %d"),
                        gp_port_result_as_string(err), err);
            goto cleanup;
        }
    }

    ret = TRUE;

 cleanup:
    entangle_camera_end_job(cam);
    g_mutex_unlock(priv->lock);
    return ret;
}


static void entangle_camera_manualfocus_helper(GTask *task,
                                               gpointer object,
                                               gpointer task_data,
                                               GCancellable *cancellable G_GNUC_UNUSED)
{
    GError *error = NULL;

    if (!entangle_camera_manualfocus(ENTANGLE_CAMERA(object),
                                     GPOINTER_TO_INT(task_data),
                                     &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_manualfocus_async:
 * @cam: (transfer none): the camera
 * @step: how much to change focus by
 *
 * Trigger the focus mechanism on the camera, to move
 * by @step.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_manualfocus_finish
 * can be used to check the status
 */
void entangle_camera_manualfocus_async(EntangleCamera *cam,
                                       EntangleCameraManualFocusStep step,
                                       GCancellable *cancellable,
                                       GAsyncReadyCallback callback,
                                       gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    g_task_set_task_data(task, GINT_TO_POINTER(step), NULL);

    g_task_run_in_thread(task,
                         entangle_camera_manualfocus_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_manualfocus_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_manualfocus_async.
 *
 * Returns: TRUE if manual focus was performed, FALSE on error
 */
gboolean entangle_camera_manualfocus_finish(EntangleCamera *cam,
                                            GAsyncResult *result,
                                            GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}



/**
 * entangle_camera_set_clock:
 * @cam: (transfer none): the camera
 * @epochsecs: new time in seconds since the epoch
 *
 * Update the camera clock to be @epochsecs seconds since
 * the epoch.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if the clock was changed, FALSE on error
 */
gboolean entangle_camera_set_clock(EntangleCamera *cam,
                                   gint64 epochsecs,
                                   GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret = FALSE;
    CameraWidget *widget;
    CameraWidgetType type;
    time_t value;
    int err;

    g_mutex_lock(priv->lock);
    entangle_camera_begin_job(cam);

    ENTANGLE_DEBUG("Setting clock to %lld", (long long)epochsecs);

    if (priv->cam == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available when camera is disconnected"));
        goto cleanup;
    }

    if (priv->widgets == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available for this camera"));
        goto cleanup;
    }

    widget = entangle_camera_find_widget(cam,
                                         "/main/settings/datetime");
    if (!widget) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Time setting not available with this camera"));
        goto cleanup;
    }

    if ((err = gp_widget_get_type(widget,
                                  &type)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget type"));
        goto cleanup;
    }

    if (type != GP_WIDGET_DATE) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Time setting was not a date widget"));
        goto cleanup;
    }

    value = epochsecs;
    if ((err = gp_widget_set_value(widget, &value)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Failed to set time state: %s %d"),
                    gp_port_result_as_string(err), err);
        goto cleanup;
    }

    if ((err = gp_camera_set_config(priv->cam,
                                    priv->widgets,
                                    priv->ctx)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to save camera control configuration: %s"),
                    priv->lastError);
        goto cleanup;
    }

    ret = TRUE;

 cleanup:
    entangle_camera_end_job(cam);
    g_mutex_unlock(priv->lock);
    return ret;
}


static void entangle_camera_set_clock_helper(GTask *task,
                                             gpointer object,
                                             gpointer task_data,
                                             GCancellable *cancellable G_GNUC_UNUSED)
{
    GError *error = NULL;
    guint64 *epochsecsptr = task_data;

    if (!entangle_camera_set_clock(ENTANGLE_CAMERA(object),
                                   *epochsecsptr,
                                   &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_set_clock_async:
 * @cam: (transfer none): the camera
 * @epochsecs: new time in seconds since the epoch
 *
 * Update the camera clock to be @epochsecs seconds since
 * the epoch.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_set_clock_finish
 * can be used to check the status
 */
void entangle_camera_set_clock_async(EntangleCamera *cam,
                                     gint64 epochsecs,
                                     GCancellable *cancellable,
                                     GAsyncReadyCallback callback,
                                     gpointer user_data)
{
    guint64 *epochsecsptr;
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    epochsecsptr = g_new0(guint64, 1);
    *epochsecsptr = epochsecs;

    g_task_set_task_data(task, epochsecsptr, g_free);

    g_task_run_in_thread(task,
                         entangle_camera_set_clock_helper);
    g_object_unref(task);
}


/**
 * entangle_camera_set_clock_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_set_clock_async.
 *
 * Returns: TRUE if the clock was changed, FALSE on error
 */
gboolean entangle_camera_set_clock_finish(EntangleCamera *cam,
                                          GAsyncResult *result,
                                          GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


/**
 * entangle_camera_set_capture_target:
 * @cam: (transfer none): the camera
 * @target: the capture target
 *
 * Set the destination for storing captured images
 * to @target.
 *
 * This can only be invoked when the camera is connected.
 *
 * This block execution of the caller until completion.
 *
 * Returns: TRUE if the capture target was changed, FALSE on error
 */
gboolean entangle_camera_set_capture_target(EntangleCamera *cam,
                                            EntangleCameraCaptureTarget target,
                                            GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret = FALSE;
    CameraWidget *widget;
    CameraWidgetType type;
    const gchar *value;
    GEnumValue *evalue;
    GEnumClass *eclass = NULL;
    int err;

    g_mutex_lock(priv->lock);
    entangle_camera_begin_job(cam);

    ENTANGLE_DEBUG("Setting clock to %d", target);

    if (priv->cam == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available when camera is disconnected"));
        goto cleanup;
    }

    if (priv->widgets == NULL) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Controls not available for this camera"));
        goto cleanup;
    }

    widget = entangle_camera_find_widget(cam,
                                         "/main/settings/capturetarget");
    if (!widget) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Capture target setting not available with this camera"));
        goto cleanup;
    }

    if ((err = gp_widget_get_type(widget,
                                  &type)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to fetch widget type"));
        goto cleanup;
    }

    if (type != GP_WIDGET_MENU) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Time setting was not a choice widget"));
        goto cleanup;
    }

    eclass = g_type_class_ref(ENTANGLE_TYPE_CAMERA_CAPTURE_TARGET);
    evalue = g_enum_get_value(eclass, target);
    value = evalue->value_nick;
    if ((err = gp_widget_set_value(widget, value)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Failed to set capture target: %s %d"),
                    gp_port_result_as_string(err), err);
        goto cleanup;
    }

    if ((err = gp_camera_set_config(priv->cam,
                                    priv->widgets,
                                    priv->ctx)) != GP_OK) {
        g_set_error(error, ENTANGLE_CAMERA_ERROR, 0,
                    _("Unable to save camera control configuration: %s"),
                    priv->lastError);
        goto cleanup;
    }

    ret = TRUE;

 cleanup:
    if (eclass)
        g_type_class_unref(eclass);
    entangle_camera_end_job(cam);
    g_mutex_unlock(priv->lock);
    return ret;
}


static void entangle_camera_set_capture_target_helper(GTask *task,
                                                      gpointer object,
                                                      gpointer task_data,
                                                      GCancellable *cancellable G_GNUC_UNUSED)
{
    GError *error = NULL;
    EntangleCameraCaptureTarget *targetptr = task_data;

    if (!entangle_camera_set_capture_target(ENTANGLE_CAMERA(object),
                                            *targetptr,
                                            &error)) {
        g_task_return_error(task, error);
    } else {
        g_task_return_boolean(task, TRUE);
    }
}


/**
 * entangle_camera_set_capture_target_async:
 * @cam: (transfer none): the camera
 * @target: the capture target
 *
 * Set the destination for storing captured images
 * to @target.
 *
 * This can only be invoked when the camera is connected.
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_set_clock_finish
 * can be used to check the status
 */
void entangle_camera_set_capture_target_async(EntangleCamera *cam,
                                              EntangleCameraCaptureTarget target,
                                              GCancellable *cancellable,
                                              GAsyncReadyCallback callback,
                                              gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    EntangleCameraCaptureTarget *targetptr;
    GTask *task = g_task_new(cam, cancellable, callback, user_data);

    targetptr = g_new0(EntangleCameraCaptureTarget, 1);
    *targetptr = target;

    g_task_set_task_data(task, targetptr, g_free);

    g_task_run_in_thread(task,
                         entangle_camera_set_capture_target_helper);
    g_object_unref(task);
}



/**
 * entangle_camera_capture_target_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_capture_target_async.
 *
 * Returns: TRUE if the capture target was changed, FALSE on error
 */
gboolean entangle_camera_set_capture_target_finish(EntangleCamera *cam,
                                                   GAsyncResult *result,
                                                   GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}


/**
 * entangle_camera_get_has_capture:
 * @cam: (transfer none): the camera
 *
 * Check if the camera supports images capture
 *
 * Returns: TRUE if the camera supports image capture, FALSE otherwise
 */
gboolean entangle_camera_get_has_capture(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret;

    g_mutex_lock(priv->lock);
    ret = priv->hasCapture;
    g_mutex_unlock(priv->lock);

    return ret;
}


/**
 * entangle_camera_get_has_preview:
 * @cam: (transfer none): the camera
 *
 * Check if the camera supports images preview
 *
 * Returns: TRUE if the camera supports image preview, FALSE otherwise
 */
gboolean entangle_camera_get_has_preview(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret;

    g_mutex_lock(priv->lock);
    ret = priv->hasPreview;
    g_mutex_unlock(priv->lock);

    return ret;
}


/**
 * entangle_camera_get_has_settings:
 * @cam: (transfer none): the camera
 *
 * Check if the camera supports configuration settings
 *
 * Returns: TRUE if the camera supports configuration settings, FALSE otherwise
 */
gboolean entangle_camera_get_has_settings(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret;

    g_mutex_lock(priv->lock);
    ret = priv->hasSettings;
    g_mutex_unlock(priv->lock);

    return ret;
}


/**
 * entangle_camera_get_has_viewfinder:
 * @cam: (transfer none): the camera
 *
 * Check if the camera supports view finder control
 *
 * Returns: TRUE if the camera supports view finder control, FALSE otherwise
 */
gboolean entangle_camera_get_has_viewfinder(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    EntangleCameraPrivate *priv = cam->priv;
    gboolean ret;

    g_mutex_lock(priv->lock);
    ret = priv->hasViewfinder;
    g_mutex_unlock(priv->lock);

    return ret;
}


/**
 * entangle_camera_set_progress:
 * @cam: (transfer none): the camera
 * @prog: (transfer none)(allow-none): the progress instance
 *
 * Set the object instance to receive operation progress
 * notifications
 */
void entangle_camera_set_progress(EntangleCamera *cam, EntangleProgress *prog)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    EntangleCameraPrivate *priv = cam->priv;

    g_mutex_lock(priv->lock);
    if (priv->progress)
        g_object_unref(priv->progress);
    priv->progress = prog;
    if (priv->progress)
        g_object_ref(priv->progress);
    g_mutex_unlock(priv->lock);
}


/**
 * entangle_camera_get_progress:
 * @cam: (transfer none): the camera
 *
 * Get the object instance that is receiving operation
 * progress notifications
 *
 * Returns: (transfer full): the progress object
 */
EntangleProgress *entangle_camera_get_progress(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), NULL);

    EntangleCameraPrivate *priv = cam->priv;
    EntangleProgress *ret;

    g_mutex_unlock(priv->lock);
    ret = priv->progress;
    g_object_ref(ret);
    g_mutex_unlock(priv->lock);

    return ret;
}


static GMount *entangle_device_manager_find_mount(EntangleCamera *cam,
                                                  GVolumeMonitor *monitor)
{
    EntangleCameraPrivate *priv = cam->priv;
    gchar *uri1;
    gchar *uri2;
    GList *mounts;
    GList *tmp;
    GMount *ret = NULL;
    gchar *host, *eschost;

    g_mutex_lock(priv->lock);
    uri1 = g_strdup_printf("gphoto2://[%s]/", priv->port);
    host = g_strdup_printf("[%s]", priv->port);
    eschost = g_uri_escape_string(host, ",", TRUE);
    uri2 = g_strdup_printf("gphoto2://%s/", eschost);
    g_mutex_unlock(priv->lock);

    mounts = g_volume_monitor_get_mounts(monitor);
    tmp = mounts;
    while (tmp) {
        GMount *mount = tmp->data;
        GFile *root = g_mount_get_root(mount);
        gchar *thisuri = g_file_get_uri(root);

        if (g_str_equal(uri1, thisuri) ||
            g_str_equal(uri2, thisuri))
            ret = mount;
        else
            g_object_unref(mount);

        tmp = tmp->next;
    }
    g_list_free(mounts);

    g_free(uri1);
    g_free(uri2);
    g_free(host);
    g_free(eschost);

    return ret;
}



/**
 * entangle_camera_is_mounted:
 * @cam: (transfer none): the camera
 *
 * Check whether the camera is mounted as a virtual filesystem,
 * which would prevent connecting it to.
 *
 * Returns: TRUE if the camera is mounted, FALSE otherwise
 */
gboolean entangle_camera_is_mounted(EntangleCamera *cam)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);
    /*
     * For some reason if we ever unref monitor, we get a 100%
     * CPU burn loop in a bg thread from DBus messages. So we
     * have made this static for now
     */
    static GVolumeMonitor *monitor;

    GMount *mount;
    gboolean ret;
    if (!monitor)
        monitor = g_volume_monitor_get();
    mount = entangle_device_manager_find_mount(cam, monitor);

    if (mount) {
        g_object_unref(mount);
        ret = TRUE;
    } else {
        ret = FALSE;
    }

    return ret;
}

struct UnmountData {
    GVolumeMonitor *monitor;
    GMount *mount;
    GAsyncReadyCallback callback;
    gpointer user_data;
};

static void entangle_camera_unmount_cleanup(GObject *object,
                                            GAsyncResult *result,
                                            gpointer user_data)
{
    struct UnmountData *data = user_data;

    data->callback(object, result, data->user_data);

    g_object_unref(data->monitor);
    if (data->mount)
        g_object_unref(data->mount);
    g_free(data);
}

static void entangle_camera_unmount_complete(GObject *object,
                                             GAsyncResult *result,
                                             gpointer user_data)
{
    GTask *task = G_TASK(user_data);
    GError *err = NULL;
    GMount *mount = G_MOUNT(object);

    g_mount_unmount_with_operation_finish(mount,
                                          result,
                                          &err);

    if (err)
        g_task_return_error(task, err);
    else
        g_task_return_boolean(task, TRUE);
    g_object_unref(task);
}


/**
 * entangle_camera_unmount_async:
 * @cam: (transfer none): the camera
 *
 * Unmount the camera virtual filesystem, allowing it to be
 * connected to
 *
 * This will execute in the background, and invoke @callback
 * when complete, whereupon entangle_camera_unmount_finish
 * can be used to check the status
 */
void entangle_camera_unmount_async(EntangleCamera *cam,
                                   GCancellable *cancellable,
                                   GAsyncReadyCallback callback,
                                   gpointer user_data)
{
    g_return_if_fail(ENTANGLE_IS_CAMERA(cam));

    struct UnmountData *data = g_new0(struct UnmountData, 1);

    data->monitor = g_volume_monitor_get();
    data->mount = entangle_device_manager_find_mount(cam, data->monitor);
    data->callback = callback;
    data->user_data = user_data;

    GTask *task = g_task_new(cam, cancellable,
                             entangle_camera_unmount_cleanup,
                             data);

    if (data->mount) {
        g_mount_unmount_with_operation(data->mount,
                                       0, NULL,
                                       cancellable,
                                       entangle_camera_unmount_complete,
                                       task);
    } else {
        g_task_return_boolean(task, TRUE);
        g_object_unref(task);
    }
}


/**
 * entangle_camera_unmount_finish:
 * @cam: (transfer none): the camera
 *
 * Check the completion status of a previous call to
 * entangle_camera_unmount_async.
 *
 * Returns: TRUE if the camera was unmounted, FALSE on error
 */
gboolean entangle_camera_unmount_finish(EntangleCamera *cam,
                                        GAsyncResult *result,
                                        GError **error)
{
    g_return_val_if_fail(ENTANGLE_IS_CAMERA(cam), FALSE);

    return g_task_propagate_boolean(G_TASK(result), error);
}

/*
 * Local variables:
 *  c-indent-level: 4
 *  c-basic-offset: 4
 *  indent-tabs-mode: nil
 *  tab-width: 8
 * End:
 */
