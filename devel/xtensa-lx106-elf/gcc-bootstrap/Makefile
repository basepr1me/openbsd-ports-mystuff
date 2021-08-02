# $OpenBSD: Makefile,v 1.3 2021/01/09 21:41:16 jasper Exp $

# new patches collected at https://github.com/earlephilhower/esp-quick-toolchain
COMMENT =	bootstrap compiler for ${CONFIG} cross-development

VERSION =	10.1.0
DISTNAME =	gcc-${VERSION}
PKGNAME =	${CONFIG}-gcc-bootstrap-${VERSION}

WANTLIB += ${COMPILER_LIBCXX} c gmp m mpc mpfr zstd

SUBST_VARS +=	VERSION

COMPILER=	base-clang ports-gcc base-gcc

.if ${MACHINE_ARCH} == "powerpc64"
PATCH_LIST =	patch-* vecstep-*
.endif

MASTER_SITES =	${MASTER_SITE_GCC:=releases/${DISTNAME}/}

BUILD_DEPENDS +=	devel/bison \
			devel/${CONFIG}/binutils
RUN_DEPENDS =		devel/${CONFIG}/binutils
LIB_DEPENDS =		archivers/zstd \
			devel/gmp \
			devel/mpfr \
			devel/libmpc

# cope with user settings in /etc/mk.conf
# without wrksrc include, build picks up wrong header file
MAKE_FLAGS =	LANGUAGES="c" CFLAGS="-I${WRKSRC}/include " \
		"-I${LOCALBASE}/include " \
		"-I/usr/include"
MAKE_ENV =	MACHINE_ARCH=${CONFIG}
MAKE_GXX =	No
MAKE_FORTRAN =	No
MAKE_OBJC =	No
MAKE_JAVA =	No
MAKE_ADA =	No

SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes
YACC =			bison

CONFIGURE_ARGS +=	--exec-prefix=${LOCALBASE}/${CONFIG}/bootstrap \
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
CONFIGURE_ENV =	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

ALL_TARGET =		all-gcc all-target-libgcc
INSTALL_TARGET =	install-gcc install-target-libgcc

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/

.include <bsd.port.mk>
