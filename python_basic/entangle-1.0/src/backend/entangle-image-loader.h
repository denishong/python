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

#ifndef __ENTANGLE_IMAGE_LOADER_H__
#define __ENTANGLE_IMAGE_LOADER_H__

#include "entangle-pixbuf-loader.h"
#include "entangle-image.h"

G_BEGIN_DECLS

#define ENTANGLE_TYPE_IMAGE_LOADER            (entangle_image_loader_get_type ())
#define ENTANGLE_IMAGE_LOADER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENTANGLE_TYPE_IMAGE_LOADER, EntangleImageLoader))
#define ENTANGLE_IMAGE_LOADER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ENTANGLE_TYPE_IMAGE_LOADER, EntangleImageLoaderClass))
#define ENTANGLE_IS_IMAGE_LOADER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENTANGLE_TYPE_IMAGE_LOADER))
#define ENTANGLE_IS_IMAGE_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENTANGLE_TYPE_IMAGE_LOADER))
#define ENTANGLE_IMAGE_LOADER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ENTANGLE_TYPE_IMAGE_LOADER, EntangleImageLoaderClass))


typedef struct _EntangleImageLoader EntangleImageLoader;
typedef struct _EntangleImageLoaderClass EntangleImageLoaderClass;
typedef struct _EntangleImageLoaderPrivate EntangleImageLoaderPrivate;

struct _EntangleImageLoader
{
    EntanglePixbufLoader parent;

    EntangleImageLoaderPrivate *priv;
};

struct _EntangleImageLoaderClass
{
    EntanglePixbufLoaderClass parent_class;
};


GType entangle_image_loader_get_type(void) G_GNUC_CONST;

EntangleImageLoader *entangle_image_loader_new(void);

void entangle_image_loader_add(EntangleImageLoader *loader, EntangleImage *image);
void entangle_image_loader_remove(EntangleImageLoader *loader, EntangleImage *image);

gboolean entangle_image_loader_get_embedded_preview(EntangleImageLoader *loader);
void entangle_image_loader_set_embedded_preview(EntangleImageLoader *loader, gboolean enable);


G_END_DECLS

#endif /* __ENTANGLE_IMAGE_LOADER_H__ */

/*
 * Local variables:
 *  c-indent-level: 4
 *  c-basic-offset: 4
 *  indent-tabs-mode: nil
 *  tab-width: 8
 * End:
 */
