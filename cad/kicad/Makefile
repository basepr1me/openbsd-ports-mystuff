# $OpenBSD$

V =			5.1.4
COMMENT =		schematic and PCB editing software
DISTNAME =		kicad-${V}

SHARED_LIBS +=		kicad_3dsg                2.0 # 2.0

CATEGORIES =		cad

HOMEPAGE =		https://github.com/KiCad/kicad-source-mirror

PERMIT_PACKAGE =	Yes

# WANTLIB += GL GLU ICE SM X11 Xext c crypto freetype m pixman-1
# WANTLIB += GLEW PTKernel TKBO TKBRep TKBin TKBinL TKBinXCAF TKBool
# WANTLIB += TKCAF TKCDF TKFillet TKG2d TKG3d TKGeomAlgo TKGeomBase
# WANTLIB += TKHLR TKIGES TKLCAF TKMath TKMesh TKOffset TKPCAF TKPLCAF
# WANTLIB += TKPShape TKPrim TKSTEP TKSTEP209 TKSTEPAttr TKSTEPBase
# WANTLIB += TKService TKShHealing TKTopAlgo TKV3d TKXCAF TKXDEIGES
# WANTLIB += TKXDESTEP TKXSBase TKernel cairo curl
# WANTLIB += ssl ${COMPILER_LIBCXX}
# WANTLIB += wx_baseu-3.0 wx_baseu_net-3.0 wx_gtk3u_adv-3.0 wx_gtk3u_aui-3.0
# WANTLIB += wx_gtk3u_core-3.0 wx_gtk3u_gl-3.0 wx_gtk3u_html-3.0
# WANTLIB += wx_baseu_xml-3.0 wx_gtk3u_stc-3.0
# WANTLIB += boost_atomic-mt boost_chrono-mt boost_context-mt
# WANTLIB += boost_coroutine-mt boost_date_time-mt boost_system-mt
# WANTLIB += boost_thread-mt python2.7 ngspice

MASTER_SITES =		https://launchpad.net/kicad/5.0/${V}/+download/

EXTRACT_SUFX =		.tar.xz

BUILD_DEPENDS =		cad/libngspice \
			cad/ngspice \
			cad/oce \
			devel/boost \
			devel/cmake \
			devel/desktop-file-utils \
			devel/doxygen \
			devel/ninja \
			devel/re2c \
			devel/swig \
			graphics/cairo \
			graphics/freeglut \
			graphics/glew \
			graphics/glm \
			misc/shared-mime-info \
			net/curl \
			x11/wxWidgets

RUN_DEPENDS =		cad/kicad-symbols \
			cad/kicad-i18n \
			cad/kicad-footprints \
			cad/kicad-packages3D \
			cad/kicad-templates \
			x11/gtk+3,-guic

#https://lists.launchpad.net/kicad-developers/msg28514.html revert
#COMPILER =		base-clang ports-gcc
COMPILER =		ports-clang

MODULES =		devel/cmake

#CONFIGURE_ARGS +=	-DCMAKE_BUILD_TYPE=Release \

CONFIGURE_ARGS +=	-DCMAKE_BUILD_TYPE=Debug \
			-DwxWidgets_CONFIG_EXECUTABLE=${LOCALBASE}/bin/wx-config \
			-DwxWidgets_LIBRARIES="${LOCALBASE}/lib" \
			-DwxWidgets_INCLUDE_DIRS="${LOCALBASE}/include/wx-3.0" \
			-DKICAD_USE_OCE=ON \
			-DOCE_DIR="${LOCALBASE}/include/oce" \
			-DKICAD_USE_OCC=OFF \
			-DKICAD_SCRIPTING=OFF \
			-DKICAD_SCRIPTING_MODULES=OFF \
			-DKICAD_SCRIPTING_WXPYTHON=OFF \
			-DKICAD_SPICE=ON

NO_TEST =		Yes

pre-build:
	@sed -i "s,-lrt,," \
		${WRKDIR}/build-amd64/build.ninja
	# @sed -i "s,-std=gnu++11,-std=c++11," \
	# 	${WRKDIR}/build-amd64/build.ninja
.include <bsd.port.mk>
