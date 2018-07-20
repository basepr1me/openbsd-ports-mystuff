# $OpenBSD$

V =			0.2.3

DISTNAME =		mkspiffs-${V}
COMMENT =		tool to build and unpack SPIFFS images
CATEGORIES =		devel

MAINTAINER =		Tracey Emery <tracey@traceyemery.net>

GH_ACCOUNT =		igrr
GH_PROJECT =		mkspiffs
GH_TAGNAME =		${V}

BUILD_DEPS =		devel/git

#MIT
PERMIT_PACKAGE_CDROM =	Yes

NO_TEST =		Yes

COMPILER =		ports-gcc \
			ports-clang

USE_GMAKE =		Yes
MAKE_ARGS =		NO_TEST=Yes

pre-configure:
	@cd ${WRKSRC} && git clone https://github.com/pellepl/spiffs.git

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkspiffs ${PREFIX}/bin

.include <bsd.port.mk>
