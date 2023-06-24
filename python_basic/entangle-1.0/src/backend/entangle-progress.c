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

#include "entangle-debug.h"
#include "entangle-progress.h"

void entangle_progress_start(EntangleProgress *prog, float target, const char *msg)
{
    g_return_if_fail(ENTANGLE_IS_PROGRESS(prog));

    ENTANGLE_PROGRESS_GET_INTERFACE(prog)->start(prog, target, msg);
}

void entangle_progress_update(EntangleProgress *prog, float current)
{
    g_return_if_fail(ENTANGLE_IS_PROGRESS(prog));

    ENTANGLE_PROGRESS_GET_INTERFACE(prog)->update(prog, current);
}

void entangle_progress_stop(EntangleProgress *prog)
{
    g_return_if_fail(ENTANGLE_IS_PROGRESS(prog));

    ENTANGLE_PROGRESS_GET_INTERFACE(prog)->stop(prog);
}

GType
entangle_progress_get_type(void)
{
    static GType progress_type = 0;

    if (!progress_type) {
        progress_type =
            g_type_register_static_simple(G_TYPE_INTERFACE, "EntangleProgress",
                                          sizeof(EntangleProgressInterface),
                                          NULL, 0, NULL, 0);

        g_type_interface_add_prerequisite(progress_type, G_TYPE_OBJECT);
    }

    return progress_type;
}

/*
 * Local variables:
 *  c-indent-level: 4
 *  c-basic-offset: 4
 *  indent-tabs-mode: nil
 *  tab-width: 8
 * End:
 */
