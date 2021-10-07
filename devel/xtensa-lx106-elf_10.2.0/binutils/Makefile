# $OpenBSD: Makefile,v 1.1.1.1 2020/03/12 15:05:19 tracey Exp $

COMMENT =	binutils for ${CONFIG} cross-development

VERSION =	2.32
DISTNAME =	binutils-${VERSION}
PKGNAME =	${CONFIG}-binutils-${VERSION}
REVISION =	0

GH_ACCOUNT =	bminor
GH_PROJECT =	binutils-gdb
GH_COMMIT =	2846942c7c83d007106cdcf1108ceedb50e1d4ec

WANTLIB += ${COMPILER_LIBCXX} c curses expat m

CONFIGURE_ARGS =	--target=${CONFIG} \
			--with-sysroot=${LOCALBASE} \
			--prefix=${INSTALLDIR}/bootstrap \
			--disable-shared \
			--with-newlib \
			--enable-threads=no \
			--disable-__cxa_atexit \
			--disable-libgomp \
			--disable-libmudflap \
			--disable-nls \
			--disable-multilib \
			--disable-lto \
			--disable-libstdcxx-verbose \
			--enable-languages=c,c++ \
			--enable-static=yes

.include <bsd.port.mk>
