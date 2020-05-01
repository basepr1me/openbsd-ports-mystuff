# $OpenBSD$

COMMENT =		tool for isolation, routing, and drilling of PCBs
V =			2.0.0
# PKGNAME =		pcb2gcode-${V}

GH_ACCOUNT =		pcb2gcode
GH_PROJECT =		pcb2gcode
GH_TAGNAME =		v${V}

CATEGORIES =		cad

MAINTAINER =		Tracey Emery <tracey@openbsd.org>

#GPLv3+
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} X11 Xcomposite Xcursor Xdamage Xext
WANTLIB += Xfixes Xi Xinerama Xrandr Xrender atk-1.0 boost_program_options-mt
WANTLIB += c cairo cairomm-1.0 expat ffi fontconfig freetype fribidi
WANTLIB += gdk-x11-2.0 gdk_pixbuf-2.0 gdkmm-2.4 gerbv gio-2.0
WANTLIB += giomm-2.4 glib-2.0 glibmm-2.4 gmodule-2.0 gobject-2.0
WANTLIB += graphite2 gtk-x11-2.0 harfbuzz iconv intl m pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 pangomm-1.4 pcre pixman-1
WANTLIB += png sigc-2.0 xcb xcb-render xcb-shm z

COMPILER =		base-clang ports-gcc base-gcc

BUILD_DEPENDS =		cad/gerbv \
			devel/boost \
			x11/gnome/librsvg \
			x11/gtk2mm
LIB_DEPENDS =		cad/gerbv \
			devel/boost \
			devel/atk \
			devel/fribidi \
			devel/libffi \
			graphics/cairo \
			x11/gtk2mm

CONFIGURE_STYLE =	autoreconf
CONFIGURE_ENV =		LDFLAGS="-L${LOCALBASE}/lib -s" \
			CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include"

MAKE_FLAGS =		GIT_VERSION="${V}"

AUTOCONF_VERSION =	2.69
AUTOMAKE_VERSION =	1.16

.include <bsd.port.mk>
