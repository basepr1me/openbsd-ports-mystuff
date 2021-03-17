# $OpenBSD: $

V =			0.3.8
COMMENT =		software to analyze data on NanoVNA devices

DISTNAME =		nanovnasaver-${V}

GH_ACCOUNT =		NanoVNA-Saver
GH_PROJECT =		nanovna-saver
GH_TAGNAME =		v${V}

CATEGORIES =		education

HOMEPAGE =		https://nanovna.com/

MAINTAINER =		Tracey Emery <tracey@openbsd.org>

#GPLv3
PERMIT_PACKAGE = 	Yes

MODULES =		lang/python

MODPY_SETUPTOOLS =	Yes

RUN_DEPENDS =		devel/py-serial${MODPY_FLAVOR} \
			math/py-numpy${MODPY_FLAVOR} \
			math/py-scipy${MODPY_FLAVOR} \
			x11/py-qt5${MODPY_FLAVOR}

FLAVORS =		python3
FLAVOR ?=		python3

.include <bsd.port.mk>
