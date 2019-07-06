# $OpenBSD$

V =			2.4.1
DISTNAME =		esp8266-${V}
COMMENT =		esp8266 arduino toolset
CATEGORIES =		devel

PKGNAME =		arduino-esp8266-${V}
HOMEPAGE =		https://github.com/esp8266/Arduino

MASTER_SITES =		https://github.com/esp8266/Arduino/archive/${V}/

MAINTAINER =            Tracey Emery <tracey@traceyemery.net>

#GPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

NO_TEST =		Yes

NO_BUILD =		Yes

BUILD_DEPENDS =		devel/arduino

RUN_DEPENDS +=		devel/arduino \
			devel/esptool-ck \
			devel/esptool-py \
			devel/mkspiffs

MODULES =		lang/python

WRKDIST =		${WRKDIR}/Arduino-${V}
WRKSRC =		${WRKDIST}
INSTALLDIR =		${PREFIX}/share/arduino/hardware/espressif/esp8266

post-extract:
	@rm ${WRKSRC}/cores/esp8266/core_esp8266_sigma_delta.c.unused

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}


#post-install:

.include <bsd.port.mk>
