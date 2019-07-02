# $OpenBSD$

COMMENT=	binutils for ${CONFIG} cross-development

VERSION=	2.31
DISTNAME=	binutils-${VERSION}

DIST_SUBDIR=	binutils-esp32

GH_ACCOUNT =	espressif
GH_PROJECT =	binutils-gdb
GH_TAGNAME =	esp32-2019r1_binutils-2_31

HOMEPAGE=	https://www.gnu.org/software/binutils/

WANTLIB=	c

USE_LIBTOOL=	No

CONFIGURE_ARGS+=--disable-werror \
		--enable-ld=yes \
		--enable-gold=no \
		--enable-multilib \
		--disable-sim \
		--disable-gdb \
		--disable-nls \
		--with-sysroot=${LOCALBASE}/${CONFIG} \
		--disable-option-checking

.include <bsd.port.mk>
