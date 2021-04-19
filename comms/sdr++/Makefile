# $OpenBSD: $

COMMENT =	bloat-free software defined radio software

V =		0.3.0
DISTNAME =	sdr++-${V}

GH_ACCOUNT =	AlexandreRouma
GH_PROJECT =	SDRPlusPlus
GH_COMMIT =	bdce551a5025e0a39752e8f7b12e4ca5f6e32267

CATEGORIES =	comms

HOMEPAGE =	https://github.com/AlexandreRouma/SDRPlusPlus

# GPLv3+
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} GL GLEW GLU SoapySDR X11 Xext Xi
WANTLIB += Xmu ad9361 airspy airspyhf c fftw3f glfw hackrf iio
WANTLIB += jack m rtaudio rtlsdr volk

COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake

BUILD_DEPENDS =	math/fftw3
LIB_DEPENDS =	audio/rtaudio \
		comms/airspy \
		comms/airspyhf \
		comms/gnuradio \
		comms/hackrf \
		comms/rtl-sdr \
		comms/soapy-sdr \
		graphics/glew \
		graphics/glfw \
		sysutils/libad9361 \
		sysutils/libiio

CONFIGURE_ENV =	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>
