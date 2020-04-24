# $OpenBSD$

COMMENT =		attach running process to a new terminal
V =			0.7.0

GH_ACCOUNT =		nelhage
GH_PROJECT =		reptyr
GH_TAGNAME =		${GH_PROJECT}-${V}

CATEGORIES =		sysutils

HOMEPAGE =		https://github.com/nelhage/reptyr

#MIT
PERMIT_PACKAGE =	Yes

# gnu++11
# COMPILER =		ports-clang ports-gcc

# MAKE_FLAGS =		VERSION=${V}
# MAKE_FLAGS +=		SPIFFS_VERSION=${SPFS_V}

USE_GMAKE =		Yes

# NO_TEST =		Yes

# post-extract:
# 	rmdir ${WRKSRC}/spiffs
# 	mv ${WRKDIR}/spiffs-* ${WRKSRC}/spiffs

# do-install:
# 	${INSTALL_PROGRAM} ${WRKSRC}/mkspiffs ${PREFIX}/bin

.include <bsd.port.mk>
