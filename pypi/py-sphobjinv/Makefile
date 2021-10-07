# $OpenBSD$

COMMENT =	Sphinx objects.inv Inspection/Manipulation Tool

MODPY_EGG_VERSION =	2.1

PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	https://github.com/bskinn/sphobjinv

# MIT
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		devel/py-attrs${MODPY_FLAVOR}>=19.2 \
			devel/py-certifi${MODPY_FLAVOR} \
			devel/py-jsonschema${MODPY_FLAVOR}>=3.0 \
			pypi/py-fuzzywuzzy${MODPY_FLAVOR}>=0.8 \
			pypi/py-levenshtein${MODPY_FLAVOR}

.include <bsd.port.mk>
