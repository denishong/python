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

#ifndef __ENTANGLE_SESSION_BROWSER_H__
#define __ENTANGLE_SESSION_BROWSER_H__

#include <gtk/gtk.h>

#include "entangle-media.h"
#include "entangle-thumbnail-loader.h"
#include "entangle-session.h"

G_BEGIN_DECLS

#define ENTANGLE_TYPE_SESSION_BROWSER            (entangle_session_browser_get_type ())
#define ENTANGLE_SESSION_BROWSER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENTANGLE_TYPE_SESSION_BROWSER, EntangleSessionBrowser))
#define ENTANGLE_SESSION_BROWSER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENTANGLE_TYPE_SESSION_BROWSER, EntangleSessionBrowserClass))
#define ENTANGLE_IS_SESSION_BROWSER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENTANGLE_TYPE_SESSION_BROWSER))
#define ENTANGLE_IS_SESSION_BROWSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENTANGLE_TYPE_SESSION_BROWSER))
#define ENTANGLE_SESSION_BROWSER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENTANGLE_TYPE_SESSION_BROWSER, EntangleSessionBrowserClass))


typedef struct _EntangleSessionBrowser EntangleSessionBrowser;
typedef struct _EntangleSessionBrowserPrivate EntangleSessionBrowserPrivate;
typedef struct _EntangleSessionBrowserClass EntangleSessionBrowserClass;

struct _EntangleSessionBrowser
{
    GtkDrawingArea parent;

    EntangleSessionBrowserPrivate *priv;
};

struct _EntangleSessionBrowserClass
{
    GtkDrawingAreaClass parent_class;
};

GType entangle_session_browser_get_type(void) G_GNUC_CONST;

EntangleSessionBrowser* entangle_session_browser_new(void);

EntangleMedia *entangle_session_browser_get_selected_media(EntangleSessionBrowser *browser);

GList *entangle_session_browser_get_earlier_images(EntangleSessionBrowser *browser,
                                                   gboolean include_selected,
                                                   gsize count);

void entangle_session_browser_set_thumbnail_loader(EntangleSessionBrowser *browser,
                                                   EntangleThumbnailLoader *loader);
EntangleThumbnailLoader *entangle_session_browser_get_thumbnail_loader(EntangleSessionBrowser *browser);


void entangle_session_browser_set_session(EntangleSessionBrowser *browser,
                                          EntangleSession *session);
EntangleSession *entangle_session_browser_get_session(EntangleSessionBrowser *browser);

EntangleMedia *entangle_session_browser_get_media_at_coords(EntangleSessionBrowser *browser,
                                                            gint x, gint y);

void entangle_session_browser_set_background(EntangleSessionBrowser *browser,
                                             const gchar *background);
gchar *entangle_session_browser_get_background(EntangleSessionBrowser *browser);

void entangle_session_browser_set_highlight(EntangleSessionBrowser *browser,
                                            const gchar *highlight);
gchar *entangle_session_browser_get_highlight(EntangleSessionBrowser *browser);


G_END_DECLS

#endif /* __ENTANGLE_SESSION_BROWSER_H__ */


/*
 * Local variables:
 *  c-indent-level: 4
 *  c-basic-offset: 4
 *  indent-tabs-mode: nil
 *  tab-width: 8
 * End:
 */
