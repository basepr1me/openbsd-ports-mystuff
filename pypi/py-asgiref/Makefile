# $OpenBSD$

COMMENT =	ASGI specs, helper code, and adapters

MODPY_EGG_VERSION =	3.3.4

DISTNAME =	asgiref-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	https://github.com/django/asgiref/

# BSD
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		devel/py-test${MODPY_FLAVOR} \
			pypi/py-mypy>=0.800 \
			pypi/py-pytest-asyncio \
			pypi/py-typing-extensions${MODPY_FLAVOR}

.include <bsd.port.mk>
