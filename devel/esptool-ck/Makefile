# $OpenBSD$

V =			0.4.13
DISTNAME =		esptool-ck-${V}
COMMENT =		firmware creation helper for esp8266 chips
CATEGORIES =		devel

HOMEPAGE =		https://github.com/igrr/esptool-ck

MASTER_SITES =		https://github.com/igrr/esptool-ck/archive/${V}/

MAINTAINER =            Tracey Emery <tracey@traceyemery.net>

#GPLv2
PERMIT_PACKAGE_CDROM =	Yes

NO_TEST =		Yes

USE_GMAKE =		Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esptool ${PREFIX}/bin

.include <bsd.port.mk>
