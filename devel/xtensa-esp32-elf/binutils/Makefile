# $OpenBSD: Makefile,v 1.1.1.1 2020/03/11 14:24:57 tracey Exp $

COMMENT =	binutils for ${CONFIG} cross-development
VERSION =	2.33.1.2020.3
PKGNAME =	${CONFIG}-binutils-${VERSION}

GH_ACCOUNT =	espressif
GH_PROJECT =	binutils-gdb
GH_TAGNAME =	esp-2020r3-binutils

WANTLIB =	c z

USE_LIBTOOL =	No

CONFIGURE_ARGS +=	--disable-werror \
			--enable-ld=yes \
			--enable-gold=no \
			--enable-multilib \
			--disable-sim \
			--disable-gdb \
			--with-sysroot=${LOCALBASE}/${CONFIG} \
			--disable-option-checking \
			--with-gnu-ld \
			--with-gnu-as \
			--with-newlib \
			--with-system-zlib

.include <bsd.port.mk>
