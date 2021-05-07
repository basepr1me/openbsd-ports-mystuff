# $OpenBSD: $

COMMENT =	software to transmie SSTV and HAMDRM

V =		9.4.4
DISTNAME =	qsstv_${V}
PKGNAME =	qsstv-${V}

CATEGORIES =	comms

HOMEPAGE =	http://users.telenet.be/on4qz/index.html

# GPLv3+
PERMIT_PACKAGE =	Yes

MASTER_SITES =		http://users.telenet.be/on4qz/qsstv/downloads/

# WANTLIB += ${COMPILER_LIBCXX} GL GLEW GLU SoapySDR X11 Xext Xi
# WANTLIB += Xmu ad9361 airspy airspyhf c fftw3f glfw hackrf iio
# WANTLIB += jack m rtaudio rtlsdr volk

# COMPILER =	base-clang ports-gcc

MODULES =	devel/qmake \
		x11/qt5

BUILD_DEPENDS =		comms/hamlib
# BUILD_DEPENDS =	comms/gnuradio
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

# CONFIGURE_ARGS +=	-DGNURADIO_OSMOSDR_INCLUDE_DIR="${LOCALBASE}/include/gnuradio"
# CONFIGURE_ENV =	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
# 		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
# USE_GMAKE =	Yes

# WRKSRC =	${WRKDIST}/qsstv

NO_TEST =	Yes

.include <bsd.port.mk>
