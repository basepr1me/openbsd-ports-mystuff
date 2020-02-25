# $OpenBSD$

COMMENT =		tool to build and unpack SPIFFS images
V =			0.2.3

GH_ACCOUNT =		igrr
GH_PROJECT =		mkspiffs
GH_TAGNAME =		${V}

DISTFILES =		${GH_PROJECT}-${V}.tar.gz

SPFS_V =		f5e26c4e933189593a71c6b82cda381a7b21e41c
DISTFILES +=     	spiffs-${SPFS_V:C/(........).*/\1/}{${SPFS_V}}.tar.gz:0

CATEGORIES =		devel

MASTER_SITES0 = 	https://github.com/pellepl/spiffs/archive/

WANTLIB += c m

#MIT both mkspiffs and spiffs
PERMIT_PACKAGE =	Yes

COMPILER =		ports-clang

MAKE_FLAGS =		VERSION=${V}
MAKE_FLAGS +=		SPIFFS_VERSION=${SPFS_V}

USE_GMAKE =		Yes

NO_TEST =		Yes

post-extract:
	rmdir ${WRKSRC}/spiffs
	mv ${WRKDIR}/spiffs-* ${WRKSRC}/spiffs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkspiffs ${PREFIX}/bin

.include <bsd.port.mk>
