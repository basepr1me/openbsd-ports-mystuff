# $OpenBSD: $
USE_NINJA =	No

COMMENT =	weak signal ham radio communication
DISTNAME =	wsjtx-2.4.0
CATEGORIES =	comms

HOMEPAGE =	https://physics.princeton.edu/pulsar/k1jt/wsjtx.html
MAINTAINER =	Tracey Emery <tracey@openbsd.org>

# GPLv3+
PERMIT_PACKAGE = Yes

MASTER_SITES =   ${MASTER_SITE_SOURCEFORGE:=wsjt/}
EXTRACT_SUFX =	.tgz

MODULES =       devel/cmake \
		fortran \
		x11/qt5

BUILD_DEPENDS =	textproc/asciidoctor \
		textproc/asciidoc
LIB_DEPENDS =	comms/hamlib \
		devel/boost \
		math/fftw3,float \
		x11/qt5/qtbase \
		x11/qt5/qtmultimedia \
		x11/qt5/qtserialport
RUN_DEPENDS =	devel/desktop-file-utils

WANTLIB += ${COMPILER_LIBCXX} Qt5Core Qt5Gui Qt5Multimedia Qt5Network
WANTLIB += Qt5PrintSupport Qt5SerialPort Qt5Sql Qt5Widgets boost_atomic-mt
WANTLIB += boost_chrono-mt boost_date_time-mt boost_filesystem-mt
WANTLIB += boost_log-mt boost_log_setup-mt boost_regex-mt boost_thread-mt
WANTLIB += c curses fftw3f fftw3f_threads hamlib m readline usb
WANTLIB += usb-1.0

.include <bsd.port.mk>
