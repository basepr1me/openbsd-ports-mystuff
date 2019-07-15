# $OpenBSD$

COMMENT=	gcc for ${CONFIG} cross-development

VERSION=	8.2.0

DISTNAME=	gcc-esp32-${VERSION}
PKGNAME=	${CONFIG}-gcc-${VERSION}

MASTER_SITES=	https://packages.traceyemery.net/distfiles/

SHARED_LIBS +=  lto_plugin                0.0 # 0.0

SUBST_VARS+=	VERSION GCC_V

WANTLIB=	${COMPILER_LIBCXX} c gmp m mpc mpfr

DIST_SUBDIR=	gcc-esp32

MAKE_GXX=	Yes
MAKE_FORTRAN=	No
MAKE_OBJC=	No
MAKE_JAVA=	No
MAKE_ADA=	No

MODULES=	lang/python

BUILD_DEPENDS+=	devel/bison \
		devel/${CONFIG}/binutils \
		devel/${CONFIG}/newlib

LIB_DEPENDS=	devel/mpfr \
		devel/libmpc

RUN_DEPENDS =	devel/${CONFIG}/binutils \
		devel/${CONFIG}/newlib

CFLAGS=		-O2 -g

CONFIGURE_ARGS+=--with-headers=${LOCALBASE}/${CONFIG}/include  \
		--with-local-prefix=${LOCALBASE}/${CONFIG} \
		--with-as="${LOCALBASE}/bin/${CONFIG}-as" \
		--with-ld="${LOCALBASE}/bin/${CONFIG}-ld" \
		--with-newlib  \
		--enable-threads=no  \
		--disable-shared  \
		--disable-__cxa_atexit  \
		--enable-cxx-flags="-fno-rtti -ffunction-sections -mlongcalls -mtext-section-literals" \
		--disable-libgomp  \
		--disable-libmudflap  \
		--disable-libmpx  \
		--disable-libssp  \
		--disable-libquadmath  \
		--disable-libquadmath-support  \
		--enable-lto  \
		--enable-target-optspace  \
		--without-long-double-128  \
		--disable-nls  \
		--enable-multiarch  \
		--disable-libstdcxx-verbose  \
		--enable-gcov-custom-rtio  \
		--enable-libstdcxx-time=yes  \
		--enable-languages=c,c++,lto  \
		--disable-option-checking

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CXXFLAGS="-O2 -g -pipe"

ALL_TARGET=	all-gcc all-target-libgcc all-target-libstdc++-v3
INSTALL_TARGET=	install-gcc install-target-libgcc install-target-libstdc++-v3

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	LANGUAGES="c c++" CFLAGS="-I${LOCALBASE}/include"
MAKE_ENV=	MACHINE_ARCH=${CONFIG}

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes
YACC=		bison

TEST_DEPENDS=devel/dejagnu

WRKDIST=	${WRKDIR}/gcc

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-${VERSION}/python/libstdcxx/__init__.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-${VERSION}/python/libstdcxx/v6/__init__.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-${VERSION}/python/libstdcxx/v6/printers.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/gcc-${VERSION}/python/libstdcxx/v6/xmethods.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/xtensa-esp32-elf/lib/esp32-psram/libstdc++.a-gdb.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/xtensa-esp32-elf/lib/libstdc++.a-gdb.py
	cd ${PREFIX}/libexec/gcc/${CONFIG}/${VERSION} && \
		ln -s liblto_plugin.so.0.0 liblto_plugin.so

.include <bsd.port.mk>
