# $OpenBSD$

COMMENT =		ngspice shared library, based on Berkeley SPICE

V =			30
DISTNAME =		ngspice-${V}
PKGNAME =		libngspice-${V}

SHARED_LIBS +=		ngspice			0.0 # 0.0

CATEGORIES =		cad

HOMEPAGE =		http://ngspice.sourceforge.net/

MAINTAINER =		Anthony J. Bentley <anthony@anjbe.name>

# BSD
PERMIT_PACKAGE =	Yes

COMPILER =		ports-clang

RUN_DEPENDS =		cad/ngspice

USE_GMAKE =		yes
CONFIGURE_STYLE =	gnu
WANTLIB +=		c m ICE SM X11 Xau Xaw Xdmcp Xext Xmu Xt
WANTLIB +=		Xpm xcb
WANTLIB +=		pthread

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=ngspice/}

CONFIGURE_ARGS +=	--with-ngshared \
			--enable-xspice \
 			--enable-cider

.include <bsd.port.mk>
