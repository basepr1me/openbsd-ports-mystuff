# $OpenBSD$

V =			0.18.3
DISTNAME =		OCE-${V}
COMMENT =		c++ 3d modeling library

CATEGORIES =		cad
PKGNAME =		oce-${V}

HOMEPAGE =		https://github.com/tpaviot/oce

MASTER_SITES =		https://github.com/tpaviot/oce/archive/

MAINTAINER =		Tracey Emery <tracey@traceyemery.net>

SHARED_LIBS +=  FWOSPlugin                11.0 # 11.0
SHARED_LIBS +=  PTKernel                  11.0 # 11.0
SHARED_LIBS +=  TKBO                      11.0 # 11.0
SHARED_LIBS +=  TKBRep                    11.0 # 11.0
SHARED_LIBS +=  TKBin                     11.0 # 11.0
SHARED_LIBS +=  TKBinL                    11.0 # 11.0
SHARED_LIBS +=  TKBinTObj                 11.0 # 11.0
SHARED_LIBS +=  TKBinXCAF                 11.0 # 11.0
SHARED_LIBS +=  TKBool                    11.0 # 11.0
SHARED_LIBS +=  TKCAF                     11.0 # 11.0
SHARED_LIBS +=  TKCDF                     11.0 # 11.0
SHARED_LIBS +=  TKFeat                    11.0 # 11.0
SHARED_LIBS +=  TKFillet                  11.0 # 11.0
SHARED_LIBS +=  TKG2d                     11.0 # 11.0
SHARED_LIBS +=  TKG3d                     11.0 # 11.0
SHARED_LIBS +=  TKGeomAlgo                11.0 # 11.0
SHARED_LIBS +=  TKGeomBase                11.0 # 11.0
SHARED_LIBS +=  TKHLR                     11.0 # 11.0
SHARED_LIBS +=  TKIGES                    11.0 # 11.0
SHARED_LIBS +=  TKLCAF                    11.0 # 11.0
SHARED_LIBS +=  TKMath                    11.0 # 11.0
SHARED_LIBS +=  TKMesh                    11.0 # 11.0
SHARED_LIBS +=  TKMeshVS                  11.0 # 11.0
SHARED_LIBS +=  TKNIS                     11.0 # 11.0
SHARED_LIBS +=  TKOffset                  11.0 # 11.0
SHARED_LIBS +=  TKOpenGl                  11.0 # 11.0
SHARED_LIBS +=  TKPCAF                    11.0 # 11.0
SHARED_LIBS +=  TKPLCAF                   11.0 # 11.0
SHARED_LIBS +=  TKPShape                  11.0 # 11.0
SHARED_LIBS +=  TKPrim                    11.0 # 11.0
SHARED_LIBS +=  TKSTEP                    11.0 # 11.0
SHARED_LIBS +=  TKSTEP209                 11.0 # 11.0
SHARED_LIBS +=  TKSTEPAttr                11.0 # 11.0
SHARED_LIBS +=  TKSTEPBase                11.0 # 11.0
SHARED_LIBS +=  TKSTL                     11.0 # 11.0
SHARED_LIBS +=  TKService                 11.0 # 11.0
SHARED_LIBS +=  TKShHealing               11.0 # 11.0
SHARED_LIBS +=  TKShapeSchema             11.0 # 11.0
SHARED_LIBS +=  TKStdLSchema              11.0 # 11.0
SHARED_LIBS +=  TKStdSchema               11.0 # 11.0
SHARED_LIBS +=  TKTObj                    11.0 # 11.0
SHARED_LIBS +=  TKTopAlgo                 11.0 # 11.0
SHARED_LIBS +=  TKV3d                     11.0 # 11.0
SHARED_LIBS +=  TKVRML                    11.0 # 11.0
SHARED_LIBS +=  TKVoxel                   11.0 # 11.0
SHARED_LIBS +=  TKXCAF                    11.0 # 11.0
SHARED_LIBS +=  TKXCAFSchema              11.0 # 11.0
SHARED_LIBS +=  TKXDEIGES                 11.0 # 11.0
SHARED_LIBS +=  TKXDESTEP                 11.0 # 11.0
SHARED_LIBS +=  TKXMesh                   11.0 # 11.0
SHARED_LIBS +=  TKXSBase                  11.0 # 11.0
SHARED_LIBS +=  TKXml                     11.0 # 11.0
SHARED_LIBS +=  TKXmlL                    11.0 # 11.0
SHARED_LIBS +=  TKXmlTObj                 11.0 # 11.0
SHARED_LIBS +=  TKXmlXCAF                 11.0 # 11.0
SHARED_LIBS +=  TKernel                   11.0 # 11.0

#LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

NO_TEST =		Yes

BUILD_DEPENDS ?=	devel/ninja

MODULES =		devel/cmake

CXXFLAGS +=		"-I/usr/X11R6/include"

WRKDIST =		${WRKDIR}/oce-OCE-${V}
WRKSRC =		${WRKDIST}

.include <bsd.port.mk>
