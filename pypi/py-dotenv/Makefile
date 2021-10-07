# $OpenBSD$

COMMENT =	Read key-value pairs from a .env file and set them as

MODPY_EGG_VERSION =	0.17.1

DISTNAME =	python-dotenv-${MODPY_EGG_VERSION}
PKGNAME =	${DISTNAME:S/^python-/py-/}

CATEGORIES =	pypi

HOMEPAGE =	https://github.com/theskumar/python-dotenv

# license field not set, consider bugging module's author
PERMIT_PACKAGE =	unknown license
PERMIT_DISTFILES =	unknown license

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

RUN_DEPENDS =		devel/py-click${MODPY_FLAVOR}>=5.0 \
			devel/py-typing

FLAVORS =	python3
FLAVOR ?=	python3

.include <bsd.port.mk>
