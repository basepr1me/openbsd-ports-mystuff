# $OpenBSD$

V =			0.2.3

DISTNAME =		mkspiffs-${V}
COMMENT =		tool to build and unpack SPIFFS images
CATEGORIES =		devel

#requires submodule https://github.com/pellepl/spiffs
MASTER_SITES =		https://packages.traceyemery.net/distfiles/

WANTLIB += c m

#MIT
PERMIT_PACKAGE =	Yes

COMPILER =		ports-clang

MAKE_FLAGS =		VERSION=${V}
MAKE_FLAGS+=		SPIFFS_VERSION=0.3.7-18-gec68ba8

USE_GMAKE =		Yes

NO_TEST =		Yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkspiffs ${PREFIX}/bin

.include <bsd.port.mk>
