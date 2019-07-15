# $OpenBSD$

V =			2.4.1
DISTNAME =		esp8266-${V}
COMMENT =		esp8266 arduino toolset
CATEGORIES =		devel

PKGNAME =		arduino-esp8266-${V}
HOMEPAGE =		https://github.com/esp8266/Arduino

MASTER_SITES =		https://github.com/esp8266/Arduino/archive/${V}/

#LGPLv2.1
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

BUILD_DEPENDS =		devel/arduino

RUN_DEPENDS +=		devel/arduino \
			devel/esptool-ck \
			devel/esptool-py \
			devel/mkspiffs \
			devel/xtensa-lx106-elf/gcc-lx106

WRKDIST =		${WRKDIR}/Arduino-${V}
WRKSRC =		${WRKDIST}
INSTALLDIR =		${PREFIX}/share/arduino/hardware/espressif/esp8266

NO_TEST =		Yes
NO_BUILD =		Yes

post-extract:
	@rm ${WRKSRC}/cores/esp8266/core_esp8266_sigma_delta.c.unused

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/doc/conf.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/package/merge_packages.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tests/device/libraries/BSTest/mock_decorators.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tests/device/libraries/BSTest/runner.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tests/device/test_WiFiServer/test_WiFiServer.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tests/device/test_http_client/test_http_client.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tests/device/test_http_server/test_http_server.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tools/boards.txt.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tools/build.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tools/espota.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tools/get.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/arduino/hardware/espressif/esp8266/tools/platformio-build.py

.include <bsd.port.mk>
