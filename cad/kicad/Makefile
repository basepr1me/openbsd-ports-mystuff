# $OpenBSD$

V =			5.1.4
COMMENT =		schematic and PCB editing software
DISTNAME =		kicad-${V}

SHARED_LIBS +=		kicad_3dsg                2.0 # 2.0

CATEGORIES =		cad

HOMEPAGE =		https://github.com/KiCad/kicad-source-mirror

#GPLv3
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX}
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
			devel/desktop-file-utils \
			misc/shared-mime-info \
			x11/gtk+3,-guic

COMPILER =		ports-clang

MODULES =		devel/cmake \
			lang/python

#CONFIGURE_ARGS +=	-DCMAKE_BUILD_TYPE=Release \

CONFIGURE_ARGS +=	-DCMAKE_BUILD_TYPE=Debug \
			-DwxWidgets_CONFIG_EXECUTABLE=${LOCALBASE}/bin/wx-config \
			-DwxWidgets_LIBRARIES="${LOCALBASE}/lib" \
			-DwxWidgets_INCLUDE_DIRS="${LOCALBASE}/include/wx-3.0" \
			-DKICAD_USE_OCE=ON \
			-DOCE_DIR="${LOCALBASE}/include/oce" \
			-DKICAD_USE_OCC=OFF \
			-DKICAD_SPICE=ON \
			-DKICAD_SCRIPTING=OFF \
			-DKICAD_SCRIPTING_MODULES=OFF \
			-DKICAD_SCRIPTING_WXPYTHON=OFF

NO_TEST =		Yes

pre-build:
	@sed -i "s,-lrt,," \
		${WRKDIR}/build-amd64/build.ninja

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/demos/python_scripts_examples/action_menu_add_automatic_border.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/demos/python_scripts_examples/action_menu_text_by_date.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/demos/python_scripts_examples/action_plugin_test_undoredo.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/demos/python_scripts_examples/gen_gerber_and_drill_files_board.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/demos/python_scripts_examples/plot_board.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/plugins/bom_csv_grouped_by_value.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/plugins/bom_csv_grouped_by_value_with_fp.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/plugins/bom_csv_sorted_by_ref.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/plugins/bom_html_grouped_by_value.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/plugins/bom_html_with_advanced_grouping.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/plugins/bom_sorted_by_ref.py
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/plugins/kicad_netlist_reader.py


.include <bsd.port.mk>
