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

CONFIGURE_ENV +=	CC_FOR_TARGET="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-gcc" \
			AS_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-as" \
			AR_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-ar" \
			RANLIB_FOR_TARGET="${LOCALBASE}/bin/${CONFIG}-ranlib"
CONFIGURE_ARGS +=	--with-system-zlib \
			--with-as="${LOCALBASE}/bin/${CONFIG}-as" \
			--with-ld="${LOCALBASE}/bin/${CONFIG}-ld" \
			--with-newlib \
			--enable-multilib \
			--disable-newlib-io-c99-formats \
			--disable-newlib-supplied-syscalls \
			--enable-newlib-nano-formatted-io \
			--enable-newlib-reent-small \
			--enable-target-optspace \
			--disable-option-checking \
			--disable-shared \
			--with-system-zlib

.include <bsd.port.mk>
