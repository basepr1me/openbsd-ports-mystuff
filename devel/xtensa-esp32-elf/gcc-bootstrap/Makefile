# $OpenBSD$

COMMENT=	gcc for ${CONFIG} cross-development

VERSION=	6.3.0
DISTNAME=	gcc-${VERSION}
PKGNAME=	${CONFIG}-gcc-bootstrap-${VERSION}

SUBST_VARS+=	VERSION

WANTLIB=	${COMPILER_LIBCXX} c gmp m mpc mpfr
DIST_SUBDIR=	gcc

MAKE_GXX=	No
MAKE_FORTRAN=	No
MAKE_OBJC=	No
MAKE_JAVA=	No
MAKE_ADA=	No

MASTER_SITES= 	${MASTER_SITE_GCC:=releases/gcc-$(VERSION)/}

COMPILER =		base-clang ports-gcc base-gcc

BUILD_DEPENDS+=	devel/bison \
		devel/${CONFIG}/binutils

LIB_DEPENDS=	devel/mpfr \
		devel/libmpc

RUN_DEPENDS =	devel/${CONFIG}/binutils

CONFIGURE_ARGS+=--without-headers \
		--disable-lto \
		--exec-prefix=${PREFIX}/${CONFIG}/bootstrap \
		--with-local-prefix=${PREFIX}/${CONFIG}/bootstrap \
		--with-as=${LOCALBASE}/bin/${CONFIG}-as \
		--with-ld=${LOCALBASE}/bin/${CONFIG}-ld

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

ALL_TARGET=	all-gcc all-target-libgcc
INSTALL_TARGET=	install-gcc install-target-libgcc

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	LANGUAGES="c c++" CFLAGS="-I${LOCALBASE}/include"
MAKE_ENV=	MACHINE_ARCH=${CONFIG}

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes
YACC=		bison

TEST_DEPENDS=devel/dejagnu

pre-configure:
	@cp -r ${FILESDIR}/esp32/* ${WRKSRC}

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/

.include <bsd.port.mk>
