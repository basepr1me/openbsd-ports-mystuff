# $OpenBSD$

V =			1.0.0-rc3
DISTNAME =		arduino-esp32-${V}
COMMENT =		esp8266 arduino toolset
CATEGORIES =		devel

HOMEPAGE =		https://github.com/espressif/arduino-esp32

MASTER_SITES =		https://github.com/espressif/arduino-esp32/archive/${V}/

#GPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

NO_TEST =		Yes

NO_BUILD =		Yes

BUILD_DEPENDS =		devel/git

RUN_DEPENDS +=		devel/arduino \
			devel/esptool-ck \
			devel/esptool-py \
			devel/mkspiffs \
			devel/xtensa-lx106-elf-g++

WRKDIST =		${WRKDIR}/arduino-esp32-1.0.0-rc3
WRKSRC =		${WRKDIST}
INSTALLDIR =		${PREFIX}/share/espressif/esp32
SPIFFSDIR =		tools/mkspiffs
ESPTOOLDIR =		tools/esptool
XTENSADIR =		tools/xtensa-lx106-elf/bin

do-install:
	@mkdir -p ${INSTALLDIR}
	@mkdir -p ${INSTALLDIR}/${SPIFFSDIR}
	@mkdir -p ${INSTALLDIR}/${ESPTOOLDIR}
	@mkdir -p ${INSTALLDIR}/${XTENSADIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}
	@cd ${WRKINST}/${LOCALBASE}/share/espressif/esp32/libraries && \
		git clone https://github.com/VSChina/ESP32_AzureIoT_Arduino.git \
			AzureIoT && \
		git clone https://github.com/nkolban/ESP32_BLE_Arduino.git BLE

BINFILES =	xtensa-lx106-elf-addr2line xtensa-lx106-elf-c++filt \
		xtensa-lx106-elf-elfedit xtensa-lx106-elf-gcc-ar \
		xtensa-lx106-elf-gdb xtensa-lx106-elf-nm \
		xtensa-lx106-elf-readelf xtensa-lx106-elf-ar \
		xtensa-lx106-elf-cc xtensa-lx106-elf-g++ \
		xtensa-lx106-elf-gcc-nm xtensa-lx106-elf-gprof \
		xtensa-lx106-elf-objcopy xtensa-lx106-elf-size \
		xtensa-lx106-elf-as xtensa-lx106-elf-cpp \
		xtensa-lx106-elf-gcc xtensa-lx106-elf-gcc-ranlib \
		xtensa-lx106-elf-ld xtensa-lx106-elf-objdump \
		xtensa-lx106-elf-strings xtensa-lx106-elf-c++ \
		xtensa-lx106-elf-ct-ng.config xtensa-lx106-elf-gcc-4.8.2 \
		xtensa-lx106-elf-gcov xtensa-lx106-elf-ld.bfd \
		xtensa-lx106-elf-ranlib xtensa-lx106-elf-strip

post-install:
.for i in ${BINFILES}
	@ln -s ${LOCALBASE}/bin/${i} ${INSTALLDIR}/${XTENSADIR}/${i}
.endfor
	@ln -s ${LOCALBASE}/bin/esptool.py ${INSTALLDIR}/${ESPTOOLDIR}/esptool.py
	@ln -s ${LOCALBASE}/bin/${i} ${INSTALLDIR}/${SPIFFSDIR}/mkspiffs

.include <bsd.port.mk>
