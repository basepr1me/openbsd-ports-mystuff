# $OpenBSD: $

COMMENT =	bloat-free software defined radio software

V =		2.14.4
DISTNAME =	gqrx-${V}

GH_ACCOUNT =	csete
GH_PROJECT =	gqrx
GH_TAGNAME =	v${V}

CATEGORIES =	comms

HOMEPAGE =	https://gqrx.dk

# Apache v2.0
PERMIT_PACKAGE =	Yes

# WANTLIB += ${COMPILER_LIBCXX} GL GLEW GLU SoapySDR X11 Xext Xi
# WANTLIB += Xmu ad9361 airspy airspyhf c fftw3f glfw hackrf iio
# WANTLIB += jack m rtaudio rtlsdr volk

COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake \
		x11/qt5

BUILD_DEPENDS =	comms/gnuradio
# BUILD_DEPENDS =	math/fftw3
# LIB_DEPENDS =	audio/rtaudio \
# 		comms/airspy \
# 		comms/airspyhf \
# 		comms/gnuradio \
# 		comms/hackrf \
# 		comms/rtl-sdr \
# 		comms/soapy-sdr \
# 		graphics/glew \
# 		graphics/glfw \
# 		sysutils/libad9361 \
# 		sysutils/libiio

CONFIGURE_ARGS +=	-DGNURADIO_OSMOSDR_INCLUDE_DIR="${LOCALBASE}/include/gnuradio"
CONFIGURE_ENV =	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>
