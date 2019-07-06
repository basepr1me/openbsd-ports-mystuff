# $OpenBSD$

COMMENT=	binutils for ${CONFIG} cross-development

VERSION=	2.25.1
DISTNAME=	binutils-${VERSION}

WANTLIB=	c

MASTER_SITES=	https://packages.traceyemery.net/distfiles/

DIST_SUBDIR=	binutils-lx106

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

.include <bsd.port.mk>
