CONFIG?=	arm-none-eabi
PKGNAME?=	${CONFIG}-${DISTNAME}
FULLPKGNAME?=	${PKGNAME}
CATEGORIES+=	devel

# GPLv3
# For newlib: multiple copyrights, but basically BSD.
#   See: ${PREFIX}/share/doc/newlib
PERMIT_PACKAGE=	Yes

COMPILER=	base-clang ports-clang

BUILD_DEPENDS+=	devel/bison \
		lang/gawk \
		sysutils/coreutils \
		textproc/gsed

SEPARATE_BUILD=	Yes
USE_GMAKE= 	Yes
YACC=		bison -y

INSTALLDIR=	${LOCALBASE}/${CONFIG}

CONFIGURE_STYLE?=simple

CONFIGURE_ARGS+=--target=${CONFIG} \
		--disable-shared \
		--disable-nls \
		--disable-werror

EXTRACT_SUFX?=	.tar.xz
