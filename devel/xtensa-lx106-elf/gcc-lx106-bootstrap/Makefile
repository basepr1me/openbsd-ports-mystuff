# $OpenBSD$

COMMENT=	bootstrap compiler for ${CONFIG} cross-development

VERSION=	4.8.5
DISTNAME=	gcc-lx106-${VERSION}
PKGNAME=	${CONFIG}-gcc-bootstrap-${VERSION}

MASTER_SITES=	https://packages.traceyemery.net/distfiles/

SHARED_LIBS+=  lto_plugin                0.0 # 0.0

SUBST_VARS+=	VERSION GCC_V

WANTLIB=	${COMPILER_LIBCXX} c gmp m mpc mpfr
DIST_SUBDIR=	gcc-lx106

MAKE_GXX=	No
MAKE_FORTRAN=	No
MAKE_OBJC=	No
MAKE_JAVA=	No
MAKE_ADA=	No

COMPILER=	base-clang ports-gcc

BUILD_DEPENDS+=	devel/bison \
		devel/${CONFIG}/binutils

LIB_DEPENDS=	devel/mpfr \
		devel/libmpc

RUN_DEPENDS =	devel/${CONFIG}/binutils

CFLAGS=		-O2 -g

CONFIGURE_ARGS+=--exec-prefix=${LOCALBASE}/${CONFIG}/bootstrap \
		--with-local-prefix=${LOCALBASE}/${CONFIG} \
		--with-as="${LOCALBASE}/bin/${CONFIG}-as" \
		--with-ld="${LOCALBASE}/bin/${CONFIG}-ld" \
		--with-newlib \
		--enable-threads=no \
		--disable-shared \
		--disable-__cxa_atexit \
		--disable-libgomp \
		--disable-libmudflap \
		--disable-libmpx \
		--disable-libssp \
		--disable-libquadmath \
		--disable-libquadmath-support \
		--enable-lto \
		--enable-target-optspace \
		--without-long-double-128 \
		--disable-nls \
		--disable-multilib \
		--enable-languages=c,lto \
		--disable-option-checking

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

ALL_TARGET=	all-gcc all-target-libgcc
INSTALL_TARGET=	install-gcc install-target-libgcc

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	LANGUAGES="c" CFLAGS="-I${LOCALBASE}/include"
MAKE_ENV=	MACHINE_ARCH=${CONFIG}

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes
YACC=		bison

TEST_DEPENDS=	devel/dejagnu

WRKDIST=	${WRKDIR}/gcc-${VERSION}

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/

.include <bsd.port.mk>
