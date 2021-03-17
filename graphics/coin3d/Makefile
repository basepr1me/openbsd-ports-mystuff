# $OpenBSD$
USE_NINJA =		No
COMMENT =		3D graphics library

V =			4.0.0
DISTNAME =		coin
PKGNAME =		coin-${V}

#SHARED_LIBS +=		med		0.0 # 11.0

CATEGORIES =		graphics

HOMEPAGE =		https://github.com/coin3d/coin

MAINTAINER =		Paco Esteban <paco@openbsd.org>

# BSD3
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} GL GLU ICE SM X11 Xext m

# DISTFILES =		coin-${V}-src${EXTRACT_SUFX}
DISTFILES =		coin-latest-src${EXTRACT_SUFX}

# MASTER_SITES =	https://github.com/coin3d/coin/releases/download/Coin-${V}/
MASTER_SITES =	https://github.com/coin3d/coin/releases/download/CI-builds/

#WANTLIB +=		${COMPILER_LIBCXX} c hdf5 m z

COMPILER =		base-clang ports-gcc

MODULES =		devel/cmake

LIB_DEPENDS =		devel/boost

CONFIGURE_ARGS =	-Hcoin -G "Unix Makefiles" \
			-DCMAKE_INSTALL_PREFIX=${LOCALBASE} \
			-DCMAKE_BUILD_TYPE=Release \
			-DCOIN_BUILD_DOCUMENTATION=OFF

SEPARATE_BUILD =	Yes
.include <bsd.port.mk>
