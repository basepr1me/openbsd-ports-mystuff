# $OpenBSD$

COMMENT=	gdb for ${CONFIG} cross-development

VERSION=	7.9.1
DISTNAME=	gdb-${VERSION}
EXTRACT_SUFX=	.tar.xz
PKGNAME=        ${CONFIG}-${DISTNAME}

HOMEPAGE=	https://www.gnu.org/software/gdb/

WANTLIB=	c curses expat m pthread z

MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}
DIST_SUBDIR=	gdb

USE_GMAKE=	Yes

CFLAGS+=	-Dunix

CONFIGURE_ARGS+=--enable-multilib \
		--enable-thumb \
		--enable-interwork

MODULES=	lang/python

TEST_DEPENDS=	devel/dejagnu

post-extract:
	@cp -r ${FILESDIR}/bfd ${WRKSRC}/
	@cp -r ${FILESDIR}/gdb ${WRKSRC}/
	@cp -r ${FILESDIR}/include ${WRKSRC}/

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gdb/system-gdbinit

.include <bsd.port.mk>
