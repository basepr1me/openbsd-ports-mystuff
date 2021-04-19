# $OpenBSD: $

COMMENT =	vendor and platform neutral SDR support library

V =		0.7.2
DISTNAME =	soapy-sdr-${V}
# PKGNAME =	sdr++-${V}

GH_ACCOUNT =	pothosware
GH_PROJECT =	SoapySDR
GH_TAGNAME =	${DISTNAME}

SHARED_LIBS +=  SoapySDR		0.0 # 0.7

CATEGORIES =	comms

HOMEPAGE =	https://github.com/pothosware/SoapySDR

# Boost v1.0
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} c intl m util

COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake \
		lang/python

BUILD_DEPENDS =	devel/doxygen \
		devel/swig

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/lib/python${MODPY_VERSION}/site-packages/SoapySDR.py

.include <bsd.port.mk>
