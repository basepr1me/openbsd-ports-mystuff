# $OpenBSD$

COMMENT=	binutils for ${CONFIG} cross-development

VERSION=	2.25.1
DISTNAME=	binutils-lx106-${VERSION}
PKGNAME=	${CONFIG}-binutils-${VERSION}

DIST_SUBDIR=	binutils-lx106

WANTLIB=	c

MASTER_SITES=	https://packages.traceyemery.net/distfiles/

USE_LIBTOOL=	No


CONFIGURE_ARGS+=--disable-werror \
		--with-system-zlib \
		--enable-ld=yes \
		--enable-gold=no \
		--disable-multilib \
		--disable-sim \
		--disable-gdb \
		--disable-nls \
		--with-sysroot=${LOCALBASE}/${CONFIG} \
		--disable-option-checking

WRKDIST=	${WRKDIR}/binutils-${VERSION}

.include <bsd.port.mk>
