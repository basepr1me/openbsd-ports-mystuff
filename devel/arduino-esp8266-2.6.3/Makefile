# $OpenBSD$

V =			2.6.3

DISTNAME =		esp8266-${V}
COMMENT =		esp8266 arduino toolset
CATEGORIES =		devel

PKGNAME =		arduino-esp8266-${V}
HOMEPAGE =		https://github.com/esp8266/Arduino

MASTER_SITES =		https://github.com/esp8266/Arduino/archive/${V}/

#LGPLv2.1
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

BUILD_DEPENDS =		devel/arduino
RUN_DEPENDS +=		devel/arduino \
			devel/esptool-ck \
			devel/py-esptool${MODPY_FLAVOR} \
			devel/mkspiffs \
			devel/xtensa-lx106-elf/gcc-lx106

MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}

WRKDIST =		${WRKDIR}/Arduino-${V}
WRKSRC =		${WRKDIST}
INSTALLDIR =		${PREFIX}/share/arduino/hardware/espressif/esp8266

NO_TEST =		Yes
NO_BUILD =		Yes

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${INSTALLDIR}/doc/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${INSTALLDIR}/package/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${INSTALLDIR}/tools/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${INSTALLDIR}/tests/

.include <bsd.port.mk>
