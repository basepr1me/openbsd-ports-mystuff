# $OpenBSD$

COMMENT =		makefile for ESP8266 and ESP32 Arduino projects
V =			5.0.1
DISTNAME =		${V}
PKGNAME =		makeesparduino-${V}

CATEGORIES =		devel

MAINTAINER =		Tracey Emery <tracey@openbsd.org>

#LGPLv2.1
PERMIT_PACKAGE =	Yes

MASTER_SITES = https://github.com/plerup/makeEspArduino/archive/

MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}
MODULES =		lang/python

RUN_DEPENDS +=		devel/arduino \
			devel/gmake

NO_TEST =		Yes

WRKDIST =		${WRKDIR}/makeEspArduino-${V}

post-patch:
	${SUBST_CMD} ${WRKDIST}/makeEspArduino.mk

do-build:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${WRKSRC}/tools

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/makeEspArduino
	cp -r ${WRKDIST}/*.mk ${PREFIX}/share/makeEspArduino/
	cp -r ${WRKDIST}/tools ${PREFIX}/share/makeEspArduino/

.include <bsd.port.mk>
