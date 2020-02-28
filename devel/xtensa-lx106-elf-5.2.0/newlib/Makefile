# $OpenBSD$

COMMENT=	newlib for ${CONFIG} cross-development

VERSION=	2.1.0
PKGNAME=	${CONFIG}-newlib-${VERSION}

GH_PROJECT=	newlib-xtensa
GH_COMMIT=	05722e6770fba6b7059e54b3c81a737f7e7cec59

CONFIGURE_ENV=CC_FOR_TARGET="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-gcc"
CONFIGURE_ENV+=AS_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-as"
CONFIGURE_ENV+=AR_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-ar"
CONFIGURE_ENV+=RANLIB_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-ranlib"

MAKE_ENV+=	${CONFIGURE_ENV}
MAKE_ENV+=	MACHINE_ARCH=${CONFIG}

HOMEPAGE=	http://sourceware.org/newlib/

DIST_SUBDIR=	newlib-lx106

BUILD_DEPENDS=	devel/${CONFIG}/binutils \
		${RUN_DEPENDS}
RUN_DEPENDS=	devel/${CONFIG}/gcc-lx106-bootstrap

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	CFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	Yes
USE_GROFF=	No

CONFIGURE_ARGS+=--with-system-zlib \
		--with-as="${LOCALBASE}/bin/${CONFIG}-as" \
		--with-ld="${LOCALBASE}/bin/${CONFIG}-ld" \
		--with-newlib \
		--disable-newlib-io-c99-formats \
		--disable-newlib-io-long-long \
		--disable-newlib-io-float \
		--disable-newlib-io-long-double \
		--disable-newlib-supplied-syscalls \
		--enable-target-optspace \
		--disable-option-checking

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/newlib
	${INSTALL_DATA} ${WRKDIST}/COPYING.NEWLIB \
		${PREFIX}/share/doc/newlib

.include <bsd.port.mk>
