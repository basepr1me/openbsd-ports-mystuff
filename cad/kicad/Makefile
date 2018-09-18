# $OpenBSD$

V =			5.0.0
COMMENT =		schematic and PCB editing software
DISTNAME =		kicad-${V}

CATEGORIES =		cad

HOMEPAGE =		https://github.com/KiCad/kicad-source-mirror

PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += GL GLU ICE SM X11 Xext c crypto freetype m pixman-1
WANTLIB += GLEW PTKernel TKBO TKBRep TKBin TKBinL TKBinXCAF TKBool
WANTLIB += TKCAF TKCDF TKFillet TKG2d TKG3d TKGeomAlgo TKGeomBase
WANTLIB += TKHLR TKIGES TKLCAF TKMath TKMesh TKOffset TKPCAF TKPLCAF
WANTLIB += TKPShape TKPrim TKSTEP TKSTEP209 TKSTEPAttr TKSTEPBase
WANTLIB += TKService TKShHealing TKTopAlgo TKV3d TKXCAF TKXDEIGES
WANTLIB += TKXDESTEP TKXSBase TKernel cairo curl
WANTLIB += ssl ${COMPILER_LIBCXX}
#WANTLIB += wx_baseu wx_baseu_net wx_gtk2u_adv wx_gtk2u_aui
#WANTLIB += wx_gtk2u_core wx_gtk2u_gl wx_gtk2u_html z

#MASTER_SITES =		https://github.com/KiCad/kicad-source-mirror/archive/${V}/
MASTER_SITES =		https://launchpad.net/kicad/${V:R}/${V}/+download/
COMPILER =		ports-clang
MODULES =		devel/cmake
#only for scripting			lang/python
EXTRACT_SUFX =		.tar.xz

BUILD_DEPENDS =		devel/boost \
			devel/cmake \
			devel/doxygen \
			devel/gettext-tools \
			devel/ninja \
			x11/wxWidgets
#only used for scripting			devel/swig
#			devel/git
#			net/curl
#		cad/ngspice


RUN_DEPENDS =		cad/kicad-symbols \
			cad/kicad-footprints \
			cad/kicad-packages3D \
			cad/kicad-i18n \
			cad/kicad-templates \
			devel/desktop-file-utils \
			misc/shared-mime-info \
			x11/gtk+3,-guic \
			x11/wxWidgets

LIB_DEPENDS =		cad/oce \
			graphics/cairo \
			graphics/glew \
			net/curl

SHARED_LIBS +=		kicad_3dsg                2.0 # 2.0

CONFIGURE_ARGS +=	-DwxWidgets_CONFIG_EXECUTABLE=${LOCALBASE}/bin/wx-config \
			-DwxWidgets_LIBRARIES="${LOCALBASE}/lib/wx" \
			-DwxWidgets_INCLUDE_DIRS="${LOCALBASE}/include/wx-3.0" \
			-DCMAKE_BUILD_TYPE=Release \
			-DKICAD_SCRIPTING_WXPYTHON=OFF \
			-DKICAD_SKIP_BOOST=ON

#
#			-DUSE_WX_GRAPHICS_CONTEXT=OFF \
#			-DUSE_WX_OVERLAY=OFF \
#			-DBUILD_GITHUB_PLUGIN=OFF \
#			-DKICAD_SCRIPTING_ACTION_MENU=OFF \
#			-DKICAD_SPICE=OFF \
#			-DKICAD_SCRIPTING=OFF \
#			-DKICAD_SCRIPTING_MODULES=OFF \
#
#
NO_TEST =		Yes

#WRKDIST =		${WRKDIR}/kicad-source-mirror-${V}
#WRKSRC =		${WRKDIST}

pre-configure:
	@cd ${WRKSRC}/eeschema/qa && mv CMakeLists.txt CMakeLists.txt.orig

#pre-build:
#	@sed -i "s,-lrt,," \
#		${WRKDIR}/build-amd64/build.ninja
pre-build:
	@sed -i "s,-lrt,-lpthread," \
		${WRKDIR}/build-amd64/build.ninja

.include <bsd.port.mk>
