COMMENT =	software development kit for the Raspberry Pi Pico

GH_ACCOUNT =	raspberrypi
GH_PROJECT =	pico-sdk
GH_TAGNAME =	2.2.0
PKGNAME =	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}

CATEGORIES =	devel

MAINTAINER =	Tracey Emery <tracey@openbsd.org>

# BSD-3
PERMIT_PACKAGE = Yes

MODULES =	lang/python

RUN_DEPENDS +=	devel/arm-none-eabi/binutils,arm \
		devel/arm-none-eabi/gcc,arm \
		devel/arm-none-eabi/newlib,arm

SITES.a = https://github.com/georgerobotics/cyw43-driver/archive/
SITES.b = https://github.com/lwip-tcpip/lwip/archive/
SITES.c = https://github.com/hathach/tinyusb/archive/
SITES.d = https://github.com/bluekitchen/btstack/archive/
SITES.e = https://github.com/Mbed-TLS/mbedtls/archive/
SITES.f = https://github.com/raspberrypi/pico-examples/archive/

CYW43_V =	dd7568229f3bf7a37737b9e1ef250c26efe75b23
LWIP_V =	77dcd25a72509eb83f72b033d219b1d40cd8eb95
TUSB_V =	86ad6e56c1700e85f1c5678607a762cfe3aa2f47
BTSTACK_V =	501e6d2b86e6c92bfb9c390bcf55709938e25ac1
MBEDTLS_V =	107ea89daaefb9867ea9121002fbbdf926780e98
EX_V =		4c3a3dc0196dd426fddd709616d0da984e027bab

DISTFILES =	${GH_PROJECT}-${GH_TAGNAME}.tar.gz
DISTFILES.a +=	cyw43-${CYW43_V:C/(........).*/\1/}{${CYW43_V}}.tar.gz
DISTFILES.b +=	lwip-${LWIP_V:C/(........).*/\1/}{${LWIP_V}}.tar.gz
DISTFILES.c +=	tinyusb-${TUSB_V:C/(........).*/\1/}{${TUSB_V}}.tar.gz
DISTFILES.d +=	btstack-${BTSTACK_V:C/(........).*/\1/}{${BTSTACK_V}}.tar.gz
DISTFILES.e +=	mbedtls-${MBEDTLS_V:C/(........).*/\1/}{${MBEDTLS_V}}.tar.gz
DISTFILES.f +=	pico-examples-${EX_V:C/(........).*/\1/}{${EX_V}}.tar.gz
INSTALLDIR =	${PREFIX}/raspberrypi-pico-sdk

NO_TEST =	Yes
NO_BUILD =	Yes

post-extract:
	rmdir ${WRKSRC}/lib/cyw43-driver
	mv ${WRKDIR}/cyw43* ${WRKSRC}/lib/cyw43-driver
	rmdir ${WRKSRC}/lib/lwip
	mv ${WRKDIR}/lwip* ${WRKSRC}/lib/lwip
	rmdir ${WRKSRC}/lib/tinyusb
	mv ${WRKDIR}/tinyusb* ${WRKSRC}/lib/tinyusb
	rmdir ${WRKSRC}/lib/btstack
	mv ${WRKDIR}/btstack* ${WRKSRC}/lib/btstack
	rmdir ${WRKSRC}/lib/mbedtls
	mv ${WRKDIR}/mbedtls* ${WRKSRC}/lib/mbedtls
	mv ${WRKDIR}/pico-examples* ${WRKSRC}/pico-examples

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKSRC}/* ${INSTALLDIR}

# post-install:
# 	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
# 	    ${PREFIX}/raspberrypi-pico-sdk

.include <bsd.port.mk>
