# $OpenBSD$

COMMENT =	Backported and Experimental Type Hints for Python 3.5+

MODPY_EGG_VERSION =	3.10.0.0

DISTNAME =	typing_extensions-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	https://github.com/python/typing/blob/master/typing_extensions/README.rst

# unknown license -> 'PSF'
PERMIT_PACKAGE =	unknown license
PERMIT_DISTFILES =	unknown license

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

RUN_DEPENDS =		devel/py-typing>=3.7.4

FLAVORS =	python3
FLAVOR ?=	python3

.include <bsd.port.mk>
