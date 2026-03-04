COMMENT =	build and flash tool for the Raspberry Pi Pico

GH_ACCOUNT =	raspberrypi
GH_PROJECT =	picotool
GH_TAGNAME =	2.2.0
PKGNAME =	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}

CATEGORIES =	devel

MAINTAINER =	Tracey Emery <tracey@openbsd.org>

# BSD-3
PERMIT_PACKAGE = Yes

WANTLIB += ${COMPILER_LIBCXX} c m usb-1.0

MODULES =		devel/cmake

BUILD_DEPENDS +=	devel/raspberrypi-pico-sdk

LIB_DEPENDS +=		devel/libusb1

CONFIGURE_ARGS +=	-DPICO_SDK_PATH="${LOCALBASE}/raspberrypi-pico-sdk"

.include <bsd.port.mk>
