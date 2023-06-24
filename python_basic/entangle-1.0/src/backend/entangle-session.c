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
#include <gio/gio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "entangle-debug.h"
#include "entangle-session.h"
#include "entangle-image.h"
#include "entangle-video.h"

#define ENTANGLE_SESSION_GET_PRIVATE(obj)                                   \
    (G_TYPE_INSTANCE_GET_PRIVATE((obj), ENTANGLE_TYPE_SESSION, EntangleSessionPrivate))

struct _EntangleSessionPrivate {
    char *directory;
    char *filenamePattern;
    gboolean recalculateDigit;
    int nextFilenameDigit;

    char *lastFilePrefixSrc;
    char *lastFilePrefixDst;

    GList *files;
};

G_DEFINE_TYPE(EntangleSession, entangle_session, G_TYPE_OBJECT);

enum {
    PROP_0,
    PROP_DIRECTORY,
    PROP_FILENAME_PATTERN,
};

static void entangle_session_get_property(GObject *object,
                                          guint prop_id,
                                          GValue *value,
                                          GParamSpec *pspec)
{
    EntangleSession *picker = ENTANGLE_SESSION(object);
    EntangleSessionPrivate *priv = picker->priv;

    switch (prop_id) {
    case PROP_DIRECTORY:
        g_value_set_string(value, priv->directory);
        break;

    case PROP_FILENAME_PATTERN:
        g_value_set_string(value, priv->filenamePattern);
        break;

    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
    }
}

static void entangle_session_set_property(GObject *object,
                                          guint prop_id,
                                          const GValue *value,
                                          GParamSpec *pspec)
{
    EntangleSession *picker = ENTANGLE_SESSION(object);
    EntangleSessionPrivate *priv = picker->priv;

    switch (prop_id) {
    case PROP_DIRECTORY:
        g_free(priv->directory);
        priv->directory = g_value_dup_string(value);
        g_mkdir_with_parents(priv->directory, 0777);
        break;

    case PROP_FILENAME_PATTERN:
        g_free(priv->filenamePattern);
        priv->filenamePattern = g_value_dup_string(value);
        priv->recalculateDigit = TRUE;
        break;

    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
    }
}


static void do_media_unref(gpointer object,
                           gpointer opaque G_GNUC_UNUSED)
{
    EntangleMedia *media = object;

    g_object_unref(media);
}

static void entangle_session_finalize(GObject *object)
{
    EntangleSession *session = ENTANGLE_SESSION(object);
    EntangleSessionPrivate *priv = session->priv;

    ENTANGLE_DEBUG("Finalize session %p", object);

    if (priv->files) {
        g_list_foreach(priv->files, do_media_unref, NULL);
        g_list_free(priv->files);
    }

    g_free(priv->lastFilePrefixSrc);
    g_free(priv->lastFilePrefixDst);
    g_free(priv->filenamePattern);
    g_free(priv->directory);

    G_OBJECT_CLASS(entangle_session_parent_class)->finalize(object);
}


static void entangle_session_class_init(EntangleSessionClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS(klass);

    object_class->finalize = entangle_session_finalize;
    object_class->get_property = entangle_session_get_property;
    object_class->set_property = entangle_session_set_property;

    g_signal_new("session-media-added",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__OBJECT,
                 G_TYPE_NONE,
                 1,
                 ENTANGLE_TYPE_MEDIA);

    g_signal_new("session-media-removed",
                 G_TYPE_FROM_CLASS(klass),
                 G_SIGNAL_RUN_FIRST,
                 0, NULL, NULL,
                 g_cclosure_marshal_VOID__OBJECT,
                 G_TYPE_NONE,
                 1,
                 ENTANGLE_TYPE_MEDIA);

    g_object_class_install_property(object_class,
                                    PROP_DIRECTORY,
                                    g_param_spec_string("directory",
                                                        "Session directory",
                                                        "Full path to session file",
                                                        NULL,
                                                        G_PARAM_READWRITE |
                                                        G_PARAM_CONSTRUCT_ONLY |
                                                        G_PARAM_STATIC_NAME |
                                                        G_PARAM_STATIC_NICK |
                                                        G_PARAM_STATIC_BLURB));

    g_object_class_install_property(object_class,
                                    PROP_FILENAME_PATTERN,
                                    g_param_spec_string("filename-pattern",
                                                        "Filename patern",
                                                        "Pattern for creating new filenames",
                                                        NULL,
                                                        G_PARAM_READWRITE |
                                                        G_PARAM_CONSTRUCT_ONLY |
                                                        G_PARAM_STATIC_NAME |
                                                        G_PARAM_STATIC_NICK |
                                                        G_PARAM_STATIC_BLURB));

    g_type_class_add_private(klass, sizeof(EntangleSessionPrivate));
}


