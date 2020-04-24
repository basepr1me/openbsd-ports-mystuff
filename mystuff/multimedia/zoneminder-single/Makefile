# $OpenBSD:$

COMMENT =	security camera DVR/NVR recorder/alarm monitor

V =		1.34.6
DISTFILES =	${V}.tar.gz

GH_ACCOUNT =	ZoneMinder
GH_PROJECT =	zoneminder
GH_TAGNAME =	${V}

PKGNAME =	zoneminder-${V}

CATEGORIES =	multimedia security

HOMEPAGE =	https://zoneminder.com

CAKE_V =	ea90c0cd7f6e24333a90885e563b5d30b793db29
CRUD_V =	0bd63fb464957080ead342db58ca9e01532cf1ef

DISTFILES +=   	cake-${CAKE_V:C/(........).*/\1/}{${CAKE_V}}.tar.gz:0
DISTFILES +=   	crud-${CRUD_V:C/(........).*/\1/}{${CRUD_V}}.tar.gz:1

MASTER_SITES0 = https://github.com/ZoneMinder/CakePHP-Enum-Behavior/archive/
MASTER_SITES1 = https://github.com/ZoneMinder/crud/archive/

WANTLIB += ${COMPILER_LIBCXX} avcodec avdevice avformat avutil
WANTLIB += c crypto curl gcrypt gnutls jpeg m mariadb pcre ssl
WANTLIB += swresample swscale vlc x264 z

# c++11
COMPILER =	base-clang ports-gcc

RUN_DEPENDS = ${BUILD_DEPENDS} \
		databases/mariadb,-server \
		devel/desktop-file-utils \
		${MODPHP_RUN_DEPENDS} \
		lang/php/${MODPHP_VERSION},-mysqli

BUILD_DEPENDS =	converters/p5-DateManip \
		databases/p5-DBI \
		databases/p5-DBD-mysql \
		devel/glib2 \
		devel/cmake \
		devel/p5-Getargs-Long \
		devel/p5-Sys-Mmap \
		devel/p5-Time-TimeDate \
		graphics/ffmpeg \
		www/p5-LWP-UserAgent-Determined

LIB_DEPENDS =	databases/mariadb \
		devel/pcre \
		graphics/ffmpeg \
		graphics/jpeg \
		net/curl \
		security/gnutls \
		security/libgcrypt \
		x11/vlc

# GPLv2
PERMIT_PACKAGE =	Yes

MODULES =		devel/cmake \
			lang/php

PREFIX =		${VARBASE}/www

CONFIGURE_STYLE =	cmake
CONFIGURE_ENV =		CXXFLAGS="-DCMAKE_INSTALL_PREFIX=${PREFIX}"
SEPARATE_BUILD =	Yes
NO_TEST =		Yes


post-extract:
	rmdir ${WRKSRC}/web/api/app/Plugin/CakePHP-Enum-Behavior
	mv ${WRKDIR}/CakePHP-Enum-Behavior-* \
		${WRKSRC}/web/api/app/Plugin/CakePHP-Enum-Behavior
	rmdir ${WRKSRC}/web/api/app/Plugin/Crud
	mv ${WRKDIR}/crud-* ${WRKSRC}/web/api/app/Plugin/Crud

.include <bsd.port.mk>
