# $OpenBSD: Makefile,v 1.3 2021/01/09 21:41:16 jasper Exp $

COMMENT =	gcc for ${CONFIG} cross-development

VERSION =	10.2.0
DISTNAME =	gcc-${VERSION}
PKGNAME =	${CONFIG}-gcc-${VERSION}

WANTLIB += ${COMPILER_LIBCXX} c gmp isl m mpc mpfr

MODULES =	lang/python

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

BUILD_DEPENDS +=	devel/${CONFIG}/binutils \
			devel/${CONFIG}/newlib
RUN_DEPENDS =		${BUILD_DEPENDS}
LIB_DEPENDS =		devel/gmp \
			devel/libmpc \
			devel/mpfr \
			math/isl

CONFIGURE_ARGS +=	--with-as="${INSTALLDIR}/bin/${CONFIG}-as" \
			--with-ld="${INSTALLDIR}/bin/${CONFIG}-ld" \
			--with-sysroot="${INSTALLDIR}/${CONFIG}" \
			--with-gmp="${LOCALBASE}" \
			--with-isl="${LOCALBASE}" \
			--disable-multilib

#--with-headers=${LOCALBASE}/${CONFIG}/include  \

ALL_TARGET =		all-gcc all-target-libgcc all-target-libstdc++-v3 \
			all-target-libssp
INSTALL_TARGET =	install-gcc install-target-libgcc \
			install-target-libstdc++-v3 install-target-libssp

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/${CONFIG}/lib/gcc/${CONFIG}/${VERSION}/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py ${PREFIX}/${CONFIG}/
	@cd ${PREFIX}/${CONFIG}/bin && ln -s ${CONFIG}-gcc ${CONFIG}-cc

.include <bsd.port.mk>
