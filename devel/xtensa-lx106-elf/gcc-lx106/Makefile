# $OpenBSD$

COMMENT=	gcc for ${CONFIG} cross-development

VERSION=	8.3.0
DISTNAME=	gcc-${VERSION}
DISTFILES=	${DISTNAME}.tar.xz
PKGNAME=	${CONFIG}-${DISTNAME}

SUBST_VARS+=	VERSION GCC_V

WANTLIB=	${COMPILER_LIBCXX} c gmp m mpc mpfr
DIST_SUBDIR=	gcc

MAKE_GXX=	Yes
MAKE_FORTRAN=	No
MAKE_OBJC=	No
MAKE_JAVA=	No
MAKE_ADA=	No

MASTER_SITES= 	${MASTER_SITE_GCC:=releases/gcc-$(VERSION)/}
master_sites0 =	https://distfiles.stumpf.co/ \
		https://spacehopper.org/mirrors/ \
		https://distfiles.bsdfrog.org/

BUILD_DEPENDS+=	devel/bison \
		devel/${CONFIG}/binutils \
		devel/${CONFIG}/newlib

LIB_DEPENDS=	devel/mpfr \
		devel/libmpc

RUN_DEPENDS =	devel/${CONFIG}/binutils \
		devel/${CONFIG}/newlib

CFLAGS=		-O2 -g

CONFIGURE_ARGS+=--enable-languages=${LANGS} \
		--enable-multilib \
		--enable-interwork \
		--with-newlib \
		--disable-lto \
		--enable-cpp \
		--datarootdir=${PREFIX}/${CONFIG}/share

# CONFIGURE_ARGS+=--with-system-zlib \
# 		--enable-multilib \
# 		--enable-interwork \
# 		--disable-decimal-float \
# 		--disable-libffi \
# 		--disable-libgomp \
# 		--disable-libmudflap \
# 		--disable-libquadmath \
# 		--disable-libquadmath-support \
# 		--disable-libssp \
# 		--enable-libstdcxx \
# 		--enable-libstdc__-v3 \
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
# 		--without-included-gettext \
# 		--exec-prefix=${PREFIX}/${CONFIG}/gcc \
# 		--with-local-prefix=${PREFIX}/${CONFIG}/gcc \
# 		--with-newlib \
# 		--enable-cpp \
# 		--datarootdir=${PREFIX}/${CONFIG}/share

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
# CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
# 		CPPFLAGS+="-I${LOCALBASE}/${CONFIG}/include" \
# 		LDFLAGS="-L${LOCALBASE}/lib" \
# 		LDFLAGS+="-L${LOCALBASE}/${CONFIG}/lib"

ALL_TARGET=	all-gcc all-target-libgcc all-target-libstdc++-v3
INSTALL_TARGET=	install-gcc install-target-libgcc install-target-libstdc++-v3

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	LANGUAGES="c c++" CFLAGS="-I${LOCALBASE}/include"
# MAKE_FLAGS=	LANGUAGES="c c++" \
# 		CFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/${CONFIG}/include"
MAKE_ENV=	MACHINE_ARCH=${CONFIG}

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes
YACC=		bison

TEST_DEPENDS=devel/dejagnu

post-extract:
	@cp ${FILESDIR}/include/xtensa-config.h ${WRKSRC}/include/

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/lib/libstdc++.a-gdb.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-8.3.0/python/libstdcxx/__init__.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-8.3.0/python/libstdcxx/v6/__init__.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-8.3.0/python/libstdcxx/v6/printers.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-8.3.0/python/libstdcxx/v6/xmethods.py

.include <bsd.port.mk>
