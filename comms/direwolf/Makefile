# $OpenBSD: $

COMMENT =	software soundcard for AX.25 packets

V =		1.6
DISTNAME =	direwolf-${V}

GH_ACCOUNT =	wb2osz
GH_PROJECT =	direwolf
GH_TAGNAME =	${V}

CATEGORIES =	comms

HOMEPAGE =	https://packet-radio.net/direwolf/

MAINTAINER =	Tracey Emery <tracey@openbsd.org>

#LGPLv2
PERMIT_PACKAGE =	Yes

WANTLIB += c hamlib m portaudio pthread

MODULES =	devel/cmake

RUN_DEPENDS =	devel/desktop-file-utils

LIB_DEPENDS =	audio/portaudio-svn \
		comms/hamlib

.include <bsd.port.mk>
