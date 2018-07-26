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
XTENSAPRE =             xtensa-lx106-elf
XTENSADIR =		tools/${XTENSAPRE}/bin

pre-install:
	@rm ${WRKSRC}/cores/esp8266/core_esp8266_sigma_delta.c.unused

do-install:
	@mkdir -p ${INSTALLDIR}
	@mkdir -p ${INSTALLDIR}/${SPIFFSDIR}
	@mkdir -p ${INSTALLDIR}/${ESPTOOLDIR}
	@mkdir -p ${INSTALLDIR}/${XTENSADIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}

BINFILES =	${XTENSAPRE}-addr2line ${XTENSAPRE}-c++filt \
		${XTENSAPRE}-elfedit ${XTENSAPRE}-gcc-ar \
		${XTENSAPRE}-gdb ${XTENSAPRE}-nm \
		${XTENSAPRE}-readelf ${XTENSAPRE}-ar \
		${XTENSAPRE}-cc ${XTENSAPRE}-g++ \
		${XTENSAPRE}-gcc-nm ${XTENSAPRE}-gprof \
		${XTENSAPRE}-objcopy ${XTENSAPRE}-size \
		${XTENSAPRE}-as ${XTENSAPRE}-cpp \
		${XTENSAPRE}-gcc ${XTENSAPRE}-gcc-ranlib \
		${XTENSAPRE}-ld ${XTENSAPRE}-objdump \
		${XTENSAPRE}-strings ${XTENSAPRE}-c++ \
		${XTENSAPRE}-ct-ng.config ${XTENSAPRE}-gcc-4.8.2 \
		${XTENSAPRE}-gcov ${XTENSAPRE}-ld.bfd \
		${XTENSAPRE}-ranlib ${XTENSAPRE}-strip

post-install:
.for i in ${BINFILES}
	@ln -s ${LOCALBASE}/bin/${i} ${INSTALLDIR}/${XTENSADIR}/${i}
.endfor
	@ln -s ${LOCALBASE}/bin/esptool ${INSTALLDIR}/${ESPTOOLDIR}/esptool
	@ln -s ${LOCALBASE}/bin/esptool.py ${INSTALLDIR}/${ESPTOOLDIR}/esptool.py
	@ln -s ${LOCALBASE}/bin/mkspiffs ${INSTALLDIR}/${SPIFFSDIR}/mkspiffs

.include <bsd.port.mk>
