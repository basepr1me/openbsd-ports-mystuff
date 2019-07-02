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

RUN_DEPENDS +=		devel/esptool-ck \
			devel/esptool-py \
			devel/mkspiffs

MODULES =		lang/python

WRKDIST =		${WRKDIR}/arduino-esp32-1.0.2
WRKSRC =		${WRKDIST}
INSTALLDIR =		${PREFIX}/share/arduino/hardware/espressif/esp32
SPIFFSDIR =		tools/mkspiffs
ESPTOOLDIR =		tools/esptool
LNPRE =			xtensa-esp32-elf
XTENSAPRE =		xtensa-esp32-elf
XTENSADIR =		tools/${XTENSAPRE}/bin

do-install:
	@mkdir -p ${INSTALLDIR}
	@mkdir -p ${INSTALLDIR}/${SPIFFSDIR}
	@mkdir -p ${INSTALLDIR}/${ESPTOOLDIR}
	@mkdir -p ${INSTALLDIR}/${XTENSADIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}
	@ln -s ${LOCALBASE}/bin/esptool ${INSTALLDIR}/${ESPTOOLDIR}/esptool
	@ln -s ${LOCALBASE}/bin/esptool.py \
	    ${INSTALLDIR}/${ESPTOOLDIR}/esptool.py
	@ln -s ${LOCALBASE}/bin/mkspiffs ${INSTALLDIR}/${SPIFFSDIR}/mkspiffs
# @cd ${WRKINST}/${LOCALBASE}/share/espressif/esp32/libraries && \
# 	git clone https://github.com/VSChina/ESP32_AzureIoT_Arduino.git \
# 		AzureIoT

# BINFILES =	addr2line ar as c++ c++filt cpp elfedit g++ gcc gcc-8.2.0 \
# 		gcc-ar gcc-nm gcc-ranlib gcov gcov-tool gprof ld ld.bfd nm \
# 		objcopy objdump ranlib readelf size strings strip

# post-install:
# .for i in ${BINFILES}
# 	@ln -s ${LOCALBASE}/bin/${LNPRE}-${i} \
# 	    ${INSTALLDIR}/${XTENSADIR}/${XTENSAPRE}-${i}
# .endfor

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
