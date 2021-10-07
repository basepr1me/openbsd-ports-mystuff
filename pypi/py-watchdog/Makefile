# $OpenBSD$

COMMENT =	Filesystem events monitoring

MODPY_EGG_VERSION =	2.1.2

DISTNAME =	watchdog-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	https://github.com/gorakhargosh/watchdog

# Apache 2.0
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		devel/py-argh${MODPY_FLAVOR}>=0.24.1 \
			textproc/py-yaml${MODPY_FLAVOR}>=3.10

.include <bsd.port.mk>