/**
 * entangle_session_new:
 * @directory: the directory associated witht session
 * @filenamePattern: the filename generator pattern
 *
 * Create a new sesssion tracking media files present in
 * @directory. The @filenamePattern is used to generate
 * filenames for newly created files
 *
 * Returns: (transfer full): the new session
 */
EntangleSession *entangle_session_new(const char *directory,
                                      const char *filenamePattern)
{
    return ENTANGLE_SESSION(g_object_new(ENTANGLE_TYPE_SESSION,
                                         "directory", directory,
                                         "filename-pattern", filenamePattern,
                                         NULL));
}


static void entangle_session_init(EntangleSession *session)
{
    EntangleSessionPrivate *priv;

    priv = session->priv = ENTANGLE_SESSION_GET_PRIVATE(session);

    priv->recalculateDigit = TRUE;
}


/**
 * entangle_session_directory:
 * @session: (transfer none): the session instance
 *
 * Get the directory associated with the session
 *
 * Returns: (transfer none): the session directory
 */
const char *entangle_session_directory(EntangleSession *session)
{
    g_return_val_if_fail(ENTANGLE_IS_SESSION(session), NULL);

    EntangleSessionPrivate *priv = session->priv;

    return priv->directory;
}


/**
 * entangle_session_filename_pattern:
 * @session: (transfer none): the session instance
 *
 * Get the filename generator pattern
 *
 * Returns: (transfer none): the filename pattern
 */
const char *entangle_session_filename_pattern(EntangleSession *session)
{
    g_return_val_if_fail(ENTANGLE_IS_SESSION(session), NULL);

    EntangleSessionPrivate *priv = session->priv;

    return priv->filenamePattern;
}


static gint entangle_session_next_digit(EntangleSession *session)
{
    EntangleSessionPrivate *priv = session->priv;
    gint maxDigit = -1;
    GList *files = priv->files;
    const gchar *template = strchr(priv->filenamePattern, 'X');
    gchar *prefix = g_strndup(priv->filenamePattern, (template - priv->filenamePattern));
    gint prefixlen = strlen(prefix);
    gsize templatelen = 0;
    const gchar *postfix;
    gsize postfixlen;

    while (*template == 'X') {
        templatelen++;
        template++;
    }

    postfix = template;
    postfixlen = strlen(postfix);

    ENTANGLE_DEBUG("Template '%s' with prefixlen %d, %zu digits and postfix %zu",
                   priv->filenamePattern, prefixlen, templatelen, postfixlen);

    while (files) {
        EntangleMedia *media = files->data;
        const gchar *name = entangle_media_get_filename(media);
        gsize used = 0;
        gint digit = 0;

        if (!g_str_has_prefix(name, priv->directory)) {
            ENTANGLE_DEBUG("File %s does not match directory",
                           entangle_media_get_filename(media));
            goto next;
        }
        name += strlen(priv->directory);
        while (*name == '/')
            name++;

        /* Ignore files not matching the template prefix */
        if (!g_str_has_prefix(name, prefix)) {
            ENTANGLE_DEBUG("File %s does not match prefix",
                           entangle_media_get_filename(media));
            goto next;
        }

        name += prefixlen;

        /* Skip over filename matching digits */
        while (used < templatelen && g_ascii_isdigit(*name)) {
            digit *= 10;
            digit += *name - '0';
            name++;
            used++;
        }

        /* See if unexpectedly got a non-digit before end of template */
        if (used < templatelen) {
            ENTANGLE_DEBUG("File %s has too few digits",
                           entangle_media_get_filename(media));
            goto next;
        }

        if (!g_str_has_prefix(name, postfix)) {
            ENTANGLE_DEBUG("File %s does not match postfix",
                           entangle_media_get_filename(media));
            goto next;
        }

        name += postfixlen;

        /* Verify there is a file extension following the digits */
        if (*name != '.') {
            ENTANGLE_DEBUG("File %s has trailing data",
                           entangle_media_get_filename(media));
            goto next;
        }

        if (digit > maxDigit)
            maxDigit = digit;
        ENTANGLE_DEBUG("File %s matches maxDigit is %d",
                       entangle_media_get_filename(media), maxDigit);

    next:
        files = files->next;
    }

    g_free(prefix);

    return maxDigit + 1;
}


