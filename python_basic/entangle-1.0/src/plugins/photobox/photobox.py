#
# Entangle: Tethered Camera Control & Capture
#
# Copyright (C) 2014-2017 Daniel P. Berrange
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

import gi

from gi.repository import GObject
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk
from gi.repository import Gdk
from gi.repository import GLib
from gi.repository import Gio
from gi.repository import Peas
gi.require_version("PeasGtk", "1.0")
from gi.repository import PeasGtk
gi.require_version("Entangle", "0.1")
from gi.repository import Entangle


class PhotoBoxPluginUnlockDialog(Gtk.Dialog):
    '''Handles prompting the user for an unlock password to
    determine whether they are authorized to exit the photo
    box'''

    def __init__(self, win, config):
        Gtk.Dialog.__init__(self,
                            title="Exit photo box",
                            parent=win,
                            flags=Gtk.DialogFlags.MODAL)

        self.add_button("OK", Gtk.ResponseType.ACCEPT)
        self.add_button("Cancel", Gtk.ResponseType.REJECT)
        self.set_transient_for(win)

        self.config = config

        box = self.get_child()
        box.set_border_width(6)

        controls = Gtk.Box()
        controls.set_orientation(Gtk.Orientation.VERTICAL)
        controls.add(Gtk.Label("A password is required to exit the photo box"))

        passwdmsg = Gtk.Label("Password:")
        passwdmsg.set_hexpand(False)
        self.passwdtxt = Gtk.Entry()
        self.passwdtxt.set_visibility(False)
        self.passwdtxt.set_hexpand(True)

        passwd = Gtk.Box()
        passwd.set_orientation(Gtk.Orientation.HORIZONTAL)
        passwd.add(passwdmsg)
        passwd.add(self.passwdtxt)
        controls.add(passwd)

        self.warning = Gtk.Label()
        controls.add(self.warning)

        controls.set_border_width(6)
        passwd.set_spacing(6)
        controls.set_spacing(6)

        self.get_content_area().add(controls)
        controls.show_all()
        self.warning.hide()

        self.passwdtxt.connect("key-release-event",
                               lambda src, ev: self.warning.hide())

    def run(self):
        while True:
            status = Gtk.Dialog.run(self)
            if status != Gtk.ResponseType.ACCEPT:
                return False
            if self.config.get_unlock_password() == self.passwdtxt.get_text():
                return True

            self.warning.set_text("Incorrect password")
            self.warning.show()


class PhotoBoxPluginWindow(object):
    '''Handles interaction with a single instance of
    the EntangleCameraManager window. We add a menu
    option to the 'Windows' menu which allows the
    photobox mode to be started. It can be stopped
    by pressing escape. In photobox mode the menubar,
    toolbar and controls are all hidden. A single
    shoot button is added at the bottom of the screen'''

    def __init__(self, win, config):
        '''@win: an instance of EntangleCameraManager'''

        self.config = config
        self.win = win
        self.action = None
        self.button = Gtk.Button("Shoot")
        self.winsig = None
        self.buttonsig = None

    def do_set_widget_state(self, visible):
        settings = self.win.get_template_child(Entangle.CameraManager, "settingsScroll")
        settings.set_visible(visible)

    def do_start_photobox(self):
        self.do_set_widget_state(False)
        pane = self.win.get_template_child(Entangle.CameraManager, "winBox")
        pane.pack_start(self.button, False, True, 0)
        self.button.show()
        self.button.grab_focus()
        self.win.fullscreen()
        self.winsig = self.win.connect("key-release-event", self.do_key_release)
        self.buttonsig = self.button.connect("clicked", self.do_capture)

    def do_stop_photobox(self):
        self.do_set_widget_state(True)
        pane = self.win.get_template_child(Entangle.CameraManager, "winBox")
        pane.remove(self.button)
        self.win.unfullscreen()
        self.win.disconnect(self.winsig)
        self.button.disconnect(self.buttonsig)

    def do_close_greeting(self, src, response, data=None):
        src.set_visible(False)
        src.destroy()

    def do_show_greeting(self):
        dlg = Gtk.MessageDialog(title="Photo box active",
                                parent=self.win,
                                flags=Gtk.DialogFlags.MODAL,
                                type=Gtk.MessageType.INFO,
                                buttons=Gtk.ButtonsType.OK)
        dlg.set_markup("Press 'Escape' to exit photo box")
        dlg.set_transient_for(self.win)
        dlg.connect("response", self.do_close_greeting)
        dlg.show()

    def do_toggle_photobox(self, action, state, data=None):
        if state.unpack():
            self.do_start_photobox()

            GLib.timeout_add(500, self.do_show_greeting)
        else:
            self.do_stop_photobox()

    def do_key_release(self, src, ev):
        if ev.keyval == Gdk.KEY_Escape:
            passwd = self.config.get_unlock_password()
            if passwd == "":
                self.action.change_state(GLib.Variant('b', False))
            else:
                dlg = PhotoBoxPluginUnlockDialog(self.win,
                                                 self.config)
                if dlg.run():
                    self.action.change_state(GLib.Variant('b', False))
                dlg.destroy()

    def do_capture(self, src):
        self.win.capture()

    def do_state_photobox(self, action, data=None):
        action.change_state(GLib.Variant('b', not action.get_state()))

    def activate(self):
        '''Activate the plugin on the window'''

        action = Gio.SimpleAction.new_stateful("photobox", None, GLib.Variant('b', False))
        action.connect("activate", self.do_state_photobox)
        action.connect("change-state", self.do_toggle_photobox)
        self.win.add_action(action)
        self.action = action

        button = self.win.get_template_child(Entangle.CameraManager, "titlebarButtonView")
        mod = button.get_menu_model()
        mod.append("Photobox", "win.photobox")

    def deactivate(self):
        '''Deactivate the plugin on the window, undoing
        all changes made since the 'activate' call'''

        if self.action.get_state().unpack():
            self.do_stop_photobox()

        button = self.win.get_template_child(Entangle.CameraManager, "titlebarButtonView")
        mod = button.get_menu_model()
        nth = mod.get_n_items()
        mod.remove(nth - 1)

        self.action = None
        self.wins.remove_action("photobox")


