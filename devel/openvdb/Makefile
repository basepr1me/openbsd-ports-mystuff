# $OpenBSD$

COMMENT =		a C++ library for sparse volume data structure and tools

GH_ACCOUNT =		AcademySoftwareFoundation
GH_PROJECT =		openvdb
GH_TAGNAME =		v6.0.0 #7.0.0 required newer zlib than we ship

PKGNAME =		${GH_PROJECT}-${GH_TAGNAME:S/v//}

CATEGORIES =		devel

SHARED_LIBS +=		openvdb                   0.0 # 6.0

WANTLIB += GL GLU Half-2_4 Iex-2_4 IlmImf-2_4 IlmThread-2_4 X11
WANTLIB += Xcursor Xi Xinerama Xrandr Xxf86vm blosc boost_iostreams-mt
WANTLIB += boost_system-mt boost_thread-mt c glfw m pthread python3.7m
WANTLIB += stdc++ tbb z

#MPL-2.0
PERMIT_PACKAGE =	Yes

COMPILER=		base-gcc ports-gcc

MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}
MODULES =		devel/cmake \
			lang/python

BUILD_DEPENDS =		archivers/blosc \
			devel/boost \
			graphics/glew \
			graphics/glfw \
			graphics/openexr
LIB_DEPENDS =		archivers/blosc \
			devel/boost \
			devel/tbb \
			graphics/glfw \
			graphics/openexr

CONFIGURE_ENV =		CXXFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include ${CXXFLAGS}"
CONFIGURE_ARGS =	-DBLOSC_LOCATION="${LOCALBASE}" \
			-DTBB_LOCATION="${LOCALBASE}" \
			-DILMBASE_LOCATION="${LOCALBASE}" \
			-DOPENEXR_LOCATION="${LOCALBASE}" \
			-DUSE_GLFW3=ON \
			-DOPENVDB_BUILD_UNITTESTS=OFF \
			-DOPENVDB_ABI_VERSION_NUMBER=6 \
			-DGLFW3_LOCATION="${LOCALBASE}"

NO_TEST =		Yes

.include <bsd.port.mk>
