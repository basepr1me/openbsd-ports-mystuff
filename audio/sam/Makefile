# $OpenBSD$

COMMENT =		software automatic mouth tiny speech synthesizer
V =			0.1
DISTNAME =		${V}
PKGNAME =		sam-${V}

CATEGORIES =		audio

#no license
PERMIT_PACKAGE =	No

MASTER_SITES =		https://github.com/basepr1me/SAM/archive/

# gnu++11
COMPILER =		ports-clang ports-gcc

USE_GMAKE =		Yes

NO_TEST =		Yes

WRKDIST =		${WRKDIR}/SAM-${V}

ALL_TARGET =		sam

do-install:
	cp -r ${WRKSRC}/sam ${PREFIX}/bin/
	chown -R ${BINOWN}:${BINGRP} ${PREFIX}/bin/sam

.include <bsd.port.mk>
