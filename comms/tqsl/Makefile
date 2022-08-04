# $OpenBSD$

COMMENT =	support digital signatures for Amateur radio QSL information
DISTNAME =	tqsl-2.5.9
CATEGORIES =	comms

HOMEPAGE =	https://lotw.arrl.org/lotw-help/
MAINTAINER =	Tracey Emery <tracey@openbsd.org>

# BSD License
PERMIT_PACKAGE = Yes

MASTER_SITES =	http://www.arrl.org/tqsl/

MODULES =	devel/cmake

# BUILD_DEPENDS =	security/openssl

CFLAGS +=	-Wno-builtin-macro-redefined
.include <bsd.port.mk>
