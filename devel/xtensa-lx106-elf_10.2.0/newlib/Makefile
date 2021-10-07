# $OpenBSD: Makefile,v 1.2 2020/04/05 21:55:02 tracey Exp $

COMMENT =	newlib for ${CONFIG} cross-development

VERSION =	4.0.0
DISTNAME =	newlib-${VERSION}
PKGNAME =	${CONFIG}-newlib-${VERSION}

GH_ACCOUNT =	earlephilhower
GH_PROJECT =	newlib-xtensa
GH_COMMIT =	85c33ba4523820f1525aa4045cb5d7393b7b1e79

BUILD_DEPENDS =	devel/${CONFIG}/binutils \
		devel/${CONFIG}/gcc-bootstrap




CE_VARS =		"-mlongcalls -Os -g -free -fipa-pta"
CONFIGURE_ENV =		CFLAGS_FOR_TARGET=${CE_VARS} \
			CXXFLAGS_FOR_TARGET=${CE-VARS} \
			CFLAGS="-I${INSTALLDIR}/include -pipe" \
			LDFLAGS="-L${INSTALLDIR}/lib"




#CONFIGURE_ENV +=	CC_FOR_TARGET="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-cc" \

CONFIGURE_ARGS =	--target=${CONFIG} \
			--prefix=${INSTALLDIR} \
			--with-newlib \
			--enable-multilib \
			--disable-newlib-io-c99-formats \
			--disable-newlib-supplied-syscalls \
			--enable-newlib-nano-formatted-io \
			--enable-newlib-reent-small \
			--enable-target-optspace \
			--disable-option-checking \
			--disable-shared

.include <bsd.port.mk>
