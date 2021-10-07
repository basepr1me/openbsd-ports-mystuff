# $OpenBSD$

COMMENT =	backport of the dataclasses module for Python 3.6

MODPY_EGG_VERSION =	0.8

DISTNAME =	dataclasses-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	https://github.com/ericvsmith/dataclasses

# unknown license -> 'Apache'
PERMIT_PACKAGE =	unknown license
PERMIT_DISTFILES =	unknown license

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

# Lines below not in the template
FIX_EXTRACT_PERMISSIONS =	Yes
.include <bsd.port.mk>
