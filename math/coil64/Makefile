COMMENT =		an inductance coil calculator

GH_ACCOUNT =		radioacoustick
GH_PROJECT =		Coil64
GH_TAGNAME =		v2.1.24

PKGNAME =		${GH_PROJECT}-${GH_TAGNAME:S/v//}

CATEGORIES =		math

HOMEPAGE =		https://coil32.net/

#GPLv3+
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} GL Qt5Core Qt5Gui Qt5Network Qt5PrintSupport
WANTLIB += Qt5Widgets c m

MODULES =		devel/qmake \
			x11/qt5

SEPERATE_BUILD =	Yes

CONFIGURE_STYLE =	qmake

pre-install:
	@mv ${WRKBUILD}/Coil64 ${WRKSRC}

.include <bsd.port.mk>