static char *entangle_session_next_file_prefix(EntangleSession *session)
{
    EntangleSessionPrivate *priv = session->priv;
    const char *template = strchr(priv->filenamePattern, 'X');
    const char *postfix;
    char *prefix;
    char *format;
    char *filename;
    int ndigits;

    ENTANGLE_DEBUG("NEXT FILENAME '%s'", template);

    if (!template)
        return NULL;

    if (priv->recalculateDigit) {
        priv->nextFilenameDigit = entangle_session_next_digit(session);
        priv->recalculateDigit = FALSE;
    }

    postfix = template;
    while (*postfix == 'X')
        postfix++;

    prefix = g_strndup(priv->filenamePattern,
                       template - priv->filenamePattern);

    ndigits = postfix - template;

    format = g_strdup_printf("%%s%%0%dd%%s", ndigits);

    ENTANGLE_DEBUG("Format '%s' prefix='%s' postfix='%s' ndigits=%d nextDigits=%d",
                   format, prefix, postfix, ndigits, priv->nextFilenameDigit);

    filename = g_strdup_printf(format,
                               prefix,
                               priv->nextFilenameDigit,
                               postfix);

    priv->nextFilenameDigit++;

    g_free(prefix);
    g_free(format);

    return filename;
}


/**
 * entangle_session_next_filename:
 * @session: (transfer none): the session instance
 * @file: (transfer none): the file to obtain a filename for
 *
 * Generate a new unique filename for @file, taking into
 * account its file extension and any previously generated
 * filename.
 *
 * Returns: (transfer full): the new filename
 */
char *entangle_session_next_filename(EntangleSession *session,
                                     EntangleCameraFile *file)
{
    g_return_val_if_fail(ENTANGLE_IS_SESSION(session), NULL);

    EntangleSessionPrivate *priv = session->priv;
    const char *srcname = entangle_camera_file_get_name(file);
    char *dstname = NULL;
    char *ext = NULL;
    char *srcprefix = NULL;

    ENTANGLE_DEBUG("Next filename %s against (%s, %s)",
                   srcname,
                   priv->lastFilePrefixSrc ? priv->lastFilePrefixSrc : "",
                   priv->lastFilePrefixDst ? priv->lastFilePrefixDst : "");

    if (srcname) {
        const char *offset = strrchr(srcname, '.');
        if (!offset) {
            srcprefix = g_strdup(srcname);
        } else {
            srcprefix = g_strndup(srcname, (offset - srcname));
            ext = g_ascii_strdown(offset + 1, -1);
        }
    }

    if (srcprefix &&
        priv->lastFilePrefixSrc &&
        priv->lastFilePrefixDst &&
        g_str_equal(priv->lastFilePrefixSrc, srcprefix)) {
    } else {
        g_free(priv->lastFilePrefixSrc);
        g_free(priv->lastFilePrefixDst);
        priv->lastFilePrefixSrc = srcprefix;
        priv->lastFilePrefixDst = entangle_session_next_file_prefix(session);
    }

    if (priv->lastFilePrefixDst)
        dstname = g_strdup_printf("%s/%s.%s",
                                  priv->directory,
                                  priv->lastFilePrefixDst,
                                  ext ? ext : "jpeg");
    g_free(ext);

    ENTANGLE_DEBUG("Built '%s'", dstname);

    if (access(dstname, R_OK) == 0 || errno != ENOENT) {
        ENTANGLE_DEBUG("Filename %s unexpectedly exists", dstname);
        g_free(dstname);
        dstname = NULL;
    }

    return dstname;
}


static gint entangle_session_compare_media(gconstpointer a,
                                           gconstpointer b)
{
    EntangleMedia *mediaa = (EntangleMedia *)a;
    EntangleMedia *mediab = (EntangleMedia *)b;

    return entangle_media_get_last_modified(mediaa) -
        entangle_media_get_last_modified(mediab);
}

/**
 * entangle_session_add_media:
 * @session: (transfer none): the session instance
 * @media: (transfer none): the media file to add to the session
 *
 * Add @media to the @session
 */
void entangle_session_add_media(EntangleSession *session, EntangleMedia *media)
{
    g_return_if_fail(ENTANGLE_IS_SESSION(session));
    g_return_if_fail(ENTANGLE_IS_MEDIA(media));

    EntangleSessionPrivate *priv = session->priv;

    g_object_ref(media);

    priv->files = g_list_insert_sorted(priv->files,
                                        media,
                                        entangle_session_compare_media);

    g_signal_emit_by_name(session, "session-media-added", media);
}


/**
 * entangle_session_remove_media:
 * @session: (transfer none): the session instance
 * @media: (transfer none): the media to remove from the session
 *
 * Remove @media from the @session
 */
