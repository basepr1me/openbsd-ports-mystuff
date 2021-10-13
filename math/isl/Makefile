# $OpenBSD$

COMMENT =	manipulate integer points bounded by linear constraints

VERSION =	0.18
DISTNAME =	isl-${VERSION}

CATEGORIES =	math

SHARED_LIBS +=  isl                       0.0 # 18.0

#MIT
PERMIT_PACKAGE =	Yes

WANTLIB += gmp

MASTER_SITES =		https://gcc.gnu.org/pub/gcc/infrastructure/
EXTRACT_SUFX =		.tar.bz2

LIB_DEPENDS =		devel/gmp

SEPERATE_BUILD =	Yes
USE_GMAKE =		Yes

CONFIGURE_STYLE ?=	gnu
CONFIGURE_ARGS +=	--with-gmp-prefix="${LOCALBASE}"

.include <bsd.port.mk>
