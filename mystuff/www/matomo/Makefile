# $OpenBSD$

V =			3.11.0
DISTNAME =		matomo-${V}
COMMENT =		liberating web analytics
CATEGORIES =		www

HOMEPAGE =		https://matomo.org/

GH_ACCOUNT =		matomo-org
GH_PROJECT =		matomo
GH_TAGNAME =		${V}

#LGPLv3
PERMIT_PACKAGE =	Yes

NO_TEST =		Yes
NO_BUILD =		Yes

INSTALLDIR =		${VARBASE}/www/htdocs/${DISTNAME}

do-install:
	${INSTALL_DATA_DIR} ${WRKSRC} ${INSTALLDIR}
	@cp -r ${WRKSRC}/* ${INSTALLDIR}

.include <bsd.port.mk>
