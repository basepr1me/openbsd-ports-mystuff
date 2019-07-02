# $OpenBSD$

COMMENT=	newlib for ${CONFIG} cross-development

VERSION=	3.0.0
PKGNAME=	${CONFIG}-newlib-${VERSION}

GH_ACCOUNT =	espressif
GH_PROJECT =	newlib-esp32
GH_TAGNAME =	esp32-2019r1_newlib-3_0_0

DIST_SUBDIR=	newlib-esp32

CONFIGURE_ENV=CC_FOR_TARGET="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-gcc"
CONFIGURE_ENV+=AS_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-as"
CONFIGURE_ENV+=AR_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-ar"
CONFIGURE_ENV+=RANLIB_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-ranlib"

MAKE_ENV+=	${CONFIGURE_ENV}
MAKE_ENV+=	MACHINE_ARCH=${CONFIG}

HOMEPAGE=	http://sourceware.org/newlib/

BUILD_DEPENDS=	devel/${CONFIG}/binutils \
		${RUN_DEPENDS}
RUN_DEPENDS=	devel/${CONFIG}/gcc-esp32-bootstrap

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	CFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	Yes
USE_GROFF=	No

CONFIGURE_ARGS+=--with-system-zlib \
		--with-as="${LOCALBASE}/bin/${CONFIG}-as" \
		--with-ld="${LOCALBASE}/bin/${CONFIG}-ld" \
		--enable-newlib-io-float \
		--disable-newlib-io-long-double \
		--disable-newlib-supplied-syscalls \
		--enable-newlib-io-pos-args \
		--enable-newlib-io-c99-formats \
		--enable-newlib-io-long-long \
		--disable-newlib-register-fini \
		--disable-newlib-nano-malloc \
		--disable-newlib-nano-formatted-io \
		--enable-newlib-atexit-dynamic-alloc \
		--disable-newlib-global-atexit \
		--disable-lite-exit \
		--enable-newlib-reent-small \
		--enable-newlib-multithread \
		--enable-newlib-wide-orient \
		--enable-newlib-unbuf-stream-opt \
		--enable-target-optspace \
		--enable-newlib-long-time_t \
		--enable-newlib-nano-malloc \
		--disable-option-checking

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/newlib

post-install:
	${INSTALL_DATA} ${WRKDIST}/COPYING.NEWLIB \
		${PREFIX}/share/doc/newlib

.include <bsd.port.mk>
