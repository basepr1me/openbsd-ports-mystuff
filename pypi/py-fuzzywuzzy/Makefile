# $OpenBSD$

COMMENT =	Fuzzy string matching in python

MODPY_EGG_VERSION =	0.18.0

DISTNAME =	fuzzywuzzy-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	https://github.com/seatgeek/fuzzywuzzy

# unknown license -> 'GPLv2'
PERMIT_PACKAGE =	unknown license
PERMIT_DISTFILES =	unknown license

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

RUN_DEPENDS =		pypi/py-levenshtein${MODPY_FLAVOR}>=0.12

FLAVORS =	python3
FLAVOR ?=	python3

# Lines below not in the template
FIX_EXTRACT_PERMISSIONS =	Yes
.include <bsd.port.mk>
