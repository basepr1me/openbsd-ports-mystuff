# $OpenBSD$

COMMENT =	The comprehensive WSGI web application library

MODPY_EGG_VERSION =	2.0.1

DISTNAME =	Werkzeug-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME:L}

CATEGORIES =	pypi

HOMEPAGE =	https://palletsprojects.com/p/werkzeug/

# unknown license -> 'BSD-3-Clause'
PERMIT_PACKAGE =	unknown license
PERMIT_DISTFILES =	unknown license

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

RUN_DEPENDS =		pypi/py-dataclasses \
			pypi/py-watchdog

.include <bsd.port.mk>
