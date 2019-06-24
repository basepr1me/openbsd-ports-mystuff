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
