COMMENT=	newlib for ${CONFIG} cross-development

DISTNAME=	newlib-2.2.0-1
VERSION=	2.2.0.1
PKGNAME=	${CONFIG}-newlib-${VERSION}
REVISION=	2

MAKE_ENV+=	${CONFIGURE_ENV}

HOMEPAGE=	http://sourceware.org/newlib/

MASTER_SITES=	ftp://sourceware.org/pub/newlib/
#MASTER_SITES=	ftp://sources.redhat.com/pub/newlib/

EXTRACT_SUFX=	.tar.gz

BUILD_DEPENDS=	devel/${CONFIG}/binutils \
		devel/${CONFIG}/gcc-bootstrap
RUN_DEPENDS=	devel/${CONFIG}/binutils

CONFIGURE_ENV=	CC_FOR_TARGET="${INSTALLDIR}/bootstrap/bin/${CONFIG}-gcc" \
		AR_FOR_TARGET="${INSTALLDIR}/bin/${CONFIG}-ar" \
		RANLIB_FOR_TARGET="${INSTALLDIR}/bin/${CONFIG}-ranlib"
CONFIGURE_ARGS+=--enable-interwork \
		--with-as="${INSTALLDIR}/bin/${CONFIG}-as" \
		--with-ld="${INSTALLDIR}/bin/${CONFIG}-ld" \
		--enable-multilib

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${CONFIG}/newlib
	${INSTALL_DATA} ${WRKDIST}/COPYING.NEWLIB \
		${PREFIX}/share/doc/${CONFIG}/newlib

.include <bsd.port.mk>
