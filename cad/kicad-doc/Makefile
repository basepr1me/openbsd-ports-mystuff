# $OpenBSD$

V =			5.1.4
COMMENT =		documentation for Kicad ${V}
DISTNAME =		kicad-doc-${V}
CATEGORIES =		cad

HOMEPAGE =		https://github.com/KiCad/kicad-doc

MASTER_SITES =		https://github.com/KiCad/kicad-doc/archive/${V}/

#CCA3 and GPLv3 (dual licensed)
PERMIT_PACKAGE =	Yes

COMPILER =		ports-clang

MODULES =		devel/cmake

BUILD_DEPENDS =		devel/gettext \
			fonts/vlgothic \
			textproc/asciidoc \
			textproc/dblatex

.include <bsd.port.mk>
