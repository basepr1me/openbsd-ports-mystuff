# $OpenBSD$

COMMENT=	bootstrap compiler for ${CONFIG} cross-development

VERSION=	8.2.0
# DISTNAME=	gcc-${VERSION}
# DISTFILES=	${DISTNAME}.tar.xz

GH_ACCOUNT =	espressif
GH_PROJECT =	gcc
GH_TAGNAME =	esp32-2019r1_gcc-8_2_0

PKGNAME=	${CONFIG}-gcc-bootstrap-${VERSION}

SUBST_VARS+=	VERSION GCC_V

# SHARED_LIBS +=  lto_plugin                0.0 # 0.

WANTLIB=	${COMPILER_LIBCXX} c gmp m mpc mpfr
DIST_SUBDIR=	gcc-elf32

MAKE_GXX=	No
MAKE_FORTRAN=	No
MAKE_OBJC=	No
MAKE_JAVA=	No
MAKE_ADA=	No

# MASTER_SITES= 	${MASTER_SITE_GCC:=releases/gcc-$(VERSION)/}
MODULES=	lang/python

BUILD_DEPENDS+=	devel/bison \
		devel/${CONFIG}/binutils

LIB_DEPENDS=	devel/mpfr \
		devel/libmpc

RUN_DEPENDS =	devel/${CONFIG}/binutils

CFLAGS=		-O2 -g

CONFIGURE_ARGS+=--enable-languages=c \
		--without-headers \
		--exec-prefix=${PREFIX}/${CONFIG}/bootstrap	\
		--with-local-prefix=${PREFIX}/${CONFIG}/bootstrap \
		--with-as=${LOCALBASE}/bin/${CONFIG}-as \
		--with-ld=${LOCALBASE}/bin/${CONFIG}-ld \
			--enable-threads=no \
			--disable-shared \
			--disable-__cxa_atexit \
			--enable-cxx-flags='-fno-rtti -ffunction-sections' \
			--disable-lto \
			--enable-target-optspace \
			--without-long-double-128 \
			--disable-libgomp \
			--disable-libmudflap \
			--disable-libssp \
			--disable-libquadmath \
			--disable-libquadmath-support \
			--disable-nls \
			--disable-libstdcxx-verbose \
			--enable-gcov-custom-rtio

# CONFIGURE_ARGS+=--enable-languages=c \
# 		--without-headers \
# 		--disable-lto \
# 		--exec-prefix=${PREFIX}/${CONFIG}/bootstrap	\
# 		--with-local-prefix=${PREFIX}/${CONFIG}/bootstrap \
# 		--with-as=${LOCALBASE}/bin/${CONFIG}-as \
# 		--with-ld=${LOCALBASE}/bin/${CONFIG}-ld

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MACHINE_ARCH=xtensa

ALL_TARGET=	all-gcc all-target-libgcc
INSTALL_TARGET=	install-gcc install-target-libgcc

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	LANGUAGES="c" CFLAGS="-I${LOCALBASE}/include"
MAKE_ENV=	MACHINE_ARCH=xtensa

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes
YACC=		bison

TEST_DEPENDS=	devel/dejagnu

# post-extract:
# 	@cp ${FILESDIR}/include/xtensa-config.h ${WRKSRC}/include/

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/lib/libstdc++.a-gdb.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-8.2.0/python/libstdcxx/__init__.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-8.2.0/python/libstdcxx/v6/__init__.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-8.2.0/python/libstdcxx/v6/printers.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-8.2.0/python/libstdcxx/v6/xmethods.py

.include <bsd.port.mk>
