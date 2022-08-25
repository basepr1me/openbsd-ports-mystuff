COMMENT =	software development kit for the Raspberry Pi Pico

GH_ACCOUNT =	raspberrypi
GH_PROJECT =	pico-sdk
GH_TAGNAME =	1.4.0

CATEGORIES =	devel

MAINTAINER =	Tracey Emery <tracey@openbsd.org>

# BSD-3
PERMIT_PACKAGE = Yes

MODULES =	lang/python

RUN_DEPENDS +=	devel/arm-none-eabi/gcc-linaro \
		devel/arm-none-eabi/newlib \
		devel/arm-none-eabi/gdb

MASTER_SITES0 = https://github.com/georgerobotics/cyw43-driver/archive/
MASTER_SITES1 = https://github.com/lwip-tcpip/lwip/archive/
MASTER_SITES2 = https://github.com/hathach/tinyusb/archive/

CYW43_V =	195dfcc10bb6f379e3dea45147590db2203d3c7b
LWIP_V =	239918ccc173cb2c2a62f41a40fd893f57faf1d6
TUSB_V =	4bfab30c02279a0530e1a56f4a7c539f2d35a293

DISTFILES =	${GH_PROJECT}-${GH_TAGNAME}.tar.gz
DISTFILES +=	cyw43-${CYW43_V:C/(........).*/\1/}{${CYW43_V}}.tar.gz:0
DISTFILES +=	lwip-${LWIP_V:C/(........).*/\1/}{${LWIP_V}}.tar.gz:1
DISTFILES +=	tinyusb-${TUSB_V:C/(........).*/\1/}{${TUSB_V}}.tar.gz:2
INSTALLDIR =	${PREFIX}/include/raspberrypi-pico-sdk

NO_TEST =	Yes
NO_BUILD =	Yes

post-extract:
	rmdir ${WRKSRC}/lib/cyw43-driver
	mv ${WRKDIR}/cyw43* \
		${WRKSRC}/lib/cyw43-driver
	rmdir ${WRKSRC}/lib/lwip
	mv ${WRKDIR}/lwip* \
		${WRKSRC}/lib/lwip
	rmdir ${WRKSRC}/lib/tinyusb
	mv ${WRKDIR}/tinyusb* \
		${WRKSRC}/lib/tinyusb

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKSRC}/* ${INSTALLDIR}

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
	    ${PREFIX}/include/raspberrypi-pico-sdk

.include <bsd.port.mk>
