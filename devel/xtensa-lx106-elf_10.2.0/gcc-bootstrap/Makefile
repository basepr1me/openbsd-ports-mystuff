# $OpenBSD: Makefile,v 1.3 2021/01/09 21:41:16 jasper Exp $

COMMENT =	bootstrap compiler for ${CONFIG} cross-development

VERSION =	10.2.0
DISTNAME =	gcc-${VERSION}
PKGNAME =	${CONFIG}-gcc-bootstrap-${VERSION}

SHARED_LIBS +=  cc1plugin                 0.0 # 0.0
SHARED_LIBS +=  cp1plugin                 0.0 # 0.0
SHARED_LIBS +=  cc1                       0.0 # 0.0

WANTLIB += ${COMPILER_LIBCXX} c gmp m mpc mpfr

SUBST_VARS +=	VERSION

MASTER_SITES= 	${MASTER_SITE_GCC:=releases/gcc-$(VERSION)/}
MASTER_SITES0 =	https://raw.githubusercontent.com/earlephilhower/esp-quick-toolchain/master/patches/gcc10.2/
PATCHFILES = 	gcc-ctype-inline-pgmread.patch:0 \
		gcc-eh-alloc.patch:0 \
		gcc-enable-mforcel32-eh.patch:0 \
		gcc-exception-what-to-pmem.patch:0 \
		gcc-file-shortname.patch:0 \
		gcc-func-sect.patch:0 \
		gcc-mforce-l32.patch:0 \
		gcc-regex-what-to-pmem.patch:0 \
		gcc-stdcsupp-safe.patch:0 \
		gcc-unwind-safe.patch:0 \
		gcc-xtensa-add-optimizations-for-shift-operations.patch:0 \
		gcc-xtensa-fix-PR-target-98285.patch:0 \
		gcc-xtensa-implement-bswapsi2-bswapdi2-and-helpers.patch:0 \
		gcc-xtensa-rearrange-DI-mode-constant-loading.patch:0
PATCH_DIST_STRIP = -p1

.if ${MACHINE_ARCH} == "powerpc64"
PATCH_LIST =	patch-* vecstep-*
.endif

BUILD_DEPENDS +=	devel/${CONFIG}/binutils-bootstrap
LIB_DEPENDS =		devel/libmpc \
			devel/mpfr

CONFIGURE_ARGS =	--target=${CONFIG} \
			--with-sysroot=${LOCALBASE} \
			--prefix=${INSTALLDIR}/bootstrap \
			--with-as="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-as" \
			--with-ld="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-ld" \
			--with-gmp="${LOCALBASE}" \
			--disable-shared \
			--with-newlib \
			--enable-threads=no \
			--disable-__cxa_atexit \
			--disable-libgomp \
			--disable-libmudflap \
			--disable-nls \
			--disable-multilib \
			--disable-lto \
			--disable-libstdcxx-verbose \
			--enable-languages=c \
			--enable-static=yes

ALL_TARGET =		all-gcc all-target-libgcc
INSTALL_TARGET =	install-gcc install-target-libgcc

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/
	@cd ${PREFIX}/${CONFIG}/bootstrap/bin && \
	    ln -s ${CONFIG}-gcc ${CONFIG}-cc

.include <bsd.port.mk>
