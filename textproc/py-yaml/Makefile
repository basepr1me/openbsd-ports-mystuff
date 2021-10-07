# $OpenBSD: Makefile,v 1.23 2021/01/04 14:06:39 sthen Exp $

COMMENT=	YAML parser and emitter for Python

MODPY_EGG_VERSION=	5.4.1
DISTNAME=	PyYAML-${MODPY_EGG_VERSION}
PKGNAME=	py-yaml-${MODPY_EGG_VERSION}
CATEGORIES=	textproc

HOMEPAGE=	https://pyyaml.org/

MAINTAINER=	Pierre-Emmanuel Andre <pea@openbsd.org>

# MIT
PERMIT_PACKAGE=	Yes

WANTLIB+=	pthread yaml-0 ${MODPY_WANTLIB}

MODULES=	lang/python
MODPY_PI=	Yes

FLAVORS =	python3
FLAVOR ?=	python3

LIB_DEPENDS=	devel/libyaml

pre-configure:
	${SUBST_CMD} ${WRKSRC}/setup.cfg

do-test:
	@cd ${WRKSRC} && ${MODPY_BIN} ${MODPY_SETUP} test

# Lines below not in the template
MODPY_SETUPTOOLS=	Yes
.include <bsd.port.mk>
