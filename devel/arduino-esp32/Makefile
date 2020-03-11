# $OpenBSD$

COMMENT =	esp32 arduino core toolset
V =		1.0.4

GH_ACCOUNT =	espressif
GH_PROJECT =	arduino-esp32
GH_TAGNAME =	${V}

DISTFILES =	esp32-${V}.tar.gz

AZURE_V =	67dfa4f31ef88b0938dd87d955612100dea5562e
DISTFILES +=   	ESP32_AzureIoT_Arduino-${AZURE_V:C/(........).*/\1/}{${AZURE_V}}.tar.gz:0

CATEGORIES =	devel

MASTER_SITES0 =	https://github.com/VSChina/ESP32_AzureIoT_Arduino/archive/

#LGPLv2.1, MIT
PERMIT_PACKAGE =	Yes

MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}
MODULES =		lang/python

RUN_DEPENDS +=		devel/arduino \
			devel/py-esptool${MODPY_FLAVOR} \
			devel/mkspiffs \
			devel/xtensa-esp32-elf/gcc

INSTALLDIR =		${PREFIX}/share/arduino/hardware/espressif/esp32

NO_TEST =		Yes
NO_BUILD =		Yes

post-extract:
	@rmdir ${WRKSRC}/libraries/AzureIoT
	@mv ${WRKDIR}/ESP32_AzureIoT_Arduino-* ${WRKSRC}/libraries/AzureIoT

post-patch:
	@sed -i 's,PREFIX,${LOCALBASE},' ${WRKDIST}/platform.txt

do-install:
	@mkdir -p ${INSTALLDIR}
	@cp -r ${WRKDIST}/* ${INSTALLDIR}
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
	 	${PREFIX}/share/arduino/hardware/espressif/esp32/tools/

.include <bsd.port.mk>
