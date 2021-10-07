# $OpenBSD$

COMMENT =	simple framework for building complex web applications

MODPY_EGG_VERSION =	2.0.1

DISTNAME =	Flask-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME:L}

CATEGORIES =	pypi

HOMEPAGE =	https://palletsprojects.com/p/flask

# unknown license -> 'BSD-3-Clause'
PERMIT_PACKAGE =	unknown license
PERMIT_DISTFILES =	unknown license

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

RUN_DEPENDS =		devel/py-click${MODPY_FLAVOR}>=7.1.2 \
			pypi/py-asgiref>=3.2 \
			pypi/py-dotenv${MODPY_FLAVOR} \
			pypi/py-itsdangerous>=2.0 \
			pypi/py-werkzeug>=2.0 \
			www/py-jinja2${MODPY_FLAVOR}>=3.0

.include <bsd.port.mk>
