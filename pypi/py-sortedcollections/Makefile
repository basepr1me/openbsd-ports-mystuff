# $OpenBSD$

COMMENT =	Python Sorted Collections

MODPY_EGG_VERSION =	2.1.0

DISTNAME =	sortedcollections-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	http://www.grantjenks.com/docs/sortedcollections/

# Apache 2.0
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		devel/py-sortedcontainers${MODPY_FLAVOR}

.include <bsd.port.mk>
