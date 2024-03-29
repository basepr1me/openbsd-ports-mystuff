# Sync cad/kicad-share/Makefile.inc with archs where kicad is broken
BROKEN-powerpc =	segfaults when trying to run the PCB editor
BROKEN-sparc64 =	missing needed libcontext asm, unsupported by kicad devs

DPB_PROPERTIES =	parallel

V =			7.0.8
COMMENT =		schematic and PCB editing software
DISTNAME =		kicad-${V}
EPOCH =			0

SHARED_LIBS +=		kicad_3dsg                1.0 # 2.0

CATEGORIES =		cad

HOMEPAGE =		https://www.kicad.org

#GPLv3
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} EGL GL GLU TKBO TKBRep TKBin TKBinL
WANTLIB += TKBinTObj TKBinXCAF TKBool TKCAF TKCDF TKFeat TKFillet
WANTLIB += TKG2d TKG3d TKGeomAlgo TKGeomBase TKHLR TKIGES TKLCAF
WANTLIB += TKMath TKMesh TKMeshVS TKOffset TKOpenGl TKPrim TKSTEP
WANTLIB += TKSTEP209 TKSTEPAttr TKSTEPBase TKSTL TKService TKShHealing
WANTLIB += TKTObj TKTopAlgo TKV3d TKVRML TKXCAF TKXDEIGES TKXDESTEP
WANTLIB += TKXMesh TKXSBase TKXml TKXmlL TKXmlTObj TKXmlXCAF TKernel
WANTLIB += atk-1.0 c cairo cairo-gobject curl fontconfig freetype
WANTLIB += gdk-3 gdk_pixbuf-2.0 gio-2.0 glib-2.0 gobject-2.0 gtk-3
WANTLIB += harfbuzz intl m ngspice odbc pango-1.0 pangocairo-1.0
WANTLIB += pixman-1 python3.10 wx_baseu-3.2 wx_baseu_net-3.2 wx_baseu_xml-3.2
WANTLIB += wx_gtk3u_aui-3.2 wx_gtk3u_core-3.2 wx_gtk3u_gl-3.2
WANTLIB += wx_gtk3u_html-3.2 wx_gtk3u_propgrid-3.2 wx_gtk3u_richtext-3.2
WANTLIB += wx_gtk3u_stc-3.2 z

SITES =			https://gitlab.com/kicad/code/kicad/-/archive/${V}/

COMPILER =		base-clang ports-gcc

MODULES =		devel/cmake \
			lang/python

BUILD_DEPENDS =		databases/unixodbc \
			devel/doxygen \
			devel/git \
			devel/boost \
			devel/re2c \
			devel/swig \
			graphics/freeglut \
			graphics/glm \
			misc/shared-mime-info

RUN_DEPENDS =		cad/kicad-share/footprints>=${V} \
			cad/kicad-share/packages3D>=${V} \
			cad/kicad-share/symbols>=${V} \
			cad/kicad-share/templates>=${V} \
			devel/desktop-file-utils \
			misc/shared-mime-info \
			x11/gtk+4,-guic

LIB_DEPENDS =		cad/ngspice/libngspice \
			cad/oce \
			databases/unixodbc \
			graphics/cairo \
			net/curl \
			x11/wxWidgets

CONFIGURE_ARGS +=	-DCMAKE_BUILD_TYPE=Release \
			-DwxWidgets_CONFIG_EXECUTABLE=${LOCALBASE}/bin/wx-config \
			-DwxWidgets_LIBRARIES="${LOCALBASE}/lib" \
			-DwxWidgets_INCLUDE_DIRS="${LOCALBASE}/include/wx-3.0" \
			-DOCC_INCLUDE_DIR="${LOCALBASE}/include/opencascade" \
			-DOCC_LIBRARY_DIR="${LOCALBASE}/lib/opencascade" \
			-DKICAD_SCRIPTING_WXPYTHON=OFF \
			-DKICAD_USE_EGL=ON

# KHR/khrplatform.h
CFLAGS +=		-I${X11BASE}/include
CXXFLAGS +=		-I${X11BASE}/include

DEBUG_PACKAGES =	${BUILD_PACKAGES}

NO_TEST =		Yes

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/demos/python_scripts_examples/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/lib/python${MODPY_VERSION}/site-packages/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/plugins/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/scripting/kicad_pyshell/
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/kicad/scripting/plugins/

.include <bsd.port.mk>
