# $OpenBSD$

COMMENT=	gdb for ${CONFIG} cross-development

VERSION=	7.10
DISTNAME=	gdb-${VERSION}
PKGNAME=        ${CONFIG}-${DISTNAME}

HOMEPAGE=	https://www.gnu.org/software/gdb/

WANTLIB=	c curses expat m pthread z

MASTER_SITES=	https://packages.traceyemery.net/distfiles/
DIST_SUBDIR=	gdb-lx106

USE_GMAKE=	Yes

CFLAGS+=	-Dunix

CONFIGURE_ARGS+=--enable-multilib \
		--enable-thumb \
		--enable-interwork

MODULES=	lang/python

TEST_DEPENDS=	devel/dejagnu

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gdb/system-gdbinit

.include <bsd.port.mk>
