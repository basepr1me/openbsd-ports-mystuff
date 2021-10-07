# $OpenBSD$

COMMENT =	Type hints (PEP 484) support for the Sphinx autodoc

MODPY_EGG_VERSION =	1.12.0

DISTNAME =	sphinx-autodoc-typehints-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =

# MIT
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		pypi/py-typed-ast>=1.4.0 \
			textproc/py-sphinx${MODPY_FLAVOR}>=3.0
TEST_DEPENDS =		devel/py-test${MODPY_FLAVOR}>=3.1.0 \
			pypi/py-dataclasses \
			pypi/py-sphobjinv>=2.0 \
			pypi/py-typing-extensions${MODPY_FLAVOR}>=3.5 \
			textproc/py-sphinx${MODPY_FLAVOR}>=3.2.0

.include <bsd.port.mk>
