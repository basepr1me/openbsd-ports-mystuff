# $OpenBSD: Makefile,v 1.3 2020/04/30 21:05:03 cwen Exp $

BROKEN-powerpc = kicad is broken, this is the only consumer (save bulk time)

COMMENT =	C++ 3d modeling library
DPB_PROPERTIES = parallel

GH_ACCOUNT =	tpaviot
GH_PROJECT =	oce
GH_COMMIT =	98a788062f0f30593880b0df1bcf967408212ba4
DISTNAME =	oce-7.6.0

.for LIB in FWOSPlugin PTKernel TKBO TKBRep TKBin TKBinL TKBinTObj TKBinXCAF \
	TKBool TKCAF TKCDF TKFeat TKFillet TKG2d TKG3d TKGeomAlgo TKGeomBase \
	TKHLR TKIGES TKLCAF TKMath TKMesh TKMeshVS TKNIS TKOffset TKOpenGl \
	TKPCAF TKPLCAF TKPShape TKPrim TKSTEP TKSTEP209 TKSTEPAttr TKSTEPBase \
	TKSTL TKService TKShHealing TKShapeSchema TKStdLSchema TKStdSchema \
	TKTObj TKTopAlgo TKV3d TKVRML TKVoxel TKXCAF TKXCAFSchema TKXDEIGES \
	TKXDESTEP TKXMesh TKXSBase TKXml TKXmlL TKXmlTObj TKXmlXCAF TKernel \
	TKDCAF TKDraw TKTObjDRAW TKTopTest TKViewerTest TKXDEDRAW TKXSDRAW
SHARED_LIBS += ${LIB} 1.0
.endfor

CATEGORIES =		cad

# LGPLv2.1
PERMIT_PACKAGE =	Yes

WANTLIB += ${MODTK_WANTLIB} ${COMPILER_LIBCXX}
WANTLIB += GL GLU ICE SM X11 Xext Xi c fontconfig freetype m pthread

NO_TEST =		Yes

COMPILER =		base-clang ports-gcc

MODULES =		devel/cmake \
			x11/tk
MODTK_VERSION =		8.6

LIB_DEPENDS =		${MODTK_LIB_DEPENDS}
RUN_DEPENDS =		shells/bash

CONFIGURE_ARGS +=	-DCMAKE_CXX_FLAGS="-I${X11BASE}/include ${CXXFLAGS}" \
			-DCMAKE_BUILD_TYPE="Release"

.include <bsd.port.mk>
