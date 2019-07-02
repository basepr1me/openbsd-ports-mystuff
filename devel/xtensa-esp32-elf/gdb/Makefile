# $OpenBSD$

COMMENT=	gdb for ${CONFIG} cross-development

VERSION=	8.1
DISTNAME=	gdb-${VERSION}

GH_ACCOUNT=	espressif
GH_PROJECT=	binutils-gdb
GH_TAGNAME=	esp32-2019r1_gdb-8_1

PKGNAME=        ${CONFIG}-${DISTNAME}

HOMEPAGE=	https://www.gnu.org/software/gdb/

WANTLIB=	c curses expat m pthread z

DIST_SUBDIR=	gdb

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MACHINE_ARCH=${CONFIG}
CONFIGURE_ENV=	CC_FOR_TARGET="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-gcc"
CONFIGURE_ENV+=	AS_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-as"
CONFIGURE_ENV+=	AR_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-ar"
CONFIGURE_ENV+=	RANLIB_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-ranlib"


MAKE_FLAGS=	CFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	Yes

CFLAGS+=	-g -O2 -Dunix

CONFIGURE_ARGS+=--with-build-sysroot=${LOCALBASE}/${CONFIG} \
		--with-sysroot=${LOCALBASE}/${CONFIG} \
		--with-as="${LOCALBASE}/bin/${CONFIG}-as" \
		--with-ld="${LOCALBASE}/bin/${CONFIG}-ld" \
		--disable-werror \
		--with-expat \
		--without-libexpat-prefix \
		--disable-threads \
		--disable-sim \
		--disable-nls \
		--disable-binutils \
		--disable-ld \
		--disable-gas \
		--disable-option-checking

TEST_DEPENDS=	devel/dejagnu

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gdb/system-gdbinit

.include <bsd.port.mk>
