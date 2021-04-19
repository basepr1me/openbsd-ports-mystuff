# $OpenBSD: $

COMMENT =	tiny and efficient software defined radio

V =		1.0.9.1
DISTNAME =	airspy-${V}

GH_ACCOUNT =	airspy
GH_PROJECT =	airspyone_host
GH_COMMIT =	70520c999eb6612a53def319fc1b044ed1c041d8

SHARED_LIBS +=  airspy                       0.0 # 1.0.9

CATEGORIES =	comms

HOMEPAGE =	https://github.com/airspy/airspyone_host

# BSD 3-Clause
PERMIT_PACKAGE =	Yes

WANTLIB += c pthread usb-1.0

COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake

LIB_DEPENDS =	devel/libusb1

.include <bsd.port.mk>