void entangle_session_remove_media(EntangleSession *session, EntangleMedia *media)
{
    g_return_if_fail(ENTANGLE_IS_SESSION(session));
    g_return_if_fail(ENTANGLE_IS_MEDIA(media));

    EntangleSessionPrivate *priv = session->priv;
    GList *tmp = g_list_find(priv->files, media);

    if (!tmp)
        return;

    priv->files = g_list_delete_link(priv->files, tmp);

    g_signal_emit_by_name(session, "session-media-removed", media);
    g_object_unref(media);
}


/**
 * entangle_session_load:
 * @session: (transfer none): the session instance
 *
 * Load all the files present in the directory associated
 * with the session
 *
 * Returns: TRUE if the session was loaded
 */
gboolean entangle_session_load(EntangleSession *session)
{
    g_return_val_if_fail(ENTANGLE_IS_SESSION(session), FALSE);

    EntangleSessionPrivate *priv = session->priv;
    GFile *dir = g_file_new_for_path(priv->directory);
    GList *tmp;
    GFileEnumerator *children = g_file_enumerate_children(dir,
                                                          "standard::name,standard::type",
                                                          G_FILE_QUERY_INFO_NONE,
                                                          NULL,
                                                          NULL);
    GFileInfo *childinfo;
    while ((childinfo = g_file_enumerator_next_file(children, NULL, NULL)) != NULL) {
        const gchar *thisname = g_file_info_get_name(childinfo);
        GFile *child = g_file_get_child(dir, thisname);
        if (g_file_info_get_file_type(childinfo) == G_FILE_TYPE_REGULAR ||
            g_file_info_get_file_type(childinfo) == G_FILE_TYPE_SYMBOLIC_LINK) {
            gchar *ctype;
            gchar *mimetype;
            EntangleMedia *media = NULL;
            char *filename = g_file_get_path(child);

            if (!(ctype = g_content_type_guess(filename,
                                               NULL, 0, NULL))) {
                ENTANGLE_DEBUG("No content type for %s", filename);
                g_free(filename);
                continue;
            }

            if (!(mimetype = g_content_type_get_mime_type(ctype))) {
                ENTANGLE_DEBUG("No mime type for content type %s file %s",
                               ctype, filename);
                g_free(filename);
                g_free(ctype);
                continue;
            }
            g_free(ctype);

            if (g_str_has_prefix(mimetype, "image/")) {
                media = ENTANGLE_MEDIA(entangle_image_new_file(filename));
            } else if (g_str_has_prefix(mimetype, "video/")) {
                media = ENTANGLE_MEDIA(entangle_video_new_file(filename));
            } else {
                ENTANGLE_DEBUG("Mime type %s for file %s not wanted",
                               mimetype, filename);
            }
            g_free(mimetype);
            if (media) {
                ENTANGLE_DEBUG("Adding '%s'", filename);
                priv->files = g_list_prepend(priv->files, media);
            }
            g_free(filename);
        }
        g_object_unref(child);
        g_object_unref(childinfo);
    }

    g_object_unref(children);

    priv->files = g_list_sort(priv->files,
                               entangle_session_compare_media);

    tmp = priv->files;
    while (tmp) {
        EntangleMedia *media = ENTANGLE_MEDIA(tmp->data);
        g_signal_emit_by_name(session, "session-media-added", media);
        tmp = tmp->next;
    }

    priv->recalculateDigit = TRUE;

    return TRUE;
}


/**
 * entangle_session_get_media_count:
 * @session: (transfer none): the session instance
 *
 * Get the total number of media files in the session
 *
 * Returns: the file count
 */
int entangle_session_get_media_count(EntangleSession *session)
{
    g_return_val_if_fail(ENTANGLE_IS_SESSION(session), 0);

    EntangleSessionPrivate *priv = session->priv;

    return g_list_length(priv->files);
}


/**
 * entangle_session_get_media:
 * @session: (transfer none): the session instance
 * @idx: index of the media file to fetch
 *
 * Get the media file at position @idx in the session
 *
 * Returns: (transfer none): the media file
 */
EntangleMedia *entangle_session_get_media(EntangleSession *session, int idx)
{
    g_return_val_if_fail(ENTANGLE_IS_SESSION(session), NULL);

    EntangleSessionPrivate *priv = session->priv;

    return g_list_nth_data(priv->files, idx);
}

/*
 * Local variables:
 *  c-indent-level: 4
 *  c-basic-offset: 4
 *  indent-tabs-mode: nil
 *  tab-width: 8
 * End:
 */
