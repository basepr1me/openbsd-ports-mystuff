# $OpenBSD: Makefile,v 1.4 2021/01/21 19:36:38 jasper Exp $

# new patches collected at https://github.com/earlephilhower/esp-quick-toolchain
COMMENT =	gcc for ${CONFIG} cross-development

VERSION =	10.1.0
DISTNAME =	gcc-${VERSION}
PKGNAME =	${CONFIG}-gcc-${VERSION}

SHARED_LIBS +=  lto_plugin                0.0 # 0.0

WANTLIB =	${COMPILER_LIBCXX} c gmp m mpc mpfr zstd

SUBST_VARS +=	VERSION

COMPILER =	base-clang ports-gcc base-gcc

.if ${MACHINE_ARCH} == "powerpc64"
PATCH_LIST =	patch-* vecstep-*
.endif

MASTER_SITES =	${MASTER_SITE_GCC:=releases/${DISTNAME}/}

BUILD_DEPENDS +=	devel/bison \
			devel/${CONFIG}/binutils \
			devel/${CONFIG}/newlib
RUN_DEPENDS =		devel/${CONFIG}/binutils \
			devel/${CONFIG}/newlib
LIB_DEPENDS =		archivers/zstd \
			devel/gmp \
			devel/mpfr \
			devel/libmpc

# cope with user settings in /etc/mk.conf
# without wrksrc include, build picks up wrong header file
MAKE_FLAGS =	LANGUAGES="c c++" CFLAGS="-I${WRKSRC}/include " \
		"-I${LOCALBASE}/include "
MAKE_ENV =	MACHINE_ARCH=${CONFIG}
MAKE_GXX =	Yes
MAKE_FORTRAN =	No
MAKE_OBJC =	No
MAKE_JAVA =	No
MAKE_ADA =	No

SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes
YACC =			bison

CONFIGURE_ARGS +=	--with-headers=${LOCALBASE}/${CONFIG}/include  \
			--with-local-prefix=${LOCALBASE}/${CONFIG} \
			--with-as="${LOCALBASE}/bin/${CONFIG}-as" \
			--with-ld="${LOCALBASE}/bin/${CONFIG}-ld" \
			--with-newlib \
			--enable-threads=yes \
			--disable-shared \
			--disable-__cxa_atexit \
			--enable-cxx-flags="-fno-rtti -ffunction-sections -mlongcalls -mtext-section-literals" \
			--enable-target-optspace \
			--without-long-double-128 \
			--disable-libgomp \
			--disable-libmudflap \
			--disable-libssp \
			--disable-libquadmath \
			--disable-libquadmath-support \
			--disable-nls \
			--disable-multilib \
			--enable-languages=c,c++ \
			--disable-option-checking \
			--enable-lto \
			--enable-static=yes
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ENV +=	MACHINE_ARCH=${CONFIG}

ALL_TARGET =		all-gcc all-target-libgcc all-target-libstdc++-v3
INSTALL_TARGET =	install-gcc install-target-libgcc install-target-libstdc++-v3

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/

.include <bsd.port.mk>
