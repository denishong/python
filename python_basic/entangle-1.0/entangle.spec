# -*- rpm-spec -*-

Summary: Tethered shooting & control of digital cameras
Name: entangle
Version: 1.0
Release: 1%{?dist}
License: GPLv3+
Source: http://entangle-photo.org/download/sources/%{name}-%{version}.tar.xz
URL: http://entangle-photo.org/

BuildRequires: glib2-devel >= 2.36.0
BuildRequires: gtk3-devel >= 3.12
BuildRequires: libgphoto2-devel >= 2.4.11
BuildRequires: libgudev1-devel >= 145
BuildRequires: lcms2-devel >= 2.0
BuildRequires: gobject-introspection-devel
BuildRequires: libpeas-devel >= 1.2.0
BuildRequires: libgexiv2-devel >= 0.2.2
BuildRequires: intltool
BuildRequires: libX11-devel
BuildRequires: libXext-devel >= 1.3.0
BuildRequires: LibRaw-devel >= 0.9.0
BuildRequires: itstool
BuildRequires: gtk-doc
BuildRequires: gstreamer1-devel >= 1.0.0
BuildRequires: gstreamer1-plugins-base-devel >= 1.0.0
BuildRequires: meson >= 0.41.0

BuildRequires: adwaita-icon-theme
Requires: adwaita-icon-theme
Requires: libpeas-loader-python3%{?_isa}

Requires(post): desktop-file-utils
Requires(postun): desktop-file-utils

%description
Entangle is an application which uses GTK and libgphoto2 to provide a
graphical interface for tethered photography with digital cameras.

It includes control over camera shooting and configuration settings
and 'hands off' shooting directly from the controlling computer.

%prep
%setup -q

%build
%meson -Denable-gtk-doc=true
%meson_build

%install
%meson_install
%find_lang %{name}

rm -f %{buildroot}%{_libdir}/libentangle_backend.so
rm -f %{buildroot}%{_libdir}/libentangle_frontend.so

%post
update-desktop-database %{_datadir}/applications
glib-compile-schemas /usr/share/glib-2.0/schemas ||:
touch -c %{_datadir}/icons/hicolor
if [ -x /usr/bin/gtk-update-icon-cache ]; then
	/usr/bin/gtk-update-icon-cache -q %{_datadir}/icons/hicolor || :
fi

%postun
update-desktop-database %{_datadir}/applications
glib-compile-schemas /usr/share/glib-2.0/schemas ||:
touch -c %{_datadir}/icons/hicolor
if [ -x /usr/bin/gtk-update-icon-cache ]; then
	/usr/bin/gtk-update-icon-cache -q %{_datadir}/icons/hicolor || :
fi

%files -f %{name}.lang
%defattr(-, root, root)
%doc README COPYING AUTHORS NEWS ChangeLog
%{_bindir}/entangle
%{_mandir}/man1/entangle.1*

%{_libdir}/libentangle_backend.so.0
%{_libdir}/libentangle_backend.so.0.0.0
%{_libdir}/libentangle_frontend.so.0
%{_libdir}/libentangle_frontend.so.0.0.0

%dir %{_libdir}/%{name}
%dir %{_libdir}/%{name}/plugins
%dir %{_datadir}/%{name}
%dir %{_datadir}/%{name}/plugins

%{_datadir}/icons/hicolor/*/apps/entangle.png
%{_datadir}/icons/hicolor/*/apps/entangle-*.png
%{_datadir}/icons/hicolor/scalable/apps/entangle.svg

%dir %{_datadir}/help/C/entangle/
%{_datadir}/help/C/entangle/*.page
%{_datadir}/help/C/entangle/*.xml
%dir %{_datadir}/help/C/entangle/figures
%{_datadir}/help/C/entangle/figures/*.png

%dir %{_libdir}/%{name}/plugins/photobox
%dir %{_datadir}/%{name}/plugins/photobox
%dir %{_datadir}/%{name}/plugins/photobox/schemas
%{_libdir}/%{name}/plugins/photobox/photobox.plugin
%{_libdir}/%{name}/plugins/photobox/photobox.py*
%{_datadir}/%{name}/plugins/photobox/schemas/gschemas.compiled
%{_datadir}/%{name}/plugins/photobox/schemas/org.entangle-photo.plugins.photobox.gschema.xml

%dir %{_libdir}/%{name}/plugins/shooter
%dir %{_datadir}/%{name}/plugins/shooter
%dir %{_datadir}/%{name}/plugins/shooter/schemas
%{_libdir}/%{name}/plugins/shooter/shooter.plugin
%{_libdir}/%{name}/plugins/shooter/shooter.py*
%{_datadir}/%{name}/plugins/shooter/schemas/gschemas.compiled
%{_datadir}/%{name}/plugins/shooter/schemas/org.entangle-photo.plugins.shooter.gschema.xml

%dir %{_libdir}/%{name}/plugins/eclipse
%dir %{_datadir}/%{name}/plugins/eclipse
%dir %{_datadir}/%{name}/plugins/eclipse/schemas
%{_libdir}/%{name}/plugins/eclipse/eclipse.plugin
%{_libdir}/%{name}/plugins/eclipse/eclipse.py*
%{_datadir}/%{name}/plugins/eclipse/schemas/gschemas.compiled
%{_datadir}/%{name}/plugins/eclipse/schemas/org.entangle-photo.plugins.eclipse.gschema.xml

%{_datadir}/%{name}/sRGB.icc
%{_datadir}/gtk-doc/html/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/appdata/%{name}.appdata.xml
%{_datadir}/glib-2.0/schemas/org.entangle-photo.manager.gschema.xml
%{_datadir}/gir-1.0/Entangle-0.1.gir
%{_libdir}/girepository-1.0/Entangle-0.1.typelib

%changelog
