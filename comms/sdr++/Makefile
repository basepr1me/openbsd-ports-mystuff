# $OpenBSD: $

COMMENT =	bloat-free software defined radio software

V =		0.2.5
DISTNAME =	sdr++-${V}

GH_ACCOUNT =	AlexandreRouma
GH_PROJECT =	SDRPlusPlus
GH_COMMIT =	bdce551a5025e0a39752e8f7b12e4ca5f6e32267

CATEGORIES =	comms

HOMEPAGE =	https://github.com/AlexandreRouma/SDRPlusPlus

# GPLv3+
PERMIT_PACKAGE =	Yes

MODULES =	devel/cmake

BUILD_DEPENDS =	audio/rtaudio \
		comms/airspyhf \
		comms/hackrf \
		comms/rtl-sdr \
		comms/soapy-sdr \
		graphics/glew \
		graphics/glfw \
		math/fftw3 \
		sysutils/libad9361 \
		sysutils/libiio

# CONFIGURE_ARGS +=	-DINSTALL_PREFIX="${PREFIX}"

.include <bsd.port.mk>
