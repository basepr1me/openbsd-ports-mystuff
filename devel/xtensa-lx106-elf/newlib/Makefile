# $OpenBSD$

COMMENT=	newlib for ${CONFIG} cross-development

DISTNAME=	newlib-2.0.0
VERSION=	2.0.0
PKGNAME=	${CONFIG}-newlib-${VERSION}

CONFIGURE_ENV=CC_FOR_TARGET="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-gcc"
CONFIGURE_ENV+=AS_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-as"
CONFIGURE_ENV+=AR_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-ar"
CONFIGURE_ENV+=RANLIB_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-ranlib"

MAKE_ENV+=	${CONFIGURE_ENV}
MAKE_ENV+=	MACHINE_ARCH=${CONFIG}

HOMEPAGE=	http://sourceware.org/newlib/

MASTER_SITES=	https://packages.traceyemery.net/distfiles/
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
