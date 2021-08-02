# $OpenBSD: Makefile,v 1.1.1.1 2020/03/12 15:05:19 tracey Exp $

COMMENT =	binutils for ${CONFIG} cross-development

VERSION =	2.32
DISTNAME =	binutils-${VERSION}
PKGNAME =	${CONFIG}-binutils-${VERSION}
REVISION =	0

HOMEPAGE = https://sourceware.org/binutils/

MASTER_SITES =	https://sourceware.org/pub/binutils/releases/

WANTLIB =	c z

USE_LIBTOOL =	No

CONFIGURE_ARGS +=	--disable-werror \
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
