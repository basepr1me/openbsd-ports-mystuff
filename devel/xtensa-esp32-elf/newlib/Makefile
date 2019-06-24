# $OpenBSD$

COMMENT=	newlib for ${CONFIG} cross-development

# DISTNAME=	newlib-3.0.0
VERSION=	3.0.0
PKGNAME=	${CONFIG}-newlib-${VERSION}

GH_ACCOUNT =	espressif
GH_PROJECT =	newlib-esp32
GH_TAGNAME =	esp32-2019r1_newlib-3_0_0

CONFIGURE_ENV=CC_FOR_TARGET="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-gcc"

MAKE_ENV+=	${CONFIGURE_ENV}

HOMEPAGE=	http://sourceware.org/newlib/

# MASTER_SITES=	ftp://sourceware.org/pub/newlib/

# EXTRACT_SUFX=	.tar.gz

BUILD_DEPENDS=	devel/${CONFIG}/binutils \
		${RUN_DEPENDS}
RUN_DEPENDS=	devel/${CONFIG}/gcc-esp32-bootstrap

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	CFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	Yes
USE_GROFF=	No
CONFIGURE_ARGS+=--enable-interwork \
		--enable-multilib \
		--enable-languages=c,c++ \
		--disable-newlib-supplied-syscalls

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/newlib
	${INSTALL_DATA} ${WRKDIST}/COPYING.NEWLIB \
		${PREFIX}/share/doc/newlib

.include <bsd.port.mk>
