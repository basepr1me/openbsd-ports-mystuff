COMMENT =	complete ODBC driver manager

DISTNAME =	unixODBC-2.3.12

SHARED_LIBS +=  odbc                      0.0 # 2.0
SHARED_LIBS +=  odbccr                    0.0 # 2.0
SHARED_LIBS +=  odbcinst                  0.0 # 2.0

CATEGORIES =	databases

HOMEPAGE =	https://unixodbc.org

#GPLv2+ LGPL21+
PERMIT_PACKAGE =	Yes

WANTLIB += c pthread readline

SITES = ftp://ftp.unixodbc.org/pub/unixODBC/

SEPARATE_BUILD =	Yes

USE_LIBTOOL =		gnu
CONFIGURE_STYLE =	gnu

.include <bsd.port.mk>
