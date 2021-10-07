# $OpenBSD$

COMMENT =	Wrappers to build Python packages using PEP 517 hooks

MODPY_EGG_VERSION =	0.10.0

DISTNAME =	pep517-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	https://github.com/pypa/pep517

# license field not set, consider bugging module's author
PERMIT_PACKAGE =	unknown license
PERMIT_DISTFILES =	unknown license

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

FLAVORS =	python3
FLAVOR ?=	python3

.include <bsd.port.mk>
