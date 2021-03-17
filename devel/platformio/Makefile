# $OpenBSD$

COMMENT =	professional collaborative platform for embedded

MODPY_EGG_VERSION =	5.1.0

DISTNAME =	platformio-${MODPY_EGG_VERSION}

CATEGORIES =	devel

HOMEPAGE =	https://platformio.org

# Apache 2.0
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		devel/py-wsproto \
			devel/py-colorama \
			devel/py-click \
			devel/py-tabulate \
			pypi/py-aiofiles \
			pypi/py-jaraco.packaging \
			pypi/py-json-rpc \
			pypi/py-marshmallow \
			pypi/py-rst.linker \
			pypi/py-semantic_version \
			pypi/py-starlette \
			pypi/py-tabulate \
			pypi/py-zeroconf \
			www/py-bottle \
			www/py-uvicorn

.include <bsd.port.mk>
