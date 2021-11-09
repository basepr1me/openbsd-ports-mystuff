# $OpenBSD: Makefile,v 1.2 2020/10/29 14:10:51 tracey Exp $

COMMENT =	binutils for ${CONFIG} cross-development
VERSION =	2.35.1.2020.1223
PKGNAME =	${CONFIG}-binutils-${VERSION}

GH_ACCOUNT =	espressif
GH_PROJECT =	binutils-gdb
GH_TAGNAME =	esp-2021r2-binutils

WANTLIB += c z

CONFIGURE_ARGS +=	--disable-multilib \
			--with-gnu-as \
			--with-gnu-ld \
			--disable-werror \
			--disable-gdb

BUILD_DEPENDS +=	lang/gawk

.include <bsd.port.mk>
