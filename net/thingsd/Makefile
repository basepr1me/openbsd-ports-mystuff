# $OpenBSD$

V =			2.3
COMMENT =		things proxy daemon for OpenBSD
DISTNAME =		thingsd-${V}
CATEGORIES =		net

HOMEPAGE =		https://github.com/basepr1me/thingsd/
MAINTAINER =		Tracey Emery <tracey@traceyemery.net>

# ISC
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB +=		c pthread util event crypto ssl tls

MASTER_SITES =		https://github.com/basepr1me/thingsd/archive/v${V}/

MAKE_FLAGS =		CC="${CC}"

NO_TEST =		Yes

do-configure:
	sed -i 's,/etc/thingsd.conf,${SYSCONFDIR}/thingsd.conf,' \
		${WRKSRC}/thingsd/thingsd.{h,8,conf.5}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/thingsd
	${INSTALL_DATA} ${WRKSRC}/thingsd/examples/etc/thingsd.conf \
		${PREFIX}/share/examples/thingsd

.include <bsd.port.mk>
