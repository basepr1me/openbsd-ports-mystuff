# $OpenBSD$

COMMENT =	Python extension for computing string edit distances and

MODPY_EGG_VERSION =	0.12.2

DISTNAME =	python-Levenshtein-${MODPY_EGG_VERSION}
PKGNAME =	${DISTNAME:S/^python-/py-/:L}

CATEGORIES =	pypi

HOMEPAGE =	http://github.com/ztane/python-Levenshtein

# unknown license -> 'GPL'
PERMIT_PACKAGE =	unknown license
PERMIT_DISTFILES =	unknown license

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

FLAVORS =	python3
FLAVOR ?=	python3

.include <bsd.port.mk>
