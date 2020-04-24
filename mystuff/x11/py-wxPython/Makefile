# $OpenBSD: Makefile,v 1.24 2019/07/12 20:51:20 sthen Exp $

COMMENT=	Python bindings for wxWidgets C++ class library

V=		4.0.1
#DISTNAME=	wxPython-src-$V
PKGNAME=	py-wxPython-$V
CATEGORIES=	x11 devel

GH_ACCOUNT=	wxWidgets
GH_PROJECT=	Phoenix
GH_TAGNAME=	wxPython-${V}

DISTFILES=	wxPython-${V}.tar.gz

NSVG_V=		9dd92bbfc6f709e889578a724724ffbd42ac3004
WXWG_V=		501e55f949725fd47bc14ddd7e7e059d376d387c
DISTFILES+=    	nanosvg-${NSVG_V:C/(........).*/\1/}{${NSVG_V}}.tar.gz:0
DISTFILES+=    	wxwidgets-${WXWG_V:C/(........).*/\1/}{${WXWG_V}}.tar.gz:1

HOMEPAGE=	https://www.wxpython.org/

MASTER_SITES0= 	https://github.com/wxWidgets/nanosvg/archive/
MASTER_SITES1= 	https://github.com/wxWidgets/wxWidgets/archive/

# modified LGPL
PERMIT_PACKAGE=	Yes

MODPY_VERSION= ${MODPY_DEFAULT_VERSION_3}

MODULES=	lang/python
# LIB_DEPENDS=    x11/wxWidgets>=3.0.4
BUILD_DEPENDS=	devel/py-setuptools${MODPY_FLAVOR}

# WANTLIB += ${COMPILER_LIBCXX} ${MODPY_WANTLIB} m
# WANTLIB += wx_baseu-3.0 wx_baseu_net-3.0 wx_baseu_xml-3.0 wx_gtk3u_adv-3.0
# WANTLIB += wx_gtk3u_aui-3.0 wx_gtk3u_core-3.0 wx_gtk3u_gl-3.0
# WANTLIB += wx_gtk3u_html-3.0 wx_gtk3u_propgrid-3.0 wx_gtk3u_qa-3.0
# WANTLIB += wx_gtk3u_richtext-3.0 wx_gtk3u_stc-3.0 wx_gtk3u_xrc-3.0

COMPILER =		base-clang ports-gcc base-gcc

#WRKSRC=		${WRKDIST}/wxPython

SUBST_VARS +=	WRKINST

MODPY_SETUPTOOLS =	Yes
MODPY_DISTUTILS_BUILDARGS =     --build-base="${WRKBUILD}"

NO_TEST=	Yes

post-extract:
	mv ${WRKDIR}/nanosvg-* ${WRKSRC}/nanosvg
	mv ${WRKDIR}/wxWidgets-* ${WRKSRC}/wxWidgets


pre-build:
	${SUBST_CMD} ${WRKSRC}/setup.py

# post-install:
# 	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-wxPython
# 	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-wxPython/demo
# 	cd ${WRKSRC}/demo; tar -cf - * | \
# 		(cd ${PREFIX}/share/examples/py-wxPython/demo; tar -xf -)
# 	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-wxPython/samples
# 	cd ${WRKSRC}/samples; tar -cf - * | \
# 		(cd ${PREFIX}/share/examples/py-wxPython/samples; tar -xf -)

.include <bsd.port.mk>
