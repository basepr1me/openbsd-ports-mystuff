# $OpenBSD$

COMMENT =	Pytest support for asyncio

MODPY_EGG_VERSION =	0.15.1

DISTNAME =	pytest-asyncio-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	https://github.com/pytest-dev/pytest-asyncio

# Apache 2.0
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		devel/py-test${MODPY_FLAVOR}>=5.4.0
TEST_DEPENDS =		devel/py-coverage${MODPY_FLAVOR} \
			devel/py-hypothesis${MODPY_FLAVOR}>=5.7.1

.include <bsd.port.mk>
