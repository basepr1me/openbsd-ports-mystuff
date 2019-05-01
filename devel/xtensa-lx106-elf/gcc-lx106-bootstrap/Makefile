# $OpenBSD$

COMMENT=	bootstrap compiler for ${CONFIG} cross-development

VERSION=	8.3.0
DISTNAME=	gcc-${VERSION}
DISTFILES=	${DISTNAME}.tar.xz
PKGNAME=	${CONFIG}-gcc-bootstrap-${VERSION}

SUBST_VARS+=	VERSION GCC_V

WANTLIB=	${COMPILER_LIBCXX} c gmp m mpc mpfr
DIST_SUBDIR=	gcc

MAKE_GXX=	No
MAKE_FORTRAN=	No
MAKE_OBJC=	No
MAKE_JAVA=	No
MAKE_ADA=	No

MASTER_SITES= 	${MASTER_SITE_GCC:=releases/gcc-$(VERSION)/}
master_sites0=	https://distfiles.stumpf.co/ \
		https://spacehopper.org/mirrors/ \
		https://distfiles.bsdfrog.org/

BUILD_DEPENDS+=	devel/bison \
		devel/${CONFIG}/binutils

LIB_DEPENDS=	devel/mpfr \
		devel/libmpc

RUN_DEPENDS =	devel/${CONFIG}/binutils

CFLAGS=		-O2 -g

CONFIGURE_ARGS+=--enable-languages=c \
		--without-headers \
		--disable-lto \
		--exec-prefix=${PREFIX}/${CONFIG}/bootstrap	\
		--with-local-prefix=${PREFIX}/${CONFIG}/bootstrap \
		--with-as=${LOCALBASE}/bin/${CONFIG}-as \
		--with-ld=${LOCALBASE}/bin/${CONFIG}-ld
# CONFIGURE_ARGS+=--with-system-zlib \
# 		--enable-multilib \
# 		--disable-decimal-float \
# 		--disable-libffi \
# 		--disable-libgomp \
# 		--disable-libmudflap \
# 		--disable-libquadmath \
# 		--disable-libquadmath-support \
# 		--disable-libssp \
# 		--disable-libstdcxx-pch \
# 		--disable-libstdc++-v3 \
# 		--disable-nls \
# 		--disable-shared \
# 		--disable-threads \
# 		--disable-tls \
# 		--disable-lto \
# 		--enable-target-optspace \
# 		--disable-__cxa_atexit \
# 		--without-long-double-128 \
# 		--enable-cxx-flags=-fno-exceptions \
# 		--with-gnu-as \
# 		--with-gnu-ld \
# 		--with-headers=no \
# 		--without-newlib \
# 		--without-included-gettext \
# 		--exec-prefix=${PREFIX}/${CONFIG}/bootstrap \
# 		--with-local-prefix=${PREFIX}/${CONFIG}/bootstrap \
# 		--with-ar=${LOCALBASE}/bin/${CONFIG}-ar \
# 		--with-as=${LOCALBASE}/bin/${CONFIG}-as \
# 		--with-nm=${LOCALBASE}/bin/${CONFIG}-nm \
# 		--with-ld=${LOCALBASE}/bin/${CONFIG}-ld

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

post-extract:
	@cp ${FILESDIR}/include/xtensa-config.h ${WRKSRC}/include/

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/

.include <bsd.port.mk>
