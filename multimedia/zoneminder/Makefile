# $OpenBSD:$

MULTI_PACKAGES = -main -web
COMMENT-main =	security camera DVR/NVR recorder/alarm monitor
COMMENT-web =	PHP scripts for ZoneMinder

V =		1.34.26

PKGNAME-main =	zoneminder-${V}
PKGNAME-web =	zoneminder-web-${V}

GH_ACCOUNT =	ZoneMinder
GH_PROJECT =	zoneminder
GH_TAGNAME =	${V}

CATEGORIES =	multimedia security

HOMEPAGE =	https://zoneminder.com

MAINTAINER =	Tracey Emery <tracey@openbsd.org>

# GPLv2
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} avcodec avdevice avformat avutil
WANTLIB += c crypto curl gcrypt jpeg m mariadb pcre ssl swresample
WANTLIB += swscale vlc x264 z

MASTER_SITES0 = https://github.com/ZoneMinder/CakePHP-Enum-Behavior/archive/
MASTER_SITES1 = https://github.com/FriendsOfCake/crud/archive/

CAKE_V =	ea90c0cd7f6e24333a90885e563b5d30b793db29
CRUD_V =	14292374ccf1328f2d5db20897bd06f99ba4d938

DISTFILES =	${V}.tar.gz
DISTFILES +=	cake-${CAKE_V:C/(........).*/\1/}{${CAKE_V}}.tar.gz:0
DISTFILES +=	crud-${CRUD_V:C/(........).*/\1/}{${CRUD_V}}.tar.gz:1

# c++11
COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake \
		lang/php

BUILD_DEPENDS =	converters/p5-DateManip \
		databases/p5-DBI \
		databases/p5-DBD-mysql \
		devel/cmake \
		devel/glib2 \
		devel/p5-Getargs-Long \
		devel/p5-Sys-Mmap \
		devel/p5-Time-TimeDate \
		devel/pcre \
		graphics/ffmpeg \
		graphics/jpeg \
		net/curl \
		security/libgcrypt \
		security/gnutls \
		www/p5-LWP-UserAgent-Determined \
		x11/vlc
RUN_DEPENDS-main = ${BUILD_DEPENDS} \
		devel/desktop-file-utils \
		devel/libmpc \
		devel/mpfr \
		devel/p5-Log-Agent \
		multimedia/zoneminder,-web=${V}
RUN_DEPENDS-web = ${BUILD_DEPENDS} \
		databases/mariadb,-server \
		${MODPHP_RUN_DEPENDS} \
		lang/php/${MODPHP_VERSION},-mysqli \
		lang/php/${MODPHP_VERSION},-gd \
		lang/php/${MODPHP_VERSION},-pdo_mysql \
		security/p5-Crypt-Eksblowfish \
		sysutils/p5-Data-Entropy \
		sysutils/p5-Number-Bytes-Human \
		sysutils/p5-Sys-MemInfo \
		security/sudo

CONFIGURE_STYLE =	cmake

SEPARATE_BUILD =	Yes
NO_TEST =		Yes

PREFIX-main =		${LOCALBASE}
PREFIX-web =		${VARBASE}/www

INSTDIR =		${PREFIX-web}

SUBST_VARS =		INSTDIR

post-extract:
	rmdir ${WRKSRC}/web/api/app/Plugin/CakePHP-Enum-Behavior
	mv ${WRKDIR}/CakePHP-Enum-Behavior-* \
		${WRKSRC}/web/api/app/Plugin/CakePHP-Enum-Behavior
	rmdir ${WRKSRC}/web/api/app/Plugin/Crud
	mv ${WRKDIR}/crud-* ${WRKSRC}/web/api/app/Plugin/Crud

post-patch:
	${SUBST_CMD} ${WRKDIST}/CMakeLists.txt

post-install:
	${INSTALL_DATA_DIR} ${WRKINST}${INSTDIR}/zm/cache
	${INSTALL_DATA_DIR} ${WRKINST}${INSTDIR}/zm/logs
	${INSTALL_DATA_DIR} ${WRKINST}${INSTDIR}/zm/run
	${INSTALL_DATA_DIR} ${WRKINST}${INSTDIR}/zm/spool
	${INSTALL_DATA_DIR} ${WRKINST}${INSTDIR}/zm/spool/events
	${INSTALL_DATA_DIR} ${WRKINST}${INSTDIR}/zm/shm
	@chmod -R 1770 ${WRKINST}${INSTDIR}/zm
	@chown -R www:www ${WRKINST}${INSTDIR}/zm ${WRKINST}${INSTDIR}/htdocs/zm
	@touch ${WRKINST}${INSTDIR}/zm/logs/web_php.log
	@cd ${WRKINST}${INSTDIR}/htdocs/zm && ln -s ../../zm/cache cache

.include <bsd.port.mk>
