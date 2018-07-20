# $OpenBSD$

V =			1.0.0-rc3
DISTNAME =		arduino-esp32-${V}
COMMENT =		esp32 arduino toolset
CATEGORIES =		devel

HOMEPAGE =		https://github.com/espressif/arduino-esp32

MASTER_SITES =		https://github.com/espressif/arduino-esp32/archive/${V}/

MAINTAINER =            Tracey Emery <tracey@traceyemery.net>

#GPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

NO_TEST =		Yes

NO_BUILD =		Yes

BUILD_DEPENDS =		devel/git

RUN_DEPENDS +=		devel/arduino \
			devel/esptool-ck \
			devel/esptool-py \
			devel/mkspiffs \
			devel/xtensa-esp32-elf

WRKDIST =		${WRKDIR}/arduino-esp32-1.0.0-rc3
WRKSRC =		${WRKDIST}
INSTALLDIR =		${PREFIX}/share/espressif/esp32
SPIFFSDIR =		tools/mkspiffs
ESPTOOLDIR =		tools/esptool
XTENSAPRE =		xtensa-esp32-elf
XTENSADIR =		tools/${XTENSAPRE}/bin

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

BINFILES = ${XTENSAPRE}-addr2line ${XTENSAPRE}-cc ${XTENSAPRE}-gcc \
	   ${XTENSAPRE}-gcov ${XTENSAPRE}-ld.bfd ${XTENSAPRE}-readelf \
	   ${XTENSAPRE}-ar ${XTENSAPRE}-cpp ${XTENSAPRE}-gcc-5.2.0 \
	   ${XTENSAPRE}-gcov-tool ${XTENSAPRE}-nm ${XTENSAPRE}-size \
	   ${XTENSAPRE}-as ${XTENSAPRE}-ct-ng.config ${XTENSAPRE}-gcc-ar \
	   ${XTENSAPRE}-gdb ${XTENSAPRE}-objcopy ${XTENSAPRE}-strings \
	   ${XTENSAPRE}-c++ ${XTENSAPRE}-elfedit ${XTENSAPRE}-gcc-nm \
	   ${XTENSAPRE}-gprof ${XTENSAPRE}-objdump ${XTENSAPRE}-strip \
	   ${XTENSAPRE}-c++filt ${XTENSAPRE}-g++ ${XTENSAPRE}-gcc-ranlib \
	   ${XTENSAPRE}-ld ${XTENSAPRE}-ranlib

post-install:
.for i in ${BINFILES}
	@ln -s ${LOCALBASE}/bin/${i} ${INSTALLDIR}/${XTENSADIR}/${i}
.endfor
	@ln -s ${LOCALBASE}/bin/esptool ${INSTALLDIR}/${ESPTOOLDIR}/esptool
	@ln -s ${LOCALBASE}/bin/esptool.py ${INSTALLDIR}/${ESPTOOLDIR}/esptool.py
	@ln -s ${LOCALBASE}/bin/mkspiffs ${INSTALLDIR}/${SPIFFSDIR}/mkspiffs

.include <bsd.port.mk>
