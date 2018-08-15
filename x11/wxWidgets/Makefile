# $OpenBSD:

COMMENT =	C++ cross-platform GUI toolkit

V =		3.0.2
GH_ACCOUNT = 	wxWidgets
GH_PROJECT = 	wxWidgets
GH_TAGNAME = 	v${V}
CATEGORIES =	x11

SHARED_LIBS +=  wx_baseu-3.0              0.0 # 0.0
SHARED_LIBS +=  wx_baseu_net-3.0          0.0 # 0.0
SHARED_LIBS +=  wx_baseu_xml-3.0          0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_adv-3.0          0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_aui-3.0          0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_core-3.0         0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_gl-3.0           0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_html-3.0         0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_media-3.0        0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_propgrid-3.0     0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_qa-3.0           0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_ribbon-3.0       0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_richtext-3.0     0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_stc-3.0          0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_webview-3.0      0.0 # 0.0
SHARED_LIBS +=  wx_gtk3u_xrc-3.0          0.0 # 0.0

HOMEPAGE =	http://www.wxwidgets.org/

#PKGNAME =  wxWidgets-gtk3-${V}
# wxWindows (modified LGPL)
# http://www.wxwidgets.org/about/licence/
PERMIT_PACKAGE_CDROM =	Yes

BUILD_DEPENDS =	devel/cppunit \
		devel/gettext-tools

LIB_DEPENDS =   devel/gettext \
		x11/gtk+3

TEST_DEPENDS = 	${BUILD_PKGPATH}>=${V}

WANTLIB += ${COMPILER_LIBCXX} GL GLU SM X11 Xxf86vm atk-1.0 c
WANTLIB += cairo cairo-gobject expat fribidi gdk-3 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 gthread-2.0
WANTLIB += gtk-3 iconv intl jpeg m pango-1.0 pangocairo-1.0 png
WANTLIB += tiff xml2 z

MAKE_FLAGS =	WXUNICODEFLAG="u"

USE_GMAKE =	Yes
AUTOCONF_VERSION = 2.69
CONFIGURE_STYLE =	autoconf no-autoheader
CONFIGURE_ARGS =	--disable-backtrace \
			--enable-mediactrl \
			--enable-unicode \
			--with-odbc \
			--with-opengl \
			--with-sdl \
			--with-gtk=3 \
			--without-webkit \
			--without-gnomeprint \
			--enable-graphics_ctx
CONFIGURE_ENV =	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		WXCONFIG_CPPFLAGS="-I${X11BASE}/include" \
		ac_cv_lib_esd_esd_close=no

# XXX: When used in conjunction with PIE, symbol versioning triggers
# weird linking problems in dependent ports
CONFIGURE_ENV += wx_cv_version_script=no

.ifdef DEBUG
CONFIGURE_ARGS += --enable-debug
.endif
MODPY_ADJ_FILES = src/stc/gen_iface.py

pre-configure:
	perl -pi -e 's/\r$$//' ${WRKSRC}/src/stc/gen_iface.py
	${SUBST_CMD} ${WRKSRC}/Makefile.in
	${MODPYTHON_pre-configure}

# - resolve conflict with x11/wxWidgets (v2)
# - fix DOS linebreaks
# - use a medium-sized hammer to remove library links
post-install:
#	mv ${PREFIX}/bin/wx-config ${PREFIX}/bin/wx-config-3.0
	rm ${PREFIX}/bin/wxrc-3.0
	perl -pi -e 's/\r$$//' ${PREFIX}/lib/wx/config/gtk3-unicode-3.0
	find ${PREFIX}/lib/ -type l -name libwx\* -exec rm {} \;

do-test:
	@cd ${WRKSRC}/tests && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} && ./test

.include <bsd.port.mk>
