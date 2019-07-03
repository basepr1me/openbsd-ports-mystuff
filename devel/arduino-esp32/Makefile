# $OpenBSD$

V =			1.0.2
DISTNAME =		esp32-${V}
COMMENT =		esp32 arduino toolset
CATEGORIES =		devel

HOMEPAGE =		https://github.com/espressif/arduino-esp32

MASTER_SITES =		https://github.com/espressif/arduino-esp32/archive/${V}/

PKGNAME =		arduino-esp32-${V}

#GPLv2.1
PERMIT_PACKAGE =	Yes

NO_TEST =		Yes

NO_BUILD =		Yes

BUILD_DEPENDS =		devel/arduino

RUN_DEPENDS +=		devel/arduino \
			devel/esptool-ck \
			devel/esptool-py \
			devel/mkspiffs

MODULES =		lang/python

WRKDIST =		${WRKDIR}/arduino-esp32-1.0.2
WRKSRC =		${WRKDIST}
INSTALLDIR =		${PREFIX}/share/arduino/hardware/espressif/esp32

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		share/arduino/hardware/espressif/esp32/package/merge_packages.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		share/arduino/hardware/espressif/esp32/tools/build.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		share/arduino/hardware/espressif/esp32/tools/espota.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		share/arduino/hardware/espressif/esp32/tools/esptool.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		share/arduino/hardware/espressif/esp32/tools/esptool/esptool.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		share/arduino/hardware/espressif/esp32/tools/gen_esp32part.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		share/arduino/hardware/espressif/esp32/tools/get.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		share/arduino/hardware/espressif/esp32/tools/platformio-build.py
.include <bsd.port.mk>
