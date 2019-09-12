# $OpenBSD$

V =			5.1.4
COMMENT =		language translations for Kicad ${V}
DISTNAME =		kicad-i18n-${V}
CATEGORIES =		cad

HOMEPAGE =		https://github.com/KiCad/kicad-i18n

MASTER_SITES =		https://github.com/KiCad/kicad-i18n/archive/${V}/

#CCA4
PERMIT_PACKAGE =	Yes

COMPILER =		ports-clang

BUILD_SRC =		${WRKSRC}

do-configure:
	@cd ${WRKDBUILD}

pre-build:
	@cd ${WRKBUILD} && \
		mkdir -p tmp/${DISTNAME}/build && \
		cd tmp/${DISTNAME}/build && \
		cmake ${WRKBUILD} && \
		make && \
		cp -r ./* ${WRKBUILD}

.include <bsd.port.mk>
