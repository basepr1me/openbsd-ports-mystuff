# $OpenBSD: Makefile,v 1.1.1.1 2020/03/12 15:05:19 tracey Exp $

COMMENT =	binutils for ${CONFIG} cross-development

VERSION =	2.32
DISTNAME =	binutils-${VERSION}
PKGNAME =	${CONFIG}-${DISTNAME}
REVISION =	0

HOMEPAGE=	https://www.gnu.org/software/binutils/

WANTLIB =	c z

MASTER_SITES =	${MASTER_SITE_GNU:=binutils/}

USE_LIBTOOL =	No

CONFIGURE_ARGS +=	--with-system-zlib \
			--disable-nls

.include <bsd.port.mk>
