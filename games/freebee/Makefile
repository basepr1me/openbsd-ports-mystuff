# $OpenBSD: $

V =		1.1
COMMENT =	free clone of The New Your Times game Spelling Bee
DISTNAME =	freebee-${V}
CATEGORIES =	games

HOMEPAGE =	http://freebee.fun
MAINTAINER =	Tracey Emery <tracey@openbsd.org>

# ISC
PERMIT_PACKAGE =	Yes

WANTLIB +=	c curl curses

MASTER_SITES =	https://github.com/ibara/freebee/releases/download/${DISTNAME}/

EXTRACT_SUFX =	.tar.xz

LIB_DEPENDS =	net/curl

NO_TEST =	Yes

.include <bsd.port.mk>
