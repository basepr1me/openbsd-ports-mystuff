# $OpenBSD$

COMMENT=	binutils for ${CONFIG} cross-development

VERSION=	2.32
PKGNAME=	${CONFIG}-binutils-${VERSION}

GH_PROJECT=	binutils-gdb-xtensa
GH_TAGNAME=	binutils-2_32

WANTLIB=	c z

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
