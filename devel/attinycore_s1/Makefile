COMMENT =	Arduino core for modern ATtiny 1 series chips

V =		0.0.7
DISTNAME =	TinyCore-${V}
PKGNAME =	attinycore-s1-${V}

CATEGORIES =	devel

MAINTAINER =	Tracey Emery <tracey@openbsd.org>

# MIT
PERMIT_PACKAGE = Yes

MASTER_SITES =	https://github.com/xukangmin/TinyCore/releases/download/${V}/

EXTRACT_SUFX =	.zip

RUN_DEPENDS +=	devel/arduino

INSTALLDIR =	${PREFIX}/share/arduino/hardware/ATTinyCore_S1

NO_TEST =	Yes
NO_BUILD =	Yes

WRKSRC=		${WRKDIR}/avr

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKSRC}/* ${INSTALLDIR}

.include <bsd.port.mk>
