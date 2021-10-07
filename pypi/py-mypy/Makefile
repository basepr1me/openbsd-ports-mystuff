# $OpenBSD$

COMMENT =	Optional static typing for Python

MODPY_EGG_VERSION =	0.812

DISTNAME =	mypy-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	pypi

HOMEPAGE =	http://www.mypy-lang.org/

# MIT
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		pypi/py-mypy-extensions${MODPY_FLAVOR}>=0.4.3 \
			pypi/py-typed-ast>=1.4.0 \
			pypi/py-typing-extensions${MODPY_FLAVOR}>=3.7.4 \
			sysutils/py-psutil${MODPY_FLAVOR}>=4.0

.include <bsd.port.mk>
