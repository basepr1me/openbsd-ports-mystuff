# $OpenBSD$

XTENSAPRE =		xtensa-esp32-elf

V =			5.2.0
COMMENT =		${XTENSAPRE} cross compiler
DISTNAME =		${XTENSAPRE}-${V}

GH_ACCOUNT =		espressif
GH_PROJECT =		crosstool-NG
GH_TAGNAME =		xtensa-1.22.x

CATEGORIES =		devel

MAINTAINER =            Tracey Emery <tracey@traceyemery.net>

WANTLIB +=		c curses expat m stdc++ z

#multiple licenses ... figure out how to list
PERMIT_PACKAGE_CDROM =	Yes

BUILD_DEPENDS ?=	${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS} \
			archivers/bzip2 \
			archivers/gtar \
			archivers/unzip \
			devel/bison \
			devel/git \
			devel/gpatch \
			devel/gperf \
			devel/metaauto \
			lang/gawk \
			net/wget \
			shells/bash \
			sysutils/ggrep \
			textproc/gsed

USE_GMAKE =		Yes

CONFIGURE_STYLE =	automake
AUTOCONF_VERSION =	2.69

CONFIGURE_ARGS +=	--prefix=${WRKSRC} \
			--enable-local \
			--with-automake=${LOCALBASE}/bin/automake \
			--with-make=${LOCALBASE}/bin/gmake \
			--with-libtool=${LOCALBASE}/bin/libtool \
			--with-libtool=${LOCALBASE}/bin/libtoolize

NO_TEST =		Yes
SHARED_LIBS +=		lto_plugin 0.0 # 0.0

pre-configure:
	@cd ${WRKSRC} && env AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		sh ./bootstrap

INSTALL_DIR =		${WRKSRC}/lib/ct-ng.1.22.x

post-configure:
	@mkdir -p ${INSTALL_DIR}
	${SUDO} cp -r ${WRKSRC}/local-patches ${INSTALL_DIR}
	${SUDO} cp -r ${WRKSRC}/overlays ${INSTALL_DIR}
	@cd ${WRKSRC} && gmake && gmake install && \
		./ct-ng ${XTENSAPRE}
	@cat ${FILESDIR}/crosstool-config-overrides >> ${WRKSRC}/.config
	@sed -i "s,patch ,gpatch ," \
		${WRKSRC}/scripts/functions
	@sed -i "s,tar ,gtar ," \
		${WRKSRC}/scripts/build/kernel/linux.sh \
		${WRKSRC}/scripts/functions \
		${WRKSRC}/scripts/build/arch/xtensa.sh
	@sed -i "s,ln -sv,ln -s," \
		${WRKSRC}/scripts/build/binutils/binutils.sh
	@sed -i "s,ln -sfv,ln -sf," \
		${WRKSRC}/scripts/build/cc/100-gcc.sh
	@sed -i "s,cp -a,cp -r," \
		${WRKSRC}/scripts/build/binutils/binutils.sh \
		${WRKSRC}/scripts/build/cc/100-gcc.sh \
		${WRKSRC}/scripts/build/debug/200-duma.sh \
		${WRKSRC}/scripts/build/debug/400-ltrace.sh \
		${WRKSRC}/scripts/build/libc/glibc.sh \
		${WRKSRC}/scripts/build/libc/mingw.sh \
		${WRKSRC}/scripts/build/libc/musl.sh \
		${WRKSRC}/scripts/build/libc/newlib.sh \
		${WRKSRC}/scripts/build/libc/uClibc.sh \
		${WRKSRC}/scripts/build/test_suite/gcc.sh

do-build:
	@sed -i "s,ln -sfv,ln -sf," \
		${WRKSRC}/scripts/build/internals.sh
	@cd ${WRKSRC} && ./ct-ng build

BINFILES = ${XTENSAPRE}-addr2line ${XTENSAPRE}-cc ${XTENSAPRE}-gcc \
	   ${XTENSAPRE}-gcov ${XTENSAPRE}-ld.bfd ${XTENSAPRE}-readelf \
	   ${XTENSAPRE}-ar ${XTENSAPRE}-cpp ${XTENSAPRE}-gcc-5.2.0 \
	   ${XTENSAPRE}-gcov-tool ${XTENSAPRE}-nm ${XTENSAPRE}-size \
	   ${XTENSAPRE}-as ${XTENSAPRE}-ct-ng.config ${XTENSAPRE}-gcc-ar \
	   ${XTENSAPRE}-gdb ${XTENSAPRE}-objcopy ${XTENSAPRE}-strings \
	   ${XTENSAPRE}-c++ ${XTENSAPRE}-elfedit ${XTENSAPRE}-gcc-nm \
	   ${XTENSAPRE}-gprof ${XTENSAPRE}-objdump ${XTENSAPRE}-strip \
	   ${XTENSAPRE}-c++filt ${XTENSAPRE}-g++ ${XTENSAPRE}-gcc-ranlib \
	   ${XTENSAPRE}-ld ${XTENSAPRE}-ranlib

BUILDDIR =	${WRKSRC}/builds/${XTENSAPRE}

do-install:
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${BUILDDIR}/bin/${i} \
		${PREFIX}/bin/
.endfor
	${SUDO} cp -r ${BUILDDIR}/lib/gcc \
		${PREFIX}/lib/
	${SUDO} cp ${BUILDDIR}/libexec/gcc/${XTENSAPRE}/5.2.0/liblto_plugin.so.0.0 \
		${BUILDDIR}/libexec/gcc/${XTENSAPRE}/5.2.0/liblto_plugin.so
	${SUDO} cp -r ${BUILDDIR}/libexec/gcc \
		${PREFIX}/libexec/
	${SUDO} cp -r ${BUILDDIR}/${XTENSAPRE} \
		${PREFIX}/

.include <bsd.port.mk>
