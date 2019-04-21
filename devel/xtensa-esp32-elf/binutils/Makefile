# $OpenBSD$

COMMENT=	binutils for ${CONFIG} cross-development

V=		2.27
DISTNAME=	binutils-$V

HOMEPAGE=	https://www.gnu.org/software/binutils/

WANTLIB=	c

MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
DIST_SUBDIR=	binutils

USE_LIBTOOL=	No

CONFIGURE_ARGS+=--enable-commonbfdlib=no \
		--enable-interwork	 \
		--enable-multilib

pre-configure:
	@cp -r ${FILESDIR}/esp32/* ${WRKSRC}

.include <bsd.port.mk>
