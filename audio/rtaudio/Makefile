# $OpenBSD: $

COMMENT =	common API for realtime audio

V =		5.1.0
DISTNAME =	rtaudio-${V}

GH_ACCOUNT =	thestk
GH_PROJECT =	rtaudio
GH_TAGNAME =	${V}

SHARED_LIBS +=  rtaudio                       0.0 # 6.1.0

CATEGORIES =	audio

HOMEPAGE =	https://github.com/thestk/rtaudio

# BSD like
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} jack m

COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake

LIB_DEPENDS =	audio/jack

CONFIGURE_ENV =	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

CONFIGURE_ARGS +=	-DRTAUDIO_API_ALSA="OFF" \
			-DRTAUDIO_API_PULSE="OFF"

.include <bsd.port.mk>
