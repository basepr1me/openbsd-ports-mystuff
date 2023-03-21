COMMENT =	complete ODBC driver manager

DISTNAME =	unixODBC-2.3.11

SHARED_LIBS +=  odbc                      0.0 # 2.0
SHARED_LIBS +=  odbccr                    0.0 # 2.0
SHARED_LIBS +=  odbcinst                  0.0 # 2.0

CATEGORIES =	databases

HOMEPAGE =	https://unixodbc.org

#GPLv2+ LGPL21+
PERMIT_PACKAGE =	Yes

USE_LIBTOOL =		gnu
CONFIGURE_STYLE =	gnu

WANTLIB += c pthread readline

MASTER_SITES = ftp://ftp.unixodbc.org/pub/unixODBC/

SEPARATE_BUILD =	Yes
.include <bsd.port.mk>
