# $OpenBSD$

COMMENT =	manipulate integer points bounded by linear constraints

VERSION =	0.18
DISTNAME =	isl-${VERSION}

CATEGORIES =	math

SHARED_LIBS +=  isl                       0.0 # 18.0
WANTLIB += gmp

#LGLBv2.1+
PERMIT_PACKAGE =	Yes

LIB_DEPENDS =		devel/gmp

MASTER_SITES =		https://gcc.gnu.org/pub/gcc/infrastructure/

EXTRACT_SUFX =		.tar.bz2

CONFIGURE_STYLE ?=	gnu
CONFIGURE_ARGS +=	--with-gmp-prefix="${LOCALBASE}"

USE_GMAKE =		Yes
SEPERATE_BUILD =	Yes

.include <bsd.port.mk>
