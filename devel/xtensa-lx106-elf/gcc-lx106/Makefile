# $OpenBSD$

COMMENT=	gcc for ${CONFIG} cross-development

VERSION=	4.8.5
DISTNAME=	gcc-${VERSION}
PKGNAME=	${CONFIG}-${DISTNAME}

SHARED_LIBS +=  lto_plugin                0.0 # 0.0

SUBST_VARS+=	VERSION GCC_V

MODULES=	lang/python

WANTLIB=	${COMPILER_LIBCXX} c gmp m mpc mpfr
DIST_SUBDIR=	gcc

MAKE_GXX=	Yes
MAKE_FORTRAN=	No
MAKE_OBJC=	No
MAKE_JAVA=	No
MAKE_ADA=	No

MASTER_SITES=	https://packages.traceyemery.net/distfiles/
DIST_SUBDIR=	gcc-lx106

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
		--with-newlib \
		--enable-threads=no \
		--disable-shared \
		--disable-__cxa_atexit \
		--enable-cxx-flags="-fno-rtti -ffunction-sections -mlongcalls -mtext-section-literals" \
		--enable-lto \
		--enable-target-optspace \
		--without-long-double-128 \
		--disable-libgomp \
		--disable-libmudflap \
		--disable-libssp \
		--disable-libquadmath \
		--disable-libquadmath-support \
		--disable-nls \
		--disable-multilib \
		--enable-languages=c,c++,lto \
		--disable-option-checking

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ENV+=	MACHINE_ARCH=${CONFIG}

ALL_TARGET=	all-gcc all-target-libgcc all-target-libstdc++-v3
INSTALL_TARGET=	install-gcc install-target-libgcc install-target-libstdc++-v3

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	LANGUAGES="c c++" CFLAGS="-I${LOCALBASE}/include"
MAKE_ENV=	MACHINE_ARCH=${CONFIG}

SEPARATE_BUILD=	Yes
USE_GMAKE=	Yes
YACC=		bison

TEST_DEPENDS=devel/dejagnu

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/lib/gcc/${CONFIG}/${VERSION}/
	cd ${PREFIX}/libexec/gcc/${CONFIG}/${VERSION} && \
		ln -s liblto_plugin.so.0.0 liblto_plugin.so

.include <bsd.port.mk>
