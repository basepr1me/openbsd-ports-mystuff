# $OpenBSD$

V =			0.4.14
DISTNAME =		esptool-ck-${V}
COMMENT =		firmware creation helper for esp8266 chips
CATEGORIES =		devel

HOMEPAGE =		https://github.com/basepr1me/esptool-ck

MASTER_SITES =		https://github.com/basepr1me/esptool-ck/archive/${V}/

#GPLv2
PERMIT_PACKAGE =	Yes

NO_TEST =		Yes

WANTLIB += c

USE_GMAKE =		Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esptool ${PREFIX}/bin

.include <bsd.port.mk>
