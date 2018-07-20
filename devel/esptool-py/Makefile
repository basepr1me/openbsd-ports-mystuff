# $OpenBSD$

V =			2.4.1
DISTNAME =		esptool-py-${V}
COMMENT =		esp8266 and esp32 rom bootloader communication tool
CATEGORIES =		devel

HOMEPAGE =		https://github.com/espressif/esptool

MASTER_SITES =		https://github.com/espressif/esptool/archive/v${V}/

MAINTAINER =            Tracey Emery <tracey@traceyemery.net>

#GPLv2
PERMIT_PACKAGE_CDROM =	Yes

NO_TEST =		Yes

NO_BUILD =		Yes

RUN_DEPENDS +=		devel/py-serial

PYFILES =		espefuse.py espsecure.py esptool.py

WRKDIST =		${WRKDIR}/esptool-${V}

do-install:
.for i in ${PYFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} \
		${PREFIX}/bin
.endfor

.include <bsd.port.mk>
