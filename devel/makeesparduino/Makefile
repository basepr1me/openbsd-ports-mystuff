# $OpenBSD$

COMMENT =		makefile for ESP8266 and ESP32 Arduino projects

V =			4.22.0
CATEGORIES =		devel
PKGNAME =		makeesparduino-${V}

GH_ACCOUNT =		plerup
GH_PROJECT =		makeEspArduino
GH_TAGNAME =		${V}

#LGPLv2.1
PERMIT_PACKAGE =	Yes

RUN_DEPENDS +=		devel/arduino \
			devel/arduino-esp32 \
			devel/arduino-esp8266 \
			devel/gmake \
			devel/xtensa-esp32-elf/gcc \
			devel/xtensa-lx106-elf/gcc

NO_TEST =		Yes
NO_BUILD =		Yes

post-patch:
	@sed -i 's,LOCALBASE,${LOCALBASE},' ${WRKDIST}/makeEspArduino.mk

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/makeEspArduino
	cp -r ${WRKDIST}/*.mk ${PREFIX}/share/makeEspArduino/

.include <bsd.port.mk>
