# $OpenBSD$

COMMENT =		a C++ library for sparse volume data structure and tools

GH_ACCOUNT =		AcademySoftwareFoundation
GH_PROJECT =		openvdb
GH_TAGNAME =		v6.0.0 #7.0.0 required newer zlib than we ship

PKGNAME =		${GH_PROJECT}-${GH_TAGNAME:S/v//}

CATEGORIES =		devel

#MPL-2.0
PERMIT_PACKAGE =	Yes

COMPILER=		base-gcc ports-gcc

MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}
MODULES =		devel/cmake \
			lang/python

BUILD_DEPENDS =		archivers/blosc \
			devel/boost \
			devel/cppunit \
			graphics/glew \
			graphics/glfw \
			graphics/openexr

CONFIGURE_ENV =		CXXFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include -DOPENVDB_USE_GLFW_3 ${CXXFLAGS}" \
			LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS =	-DBLOSC_LOCATION="${LOCALBASE}" \
			-DTBB_LOCATION="${LOCALBASE}" \
			-DILMBASE_LOCATION="${LOCALBASE}" \
			-DOPENEXR_LOCATION="${LOCALBASE}" \
			-DCPPUNIT_LOCATION="${LOCALBASE}"


SEPARATE_BUILD =	Yes

.include <bsd.port.mk>
