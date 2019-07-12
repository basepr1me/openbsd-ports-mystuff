# $OpenBSD$

COMMENT=	binutils for ${CONFIG} cross-development

VERSION=	2.31
DISTNAME=	binutils-esp32-${VERSION}

DIST_SUBDIR=	binutils-esp32

# GH_ACCOUNT =	espressif
# GH_PROJECT =	binutils-gdb
# GH_TAGNAME =	esp32-2019r1_binutils-2_31

MASTER_SITES=	https://packages.traceyemery.net/distfiles/

HOMEPAGE=	https://www.gnu.org/software/binutils/

WANTLIB=	c

USE_LIBTOOL=	No

CONFIGURE_ENV +="CXXFLAGS=-O2 -g -pipe"
CONFIGURE_ARGS+=--disable-werror \
		--enable-ld=yes \
		--enable-gold=no \
		--enable-multilib \
		--disable-sim \
		--disable-gdb \
		--disable-nls \
		--with-sysroot=${LOCALBASE}/${CONFIG} \
		--disable-option-checking \
		--with-gnu-ld \
		--with-gnu-as \
		--with-newlib

WRKDIST=	${WRKDIR}/binutils

.include <bsd.port.mk>
