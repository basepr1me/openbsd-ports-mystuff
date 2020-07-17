# $OpenBSD$

COMMENT =		arduino core for modern attiny chips

GH_ACCOUNT =		SpenceKonde
GH_PROJECT =		ATTinyCore
GH_TAGNAME =		1.4

PKGNAME =		attinycore-${GH_TAGNAME}

CATEGORIES =		devel

# LGPLv3+
PERMIT_PACKAGE =	Yes

RUN_DEPENDS +=		devel/arduino

INSTALLDIR =		${PREFIX}/share/arduino/hardware/ATTinyCore/avr

NO_TEST =		Yes
NO_BUILD =		Yes

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}

.include <bsd.port.mk>
