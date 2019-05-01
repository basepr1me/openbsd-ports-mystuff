# $OpenBSD$

COMMENT=	binutils for ${CONFIG} cross-development

VERSION=	2.27
DISTNAME=	binutils-${VERSION}

HOMEPAGE=	https://www.gnu.org/software/binutils/

WANTLIB=	c

MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
DIST_SUBDIR=	binutils

USE_LIBTOOL=	No

CONFIGURE_ARGS+=--enable-commonbfdlib=no \
		--enable-interwork	 \
		--enable-multilib

post-extract:
	@cp ${FILESDIR}/bfd/xtensa-modules.c ${WRKSRC}/bfd/
	@cp ${FILESDIR}/include/xtensa-config.h ${WRKSRC}/include/

.include <bsd.port.mk>
