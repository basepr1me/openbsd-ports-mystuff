# $OpenBSD$

COMMENT=	gdb for ${CONFIG} cross-development

DISTNAME=	gdb-7.9.1
EXTRACT_SUFX=	.tar.xz
REVISION=	1

HOMEPAGE=	https://www.gnu.org/software/gdb/

WANTLIB=	c expat m ncurses pthread z

MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}
DIST_SUBDIR=	gdb

USE_GMAKE=	Yes

CFLAGS+=	-Dunix

CONFIGURE_ARGS+=--enable-multilib \
		--enable-thumb \
		--enable-interwork

MODULES=	lang/python

TEST_DEPENDS=	devel/dejagnu


pre-configure:
	@cp -r ${FILESDIR}/esp32/* ${WRKSRC}

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gdb/system-gdbinit

.include <bsd.port.mk>
