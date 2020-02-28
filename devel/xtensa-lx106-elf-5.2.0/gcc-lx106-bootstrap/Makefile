# $OpenBSD$

COMMENT=	bootstrap compiler for ${CONFIG} cross-development

VERSION=	5.2.0
PKGNAME=	${CONFIG}-gcc-${VERSION}

GH_PROJECT=	gcc-xtensa
GH_COMMIT=	4a86aa4eb36ae95cf42f99251965f4a3a8f45f88

WANTLIB=	${COMPILER_LIBCXX} c gmp m mpc mpfr

DIST_SUBDIR=	gcc-lx106

COMPILER=	base-clang ports-gcc base-gcc

BUILD_DEPENDS+=	devel/bison \
		devel/${CONFIG}/binutils
RUN_DEPENDS =	devel/${CONFIG}/binutils
LIB_DEPENDS=	devel/mpfr \
		devel/libmpc

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	LANGUAGES="c" CFLAGS="-I${LOCALBASE}/include"
MAKE_ENV=	MACHINE_ARCH=${CONFIG}
MAKE_GXX=	No
MAKE_FORTRAN=	No
MAKE_OBJC=	No
MAKE_JAVA=	No
MAKE_ADA=	No

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes
YACC=		bison

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
		--disable-lto \
		--enable-target-optspace \
		--without-long-double-128 \
		--disable-nls \
		--disable-multilib \
		--enable-languages=c \
		--disable-option-checking
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

ALL_TARGET=	all-gcc all-target-libgcc
INSTALL_TARGET=	install-gcc install-target-libgcc

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/

.include <bsd.port.mk>
