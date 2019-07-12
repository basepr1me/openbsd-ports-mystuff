# $OpenBSD$

COMMENT=	bootstrap compiler for ${CONFIG} cross-development

VERSION=	8.2.0

# GH_ACCOUNT =	espressif
# GH_PROJECT =	gcc
# GH_TAGNAME =	esp32-2019r1_gcc-8_2_0
DISTNAME=	gcc-esp32-${VERSION}
PKGNAME=	${CONFIG}-gcc-bootstrap-${VERSION}

MASTER_SITES=	https://packages.traceyemery.net/distfiles/

SHARED_LIBS +=  lto_plugin                0.0 # 0.0

SUBST_VARS+=	VERSION GCC_V

WANTLIB=	${COMPILER_LIBCXX} c gmp m mpc mpfr

DIST_SUBDIR=	gcc-esp32

MAKE_GXX=	No
MAKE_FORTRAN=	No
MAKE_OBJC=	No
MAKE_JAVA=	No
MAKE_ADA=	No

MODULES=	lang/python

BUILD_DEPENDS+=	devel/bison \
		devel/${CONFIG}/binutils

LIB_DEPENDS=	devel/mpfr \
		devel/libmpc

RUN_DEPENDS =	devel/${CONFIG}/binutils

CFLAGS=		-O2 -g

CONFIGURE_ARGS+=--exec-prefix=${LOCALBASE}/${CONFIG}/bootstrap \
		--with-local-prefix=${LOCALBASE}/${CONFIG} \
		--with-as="${LOCALBASE}/bin/${CONFIG}-as" \
		--with-ld="${LOCALBASE}/bin/${CONFIG}-ld" \
		--without-headers \
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
		--enable-lto \
		--enable-target-optspace \
		--without-long-double-128 \
		--disable-nls \
		--enable-multiarch \
		--enable-languages=c,lto \
		--disable-option-checking

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MACHINE_ARCH=${CONFIG}

ALL_TARGET=	all-gcc all-target-libgcc
INSTALL_TARGET=	install-gcc install-target-libgcc

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	LANGUAGES="c" CFLAGS="-I${LOCALBASE}/include"
MAKE_ENV=	MACHINE_ARCH=${CONFIG}

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes
YACC=		bison

TEST_DEPENDS=	devel/dejagnu

WRKDIST=	${WRKDIR}/gcc

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
