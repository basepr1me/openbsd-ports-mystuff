# $OpenBSD$

COMMENT =	esp8266 arduino toolset
V =		2.4.1

GH_ACCOUNT =	esp8266
GH_PROJECT =	Arduino
GH_TAGNAME =	${V}

PKGNAME =	arduino-${GH_ACCOUNT}-${V}
DISTFILES =	esp8266-${V}.tar.gz

EFAT_V =	b240d2231a117bbd89b79902eb54cae948ee2f42
LFS_V = 	ce2c01f098f4d2b9479de5a796c3bb531f1fe14c
SS_V =		d4b3c77b2fa1c554b943d8dc2a571a6f5d709bc3
LW_V =		92add5010fc329cbfbbcb1ce713108451cf9fc8c
BSSL_V =	5c771bed8b11b968e2f75f26b9b00de51f2e9333
UZ_V =		80765a42d657fcd3a24e036ac9822f9dbf862449

DISTFILES +=	ESP8266SdFat-${EFAT_V:C/(........).*/\1/}{${EFAT_V}}.tar.gz:0
DISTFILES +=	littlefs-${LFS_V:C/(........).*/\1/}{${LFS_V}}.tar.gz:1
DISTFILES +=	espsoftwareserial-${SS_V:C/(........).*/\1/}{${SS_V}}.tar.gz:2
DISTFILES +=	lwip-builder-${LW_V:C/(........).*/\1/}{${LW_V}}.tar.gz:3
DISTFILES +=	bearssl-${BSSL_V:C/(........).*/\1/}{${BSSL_V}}.tar.gz:4
DISTFILES +=	uzlib-${UZ_V:C/(........).*/\1/}{${UZ_V}}.tar.gz:5

CATEGORIES =	devel

MASTER_SITES0 =	https://github.com/earlephilhower/ESP8266SdFat/archive/
MASTER_SITES1 =	https://github.com/ARMmbed/littlefs/archive/
MASTER_SITES2 =	https://github.com/plerup/espsoftwareserial/archive/
MASTER_SITES3 =	https://github.com/d-a-v/esp82xx-nonos-linklayer/archive/
MASTER_SITES4 =	https://github.com/earlephilhower/bearssl-esp8266/archive/
MASTER_SITES5 =	https://github.com/earlephilhower/uzlib/archive/

#LGPLv2.1, MIT, BSD, Zlib
PERMIT_PACKAGE =	Yes

MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}
MODULES =		lang/python

RUN_DEPENDS +=		devel/arduino \
			devel/esptool-ck \
			devel/py-esptool${MODPY_FLAVOR} \
			devel/mkspiffs \
			devel/xtensa-lx106-elf/gcc

INSTALLDIR =		${PREFIX}/share/arduino/hardware/espressif/esp8266

NO_TEST =		Yes
NO_BUILD =		Yes

post-extract:
	@mv ${WRKDIR}/ESP8266SdFat-* ${WRKSRC}/libraries/ESP8266SdFat
	@mkdir -p ${WRKSRC}/libraries/LittleFS/lib
	@mv ${WRKDIR}/littlefs-* ${WRKSRC}/libraries/LittleFS/lib/littlefs
	@mv ${WRKDIR}/espsoftwareserial-* ${WRKSRC}/libraries/SoftwareSerial
	@rmdir ${WRKSRC}/tools/sdk/lwip2/builder
	@mv ${WRKDIR}/esp82xx-nonos-linklayer-* \
		${WRKSRC}/tools/sdk/lwip2/builder
	@mkdir -p ${WRKSRC}/tools/sdk/ssl
	@mv ${WRKDIR}/bearssl-* ${WRKSRC}/tools/sdk/ssl/bearssl
	@mv ${WRKDIR}/uzlib-* ${WRKSRC}/tools/sdk/uzlib
	@rm ${WRKSRC}/cores/esp8266/core_esp8266_sigma_delta.c.unused

post-patch:
	@sed -i 's,PREFIX,${LOCALBASE},' ${WRKDIST}/platform.txt

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/doc/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/libraries/ESP8266SdFat/
	# bad syntax
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/libraries/LittleFS/lib/littlefs/scripts/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/package/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tests/device/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tools/

.include <bsd.port.mk>
