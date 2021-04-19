# $OpenBSD: $

COMMENT =	simple library used for userspace

V =		0.2
DISTNAME =	libad9361-${V}

GH_ACCOUNT =	analogdevicesinc
GH_PROJECT =	libad9361-iio
GH_TAGNAME =	v${V}

SHARED_LIBS +=  ad9361                       0.0 # 0.2

CATEGORIES =	sysutils

HOMEPAGE =	https://github.com/analogdevicesinc/libad9361-iio

# LGPLv2+
PERMIT_PACKAGE =	Yes

WANTLIB += iio m

COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake

LIB_DEPENDS =	sysutils/libiio

.include <bsd.port.mk>
