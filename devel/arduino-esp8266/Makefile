# $OpenBSD$

V =			2.4.1
DISTNAME =		arduino-esp8266-${V}
COMMENT =		esp8266 arduino toolset
CATEGORIES =		devel

HOMEPAGE =		https://github.com/esp8266/Arduino

MASTER_SITES =		https://github.com/esp8266/Arduino/archive/${V}/

MAINTAINER =            Tracey Emery <tracey@traceyemery.net>

#GPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

NO_TEST =		Yes

NO_BUILD =		Yes

RUN_DEPENDS +=		devel/arduino \
			devel/esptool-ck \
			devel/esptool-py \
			devel/mkspiffs \
			devel/xtensa-lx106-elf

WRKDIST =		${WRKDIR}/Arduino-2.4.1
WRKSRC =		${WRKDIST}
INSTALLDIR =		${PREFIX}/share/espressif/esp8266
SPIFFSDIR =		tools/mkspiffs
ESPTOOLDIR =		tools/esptool
XTENSADIR =		tools/xtensa-lx106-elf/bin

pre-install:
	@rm ${WRKSRC}/cores/esp8266/core_esp8266_sigma_delta.c.unused

do-install:
	@mkdir -p ${INSTALLDIR}
	@mkdir -p ${INSTALLDIR}/${SPIFFSDIR}
	@mkdir -p ${INSTALLDIR}/${ESPTOOLDIR}
	@mkdir -p ${INSTALLDIR}/${XTENSADIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}

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
	@ln -s ${LOCALBASE}/bin/esptool ${INSTALLDIR}/${ESPTOOLDIR}/esptool
	@ln -s ${LOCALBASE}/bin/esptool.py ${INSTALLDIR}/${ESPTOOLDIR}/esptool.py
	@ln -s ${LOCALBASE}/bin/mkspiffs ${INSTALLDIR}/${SPIFFSDIR}/mkspiffs

.include <bsd.port.mk>
