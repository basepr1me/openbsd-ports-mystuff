# $OpenBSD$

CONFIG=		xtensa-esp32-elf
PKGNAME?=	${CONFIG}-${DISTNAME}
CATEGORIES+=	devel

# GPLv3
# For newlib: multiple copyrights, but basically BSD.
#   See: ${PREFIX}/share/doc/newlib
PERMIT_PACKAGE=   Yes

# XXX at least gmkdir gets picked up if present
BUILD_DEPENDS+=	sysutils/coreutils

LANGS=		c,c++

CONFIGURE_STYLE=gnu
CONFIGURE_ARGS+=--target=${CONFIG} \
		--enable-languages=${LANGS} \
		--disable-shared \
		--disable-nls \
		--disable-werror
