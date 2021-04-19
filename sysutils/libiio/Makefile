# $OpenBSD: $

COMMENT =	library for interfacing with Linux IIO devices

V =		0.21
DISTNAME =	libiio-${V}

GH_ACCOUNT =	analogdevicesinc
GH_PROJECT =	libiio
GH_TAGNAME =	${V}

SHARED_LIBS +=  iio                       0.0 # 0.21

CATEGORIES =	sysutils

HOMEPAGE =	https://github.com/analogdevicesinc/libiio

# LGPLv2+/GPLv2+
PERMIT_PACKAGE =	Yes

WANTLIB += avahi-client avahi-common c iconv lzma m pthread usb-1.0
WANTLIB += xml2 z

COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake

LIB_DEPENDS =	archivers/xz \
		converters/libiconv \
		devel/libusb1 \
		net/avahi \
		textproc/libxml

CONFIGURE_ARGS +=	-DCMAKE_INSTALL_PREFIX="${PREFIX}"

.include <bsd.port.mk>
