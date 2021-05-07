# $OpenBSD$

V =			4.2.1
COMMENT =		liberating web analytics

DISTNAME =		matomo-${V}

GH_ACCOUNT =		matomo-org
GH_PROJECT =		matomo
GH_TAGNAME =		${V}

CATEGORIES =		www

HOMEPAGE =		https://matomo.org/

#LGPLv3
PERMIT_PACKAGE =	Yes

MODULES =		lang/php

RUN_DEPENDS =		databases/mariadb,-server \
			${MODPHP_RUN_DEPENDS} \
			lang/php/${MODPHP_VERSION},-mysqli \
			lang/php/${MODPHP_VERSION},-pdo_mysql \
			www/composer

NO_TEST =		Yes
NO_BUILD =		Yes

PREFIX =		${VARBASE}/www
INSTALLDIR =		${PREFIX}/htdocs/matomo

do-install:
	${INSTALL_DATA_DIR} ${WRKSRC} ${INSTALLDIR}
	@cp -r ${WRKSRC}/* ${INSTALLDIR}
	@chown -R www:www ${INSTALLDIR}

.include <bsd.port.mk>
