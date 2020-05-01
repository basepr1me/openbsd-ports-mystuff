# $OpenBSD$

COMMENT =		keyboard firmware for Atmel AVR and Arm USB families

GH_ACCOUNT =		qmk
GH_PROJECT =		qmk_firmware
GH_TAGNAME =		0.8.139

PKGNAME =		${GH_PROJECT}-${GH_TAGNAME}

CATEGORIES =		devel

#LGPLv2.1
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

RUN_DEPENDS =		archivers/zip \
			archivers/unzip \
			avr/binutils \
			avr/gcc \
			avr/libc \
			comms/dfu-util \
			devel/arm-none-eabi/binutils \
			devel/arm-none-eabi/gcc-linaro \
			devel/arm-none-eabi/newlib \
			devel/dfu-programmer \
			devel/git \
			devel/gmake \
			devel/py-appdirs${MODPY_FLAVOR} \
			devel/py-argcomplete${MODPY_FLAVOR} \
			devel/py-colorama${MODPY_FLAVOR} \
			devel/py-hjson${MODPY_FLAVOR} \
			lang/gcc \
			net/wget \
			textproc/gdiff


USE_GMAKE =		Yes

NO_BUILD =		Yes
NO_TEST =		Yes

.include <bsd.port.mk>
