COMMENT =	Arduino core for modern ATtiny series 0/1/2 chips

GH_ACCOUNT =	SpenceKonde
GH_PROJECT =	megaTinyCore
GH_TAGNAME =	2.5.11

PKGNAME =	megatinycore-${GH_TAGNAME}

CATEGORIES =	devel

MAINTAINER =	Tracey Emery <tracey@openbsd.org>

# LGPLv2.1+
PERMIT_PACKAGE = Yes

MODULES =	lang/python

RUN_DEPENDS +=	devel/arduino

INSTALLDIR =	${PREFIX}/share/arduino/hardware/megaTinyCore

NO_TEST =	Yes
NO_BUILD =	Yes

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
	    ${PREFIX}/share/arduino/hardware/megaTinyCore/megaavr/tools

.include <bsd.port.mk>
