# $OpenBSD: Makefile,v 1.7 2021/02/23 19:39:12 sthen Exp $

COMMENT =	esp8266 arduino core toolset
V =		3.0.2
DISTNAME =	esp8266-${V}
PKGNAME =	arduino-${DISTNAME}

CATEGORIES =	devel

MAINTAINER =	Tracey Emery <tracey@openbsd.org>

#LGPLv2.1, MIT, BSD, Zlib
PERMIT_PACKAGE =	Yes

MASTER_SITES = https://github.com/esp8266/Arduino/releases/download/${V}/
EXTRACT_SUFX =		.zip

MODULES =		lang/python

RUN_DEPENDS +=		devel/arduino \
			devel/esptool-ck \
			devel/py-esptool${MODPY_FLAVOR} \
			devel/mkspiffs

INSTALLDIR =		${PREFIX}/share/arduino/hardware/espressif/esp8266

NO_TEST =		Yes

pre-build:
	${SUBST_CMD} ${WRKDIST}/platform.txt

do-build:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}
	@cd ${INSTALLDIR}/tools/sdk && mkdir libc && cd libc && \
	    ln -s ../../../../../../../../xtensa-lx106-elf xtensa-lx106-elf

.include <bsd.port.mk>
