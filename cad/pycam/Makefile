# $OpenBSD: $

V =			0.6.5
COMMENT =		generate gcode from 2D or 3D models for 3-axis CNC

DISTNAME =		pycam-${V}

GH_ACCOUNT =		SebKuzminsky
GH_PROJECT =		pycam
#GH_TAGNAME =		v${V}
GH_COMMIT =		4687f2f62bd75078a7b1b70339e9a5df75b64c63

CATEGORIES =		cad

HOMEPAGE =		http://pycam.sourceforge.net/

MAINTAINER =		Tracey Emery <tracey@openbsd.org>

#GPLv3
PERMIT_PACKAGE = 	Yes

MODULES =		lang/python

MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}
MODPY_SETUPTOOLS =	Yes

RUN_DEPENDS =		devel/py-gobject3 \
			x11/gtk+3

.include <bsd.port.mk>
