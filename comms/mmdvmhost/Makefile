# $OpenBSD: $

COMMENT =	host software for MMDVM

V =		20210408
DISTNAME =	mmdvmhost-${V}

GH_ACCOUNT =	g4klx
GH_PROJECT =	MMDVMHost
GH_COMMIT =	b30d5465f5a6b0f38447763669d84856601cae1e

CATEGORIES =	comms

HOMEPAGE =	https://github.com/g4klx/MMDVMHost

# GPLv2
PERMIT_PACKAGE =	Yes

USE_GMAKE =	Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MMDVMHost ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/RemoteCommand ${PREFIX}/bin

.include <bsd.port.mk>
