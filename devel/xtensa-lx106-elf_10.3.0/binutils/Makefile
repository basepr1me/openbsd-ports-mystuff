# $OpenBSD: Makefile,v 1.1.1.1 2020/03/12 15:05:19 tracey Exp $

COMMENT =	binutils for ${CONFIG} cross-development

VERSION =	2.32
DISTNAME =	binutils-${VERSION}
PKGNAME =	${CONFIG}-binutils-${VERSION}
REVISION =	0

GH_ACCOUNT =	bminor
GH_PROJECT =	binutils-gdb
# GH_TAGNAME =	binutils-2_32
GH_COMMIT =	2846942c7c83d007106cdcf1108ceedb50e1d4ec

WANTLIB += ${COMPILER_LIBCXX} c curses expat intl m python3.8
WANTLIB += util

MODULES =		lang/python

# CONFIGURE_ENV +=	CFLAGS_FOR_BUILD="-mlongcalls -Os -g -free -fipa-pta" \
# 			CXXFLAGS_FOR_BUILD="-mlongcalls -Os -g -free -fipa-pta"

CONFIGURE_ARGS +=	--enable-languages=c,c++

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gdb/python/gdb

.include <bsd.port.mk>
