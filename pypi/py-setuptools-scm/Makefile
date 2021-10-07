# $OpenBSD$

COMMENT =	the blessed package to manage your versions by scm tags

MODPY_EGG_VERSION =	6.0.1

DISTNAME =	setuptools_scm-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	https://github.com/pypa/setuptools_scm/

# MIT
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		devel/py-setuptools${MODPY_FLAVOR}>=45 \
			pypi/py-toml${MODPY_FLAVOR}

.include <bsd.port.mk>
