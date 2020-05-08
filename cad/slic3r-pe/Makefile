# $OpenBSD: $

COMMENT =		G-code generator for 3D printers (Prusa Edition)

V =			2.2.0
REVISION =		0
GH_ACCOUNT =		prusa3d

GH_PROJECT =		PrusaSlicer
GH_TAGNAME =		version_${V}
DISTNAME =		Slic3r-${GH_TAGNAME}
PKGNAME =		slic3r-pe-${V}

CATEGORIES =		cad graphics

HOMEPAGE =		https://www.prusa3d.com/slic3r-prusa-edition/

# MAINTAINER =		Klemens Nanni <kn@openbsd.org>

# AGPLv3
PERMIT_PACKAGE =	Yes

MODULES =		devel/cmake

BUILD_DEPENDS =		devel/cereal \
			devel/tbb \
			math/eigen3 \
			math/nlopt

WRKDIST =		${WRKDIR}/Prusa${DISTNAME:S/Slic3r/Slicer/}

.include <bsd.port.mk>
