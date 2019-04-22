# $OpenBSD$

COMMENT =		language translations for Kicad 5.1.0
V =			5.1.0
DISTNAME =		kicad-i18n-${V}
CATEGORIES =		cad

HOMEPAGE =		https://github.com/KiCad/kicad-i18n

MASTER_SITES =		https://github.com/KiCad/kicad-i18n/archive/${V}/

#CCA4
PERMIT_PACKAGE_CDROM =	Yes

DIST_SUBDIR =		kicad

LIB_DEPENDS =		devel/gettext

MODULES =		devel/cmake

BUILD_SRC =		${WRKSRC}

post-extract:
	@cd ${WRKSRC} && \
		mkdir -p tmp/${DISTNAME}/build && \
		cd tmp/${DISTNAME}/build && \
		cmake ${BUILD_SRC}

do-build:
	@cd ${WRKSRC}/tmp/${DISTNAME}/build && make && \
		cp -r * ${WRKDIR}/build-amd64

.include <bsd.port.mk>
