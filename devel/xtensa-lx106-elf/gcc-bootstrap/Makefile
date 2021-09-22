# $OpenBSD: Makefile,v 1.3 2021/01/09 21:41:16 jasper Exp $

COMMENT =	bootstrap compiler for ${CONFIG} cross-development

VERSION =	10.1.0
DISTNAME =	gcc-${VERSION}
PKGNAME =	${CONFIG}-gcc-bootstrap-${VERSION}

SHARED_LIBS +=  cc1plugin                 0.0 # 0.0
SHARED_LIBS +=  cp1plugin                 0.0 # 0.0
SHARED_LIBS +=  cc1                       0.0 # 0.0

WANTLIB += ${COMPILER_LIBCXX} c gmp m mpc mpfr zstd

SUBST_VARS +=	VERSION

MASTER_SITES= 	${MASTER_SITE_GCC:=releases/gcc-$(VERSION)/}
MASTER_SITES0 =	https://raw.githubusercontent.com/earlephilhower/esp-quick-toolchain/master/patches/gcc10.1/
PATCHFILES = 	gcc-ctype-inline-pgmread.patch \
		gcc-eh-alloc.patch \
		gcc-enable-mforcel32-eh.patch \
		gcc-exception-what-to-pmem.patch \
		gcc-file-shortname.patch \
		gcc-func-sect.patch \
		gcc-mforce-l32.patch \
		gcc-regex-what-to-pmem.patch \
		gcc-stdcsupp-safe.patch \
		gcc-unwind-safe.patch \
		gcc-xtensa-add-optimizations-for-shift-operations.patch \
		gcc-xtensa-fix-PR-target-98285.patch \
		gcc-xtensa-implement-bswapsi2-bswapdi2-and-helpers.patch \
		gcc-xtensa-rearrange-DI-mode-constant-loading.patch
PATCH_DIST_STRIP = -p1

.if ${MACHINE_ARCH} == "powerpc64"
PATCH_LIST =	patch-* vecstep-*
.endif

BUILD_DEPENDS +=	devel/${CONFIG}/binutils
LIB_DEPENDS =		archivers/zstd \
			devel/libmpc \
			devel/mpfr

CONFIGURE_ARGS +=	--exec-prefix=${LOCALBASE}/${CONFIG}/bootstrap \
 			--with-local-prefix=${LOCALBASE}/${CONFIG} \
 			--with-as="${LOCALBASE}/bin/${CONFIG}-as" \
 			--with-ld="${LOCALBASE}/bin/${CONFIG}-ld" \
			--with-gmp="${LOCALBASE}" \
			--disable-shared \
			--with-newlib \
			--enable-threads=no \
			--disable-__cxa_atexit \
			--disable-libgomp \
			--disable-libmudflap \
			--disable-libssp \
			--disable-multilib \
			--enable-languages=c \
			--disable-lto

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/

.include <bsd.port.mk>
