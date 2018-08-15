# $OpenBSD: Makefile,v 1.20 2017/07/26 22:45:33 sthen Exp $

COMMENT=	Python bindings for wxWidgets C++ class library

V=		3.0.2.0
DISTNAME=	wxPython-src-$V
PKGNAME=	py-wxPython-$V
CATEGORIES=	x11 devel

HOMEPAGE=	http://www.wxpython.org/

MAINTAINER=	Aleksander Piotrowski <pelotasplus@gmail.com>

# modified LGPL
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}
EXTRACT_SUFX=	.tar.bz2

USE_GMAKE =		Yes

MODULES =	lang/python

LIB_DEPENDS=    www/webkitgtk4 \
		x11/gtk+3 \
		x11/wxWidgets

#BUILD_DEPENDS =	x11/gtk+3

CFLAGS+=	"-I${LOCALBASE}/include/wx-3.0" \
		"-I${LOCALBASE}/lib/wx/include/gtk3-unicode-3.0"
#		"-I${LOCALBASE}/lib"

COMPILER =	ports-clang
#WANTLIB +=	wx_gtk3u_aui wx_gtk3_richtext wx_gtk3_gizmos wx_gtk3_stc \
#		wx_base_xml wx_gtk3_qa wx_base_odbc wx_gtk3_html \
#		wx_gtk3_gl wx_base wx_gtk3_adv wx_gtk3_xrc wx_gtk3_core \
#		wx_base_net wx_gtk3_dbgrid m pthread ${COMPILER_LIBCXX} ${MODPY_WANTLIB}

#WANTLIB +=	wx_gtk3_aui m pthread ${COMPILER_LIBCXX} ${MODPY_WANTLIB}
WRKSRC=		${WRKDIST}/wxPython

SUBST_VARS +=	WRKINST

NO_TEST=	Yes

pre-build:
	${SUBST_CMD} ${WRKSRC}/config.py
#post-install:
#	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-wxPython
#	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-wxPython/demo
#	cd ${WRKSRC}/demo; tar -cf - * | \
#		(cd ${PREFIX}/share/examples/py-wxPython/demo; tar -xf -)
#	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-wxPython/samples
#	cd ${WRKSRC}/samples; tar -cf - * | \
#		(cd ${PREFIX}/share/examples/py-wxPython/samples; tar -xf -)

.include <bsd.port.mk>
