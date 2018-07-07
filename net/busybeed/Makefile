# $OpenBSD$

V =		1.04
COMMENT =	device packet subscription and routing for OpenBSD
DISTNAME =	busybeed-${V}
CATEGORIES =	net

HOMEPAGE =	https://github.com/spoollord/busybeed/
MAINTAINER =	Tracey Emery <tracey@traceyemery.net>

# ISC
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += c pthread util event

MASTER_SITES =	https://github.com/spoollord/busybeed/releases/download/v${V}/

MAKE_FLAGS =	CC="${CC}"

NO_TEST =	Yes

do-configure:
	sed -i 's,/etc/busybeed.conf,${SYSCONFDIR}/busybeed.conf,' \
		${WRKSRC}/src/busybeed.{h,8,conf.5}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/busybeed
	${INSTALL_DATA} ${WRKSRC}/src/examples/etc/busybeed.conf \
		${PREFIX}/share/examples/busybeed

.include <bsd.port.mk>