class PhotoBoxPluginConfig(Gtk.Grid):
    '''Provides integration with GSettings to read/write
    configuration parameters'''

    def __init__(self, plugin_info):
        Gtk.Grid.__init__(self)
        settingsdir = plugin_info.get_data_dir() + "/schemas"
        sssdef = Gio.SettingsSchemaSource.get_default()
        sss = Gio.SettingsSchemaSource.new_from_directory(settingsdir, sssdef, False)
        schema = sss.lookup("org.entangle-photo.plugins.photobox", False)
        self.settings = Gio.Settings.new_full(schema, None, None)

    def get_unlock_password(self):
        return self.settings.get_string("unlock-password")

    def set_unlock_password(self, passwd):
        self.settings.set_string("unlock-password", passwd)


class PhotoBoxPluginConfigure(Gtk.Grid):
    ''''Provides the configuration widget for the plugin'''

    def __init__(self, config):
        Gtk.Grid.__init__(self)
        self.config = config
        self.passwdtxt = Gtk.Entry()
        self.passwdtxt.set_visibility(False)
        self.attach(Gtk.Label("Unlock password:"),
                    0, 0, 1, 1)
        self.attach(self.passwdtxt,
                    1, 0, 2, 1)
        self.set_border_width(6)
        self.set_row_spacing(6)
        self.set_column_spacing(6)

        self.passwdtxt.connect("changed", self.do_set_unlock_password)

        self.passwdtxt.set_text(self.config.get_unlock_password())

    def do_set_unlock_password(self, src):
        self.config.set_unlock_password(src.get_text())


class PhotoBoxPlugin(GObject.Object, Peas.Activatable, PeasGtk.Configurable):
    '''Handles the plugin activate/deactivation and
    tracking of camera manager windows. When a window
    appears, it enables the photobox functionality on
    that window'''
    __gtype_name__ = "PhotoBoxPlugin"

    object = GObject.property(type=GObject.Object)

    def __init__(self):
        GObject.Object.__init__(self)
        self.winsig = None
        self.wins = []
        self.config = None

    def do_activate_window(self, win):
        if not isinstance(win, Entangle.CameraManager):
            return
        pb = PhotoBoxPluginWindow(win, self.config)
        self.wins.append(pb)
        pb.activate()

    def do_deactivate_window(self, win):
        if not isinstance(win, Entangle.CameraManager):
            return
        oldwins = self.wins
        self.wins = []
        for w in oldwins:
            if w.win == win:
                w.deactivate()
            else:
                self.wins.append(w)

    def do_activate(self):
        if self.config is None:
            self.config = PhotoBoxPluginConfig(self.plugin_info)

        # Windows can be dynamically added/removed so we
        # must track this
        self.winsig = self.object.connect(
            "window-added",
            lambda app, win: self.do_activate_window(win))
        self.winsig = self.object.connect(
            "window-removed",
            lambda app, win: self.do_deactivate_window(win))

        for win in self.object.get_windows():
            self.do_activate_window(win)

    def do_deactivate(self):
        self.object.disconnect(self.winsig)
        for win in self.object.get_windows():
            self.do_deactivate_window(win)
        self.config = None


    def do_create_configure_widget(self):
        if self.config is None:
            self.config = PhotoBoxPluginConfig(self.plugin_info)

        return PhotoBoxPluginConfigure(self.config)
