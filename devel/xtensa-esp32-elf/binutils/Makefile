# $OpenBSD: Makefile,v 1.2 2020/10/29 14:10:51 tracey Exp $

COMMENT =	binutils for ${CONFIG} cross-development
VERSION =	2.33.1.2020.3
PKGNAME =	${CONFIG}-binutils-${VERSION}
REVISION =	0

GH_ACCOUNT =	espressif
GH_PROJECT =	binutils-gdb
GH_TAGNAME =	esp-2020r3-binutils

WANTLIB += ${COMPILER_LIBCXX} c curses expat m

CONFIGURE_ARGS +=	--disable-multilib \
			--with-gnu-as \
			--with-gnu-ld

.include <bsd.port.mk>
