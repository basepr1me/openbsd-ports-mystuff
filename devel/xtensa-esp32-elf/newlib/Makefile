# $OpenBSD$

COMMENT=	newlib for ${CONFIG} cross-development

DISTNAME=	newlib-2.2.0-1
VERSION=	2.2.0.1
PKGNAME=	${CONFIG}-newlib-${VERSION}

CONFIGURE_ENV=	CC_FOR_TARGET="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-gcc"

MAKE_ENV+=	${CONFIGURE_ENV}

HOMEPAGE=	http://sourceware.org/newlib/

MASTER_SITES=	ftp://sourceware.org/pub/newlib/
#MASTER_SITES=	ftp://sources.redhat.com/pub/newlib/

EXTRACT_SUFX=	.tar.gz

BUILD_DEPENDS=	devel/${CONFIG}/binutils \
		${RUN_DEPENDS}
RUN_DEPENDS=	devel/${CONFIG}/gcc-bootstrap

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	CFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	Yes
USE_GROFF=	No
CONFIGURE_ARGS+=--enable-interwork \
		--enable-multilib \
		--enable-languages=c,c++ \
		--disable-newlib-supplied-syscalls

pre-configure:
	@cp -r ${FILESDIR}/esp32/* ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/newlib
	${INSTALL_DATA} ${WRKDIST}/COPYING.NEWLIB \
		${PREFIX}/share/doc/newlib
	${INSTALL_DATA} ${WRKDIST}/newlib/libc/sys/xtensa/include/xtensa/simcall-errno.h \
		${PREFIX}/${CONFIG}/include/xtensa
	${INSTALL_DATA} ${WRKDIST}/newlib/libc/sys/xtensa/include/xtensa/simcall-fcntl.h \
		${PREFIX}/${CONFIG}/include/xtensa

.include <bsd.port.mk>
