# $OpenBSD$

COMMENT=	binutils for ${CONFIG} cross-development

VERSION=	2.31
DISTNAME=	binutils-${VERSION}

GH_ACCOUNT =	espressif
GH_PROJECT =	binutils-gdb
GH_TAGNAME =	esp32-2019r1_binutils-2_31

HOMEPAGE=	https://www.gnu.org/software/binutils/

WANTLIB=	c

# MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
# DIST_SUBDIR=	binutils

# USE_GMAKE=	Yes
USE_LIBTOOL=	No

CONFIGURE_ARGS+=--enable-commonbfdlib=no \
		--enable-interwork	 \
		--enable-multilib

.include <bsd.port.mk>
