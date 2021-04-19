# $OpenBSD: $

COMMENT =	software defined radio for the HF and VHF bands

V =		1.6.8
DISTNAME =	airspyhf-${V}

GH_ACCOUNT =	airspy
GH_PROJECT =	airspyhf
GH_TAGNAME =	${V}

SHARED_LIBS +=  airspyhf                       0.0 # 1.6.8

CATEGORIES =	comms

HOMEPAGE =	https://github.com/airspy/airspyhf

# BSD 3-Clause
PERMIT_PACKAGE =	Yes

WANTLIB += c m pthread usb-1.0

COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake

LIB_DEPENDS =	devel/libusb1

.include <bsd.port.mk>
