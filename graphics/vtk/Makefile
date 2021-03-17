# $OpenBSD$

COMMENT =		image processing, 3D graphics and volume rendering

V =			9.0.1
DISTNAME =		VTK-${V}
PKGNAME =		vtk-${V}

.for LIB in vtkChartsCore vtkCommonColor vtkCommonComputationalGeometry \
	vtkCommonCore vtkCommonDataModel vtkCommonExecutionModel vtkCommonMath \
	vtkCommonMisc vtkCommonSystem vtkCommonTransforms vtkDICOMParser \
	vtkDomainsChemistry vtkFiltersAMR vtkFiltersCore vtkFiltersExtraction \
	vtkFiltersFlowPaths vtkFiltersGeneral vtkFiltersGeneric \
	vtkFiltersGeometry vtkFiltersHybrid vtkFiltersHyperTree \
	vtkFiltersImaging vtkFiltersModeling vtkFiltersParallel \
	vtkFiltersParallelImaging vtkFiltersPoints vtkFiltersProgrammable \
	vtkFiltersSMP vtkFiltersSelection vtkFiltersSources vtkFiltersStatistics \
	vtkFiltersTexture vtkFiltersTopology vtkFiltersVerdict vtkGeovisCore \
	vtkIOAMR vtkIOAsynchronous vtkIOCityGML vtkIOCore vtkIOEnSight \
	vtkIOExodus vtkIOExport vtkIOExportGL2PS vtkIOExportPDF vtkIOGeometry \
	vtkIOImage vtkIOImport vtkIOInfovis vtkIOLSDyna vtkIOLegacy vtkIOMINC \
	vtkIOMotionFX vtkIOMovie vtkIONetCDF vtkIOOggTheora vtkIOPLY \
	vtkIOParallel vtkIOParallelXML vtkIOSQL vtkIOSegY vtkIOTecplotTable \
	vtkIOVeraOut vtkIOVideo vtkIOXML vtkIOXMLParser vtkImagingColor \
	vtkImagingCore vtkImagingFourier vtkImagingGeneral vtkImagingHybrid \
	vtkImagingMath vtkImagingMorphological vtkImagingSources \
	vtkImagingStatistics vtkImagingStencil vtkInfovisCore vtkInfovisLayout \
	vtkInteractionImage vtkInteractionStyle vtkInteractionWidgets \
	vtkParallelCore vtkParallelDIY vtkRenderingAnnotation \
	vtkRenderingContext2D vtkRenderingCore vtkRenderingFreeType \
	vtkRenderingGL2PSOpenGL2 vtkRenderingImage vtkRenderingLOD \
	vtkRenderingLabel vtkRenderingOpenGL2 vtkRenderingSceneGraph \
	vtkRenderingUI vtkRenderingVolume vtkRenderingVolumeOpenGL2 \
	vtkRenderingVtkJS vtkTestingRendering vtkViewsContext2D vtkViewsCore \
	vtkViewsInfovis vtkWrappingTools vtkdoubleconversion vtkexodusII \
	vtkexpat vtkfreetype vtkgl2ps vtkglew vtkhdf5 vtkhdf5_hl vtkjpeg \
	vtkjsoncpp vtklibharu vtklibproj vtklibxml2 vtkloguru vtklz4 vtklzma \
	vtkmetaio vtknetcdf vtkogg vtkpng vtkpugixml vtksqlite vtksys vtktheora \
	vtktiff vtkverdict vtkzlib
SHARED_LIBS += ${LIB} 0.0
.endfor

CATEGORIES =		graphics

HOMEPAGE =		https://www.vtk.org/

MAINTAINER =		Paco Esteban <paco@openbsd.org>

# BSD
PERMIT_PACKAGE =	Yes

MASTER_SITES =		https://www.vtk.org/files/release/${V:R}/

WANTLIB += ${COMPILER_LIBCXX} GL GLU X11 c execinfo m

COMPILER =		base-clang ports-gcc

MODULES =		devel/cmake

LIB_DEPENDS =		devel/libexecinfo

NO_TEST =		Yes

CONFIGURE_ARGS =	-DCMAKE_CXX_FLAGS="${CXXFLAGS} -I${LOCALBASE}/include"

.include <bsd.port.mk>
