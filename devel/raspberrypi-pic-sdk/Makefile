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

INSTALLDIR =	${PREFIX}/include/raspberrypi-pico-sdk

NO_TEST =	Yes
NO_BUILD =	Yes

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKSRC}/* ${INSTALLDIR}

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
	    ${PREFIX}/include/raspberrypi-pico-sdk

.include <bsd.port.mk>
