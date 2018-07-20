# $OpenBSD$

XTENSAPRE =		xtensa-lx106-elf

V =			4.8.5
COMMENT =		${XTENSAPRE} cross compiler
DISTNAME =		${XTENSAPRE}-${V}

GH_ACCOUNT =		jcmvbkbc
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
	@cp -r ${WRKSRC}/local-patches ${INSTALL_DIR}
	@cp -r ${WRKSRC}/overlays ${INSTALL_DIR}
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

BINFILES = 	${XTENSAPRE}-addr2line ${XTENSAPRE}-c++filt \
		${XTENSAPRE}-elfedit ${XTENSAPRE}-gcc-ar ${XTENSAPRE}-gdb \
		${XTENSAPRE}-nm ${XTENSAPRE}-readelf ${XTENSAPRE}-ar \
		${XTENSAPRE}-cc ${XTENSAPRE}-g++ ${XTENSAPRE}-gcc-nm \
		${XTENSAPRE}-gprof ${XTENSAPRE}-objcopy ${XTENSAPRE}-size \
		${XTENSAPRE}-as ${XTENSAPRE}-cpp ${XTENSAPRE}-gcc \
		${XTENSAPRE}-gcc-ranlib ${XTENSAPRE}-ld ${XTENSAPRE}-objdump \
		${XTENSAPRE}-strings ${XTENSAPRE}-c++ ${XTENSAPRE}-ct-ng.config \
		${XTENSAPRE}-gcc-4.8.5 ${XTENSAPRE}-gcov ${XTENSAPRE}-ld.bfd \
		${XTENSAPRE}-ranlib ${XTENSAPRE}-strip

BUILDDIR =	${WRKSRC}/builds/${XTENSAPRE}

do-install:
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${BUILDDIR}/bin/${i} \
		${PREFIX}/bin/
.endfor
	@cp -r ${BUILDDIR}/lib/gcc \
		${PREFIX}/lib/
	@cp -r ${BUILDDIR}/lib/ldscripts \
		${PREFIX}/lib/
	@cp ${BUILDDIR}/libexec/gcc/${XTENSAPRE}/${V}/liblto_plugin.so.0.0 \
		${BUILDDIR}/libexec/gcc/${XTENSAPRE}/${V}/liblto_plugin.so
	@cp -r ${BUILDDIR}/libexec/gcc \
		${PREFIX}/libexec/
	@cp -r ${BUILDDIR}/${XTENSAPRE} \
		${PREFIX}/

.include <bsd.port.mk>
