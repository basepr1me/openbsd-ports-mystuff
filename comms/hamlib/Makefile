# $OpenBSD: Makefile,v 1.42 2021/02/23 19:39:10 sthen Exp $

COMMENT-main=	radio/rotator control library
COMMENT-python=	python bindings for hamlib
COMMENT-tcl=	tcl bindings for hamlib

VERSION=	4.2
DISTNAME=	hamlib-${VERSION}
PKGNAME-main=	hamlib-${VERSION}
PKGNAME-python=	hamlib-python-${VERSION}
PKGNAME-tcl=	hamlib-tcl-${VERSION}
CATEGORIES=	comms hamradio

MULTI_PACKAGES=	-main -python -tcl

SHARED_LIBS +=	hamlib               4.0      # 2.16
SHARED_LIBS +=	hamlib++             4.0      # 2.16

HOMEPAGE=	http://hamlib.sourceforge.net/

MODULES=	lang/python \
		lang/tcl
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_2}

# GPLv2/LGPLv2.1
PERMIT_PACKAGE=	Yes

COMPILER =		base-clang ports-gcc base-gcc

LIBTOOL_FLAGS=		--tag=disable-static

cWANTLIB=		m pthread usb usb-1.0
WANTLIB-main=		${cWANTLIB} c ${COMPILER_LIBCXX}
WANTLIB-main +=		ltdl xml2 curses readline
WANTLIB-main +=		perl # uses perl ABI
WANTLIB-python=		${cWANTLIB} hamlib ${MODPY_WANTLIB} iconv intl util
# WANTLIB-tcl=		${cWANTLIB} hamlib ${MODTCL_WANTLIB}

LIB_DEPENDS-main=	textproc/libxml \
			devel/libusb-compat \
			devel/libtool,-ltdl \
			${MODGCC4_CPPLIBDEP}
LIB_DEPENDS-python=	${BUILD_PKGPATH} \
			${MODPY_LIB_DEPENDS}
LIB_DEPENDS-tcl=	${BUILD_PKGPATH} \
			${MODTCL_LIB_DEPENDS}

BUILD_DEPENDS=		devel/swig

RUN_DEPENDS-main=
RUN_DEPENDS-python=	${MODPY_RUN_DEPENDS}
RUN_DEPENDS-tcl=	${MODTCL_RUN_DEPENDS}

MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=hamlib/}

CONFIGURE_STYLE=	gnu
CONFIGURE_ARGS=		--with-cxx-binding \
			--with-perl-binding \
			--with-rpc-backends \
			--enable-tcl-binding \
			--with-python-binding \
			--without-rigmatrix \
			--with-tcl=${MODTCL_LIBDIR}
CONFIGURE_ENV=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			LIBUSB_CFLAGS="-lusb"

post-install:
	rm -f ${PREFIX}/lib/hamlib/*.la

.include <bsd.port.mk>
