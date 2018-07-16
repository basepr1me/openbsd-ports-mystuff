# $OpenBSD$

V =			1.0
COMMENT =		xtensa-lx106-elf cross compiler
DISTNAME =		xtensa-lx106-elf-g++-${V}

GH_ACCOUNT =		jcmvbkbc
GH_PROJECT =		crosstool-NG
GH_TAGNAME =		lx106-g++

CATEGORIES =		devel

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

WRKDIST =		${WRKDIR}/crosstool-NG-lx106-g-
WRKSRC =		${WRKDIST}
INSTALL_DIR =		${WRKSRC}/lib/ct-ng.1.20.0

post-configure:
	@mkdir -p ${INSTALL_DIR}
	@cp -r ${WRKSRC}/local-patches ${INSTALL_DIR}
	@cp -r ${WRKSRC}/overlays ${INSTALL_DIR}
	@cd ${WRKSRC} && gmake && gmake install && \
		./ct-ng xtensa-lx106-elf
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
		${WRKSRC}/scripts/build/internals.sh \
		${WRKSRC}/scripts/build/cc/gcc.sh
	@sed -i "s,cp -a,cp -r," \
		${WRKSRC}/scripts/build/binutils/binutils.sh \
		${WRKSRC}/scripts/build/debug/200-duma.sh \
		${WRKSRC}/scripts/build/debug/400-ltrace.sh \
		${WRKSRC}/scripts/build/libc/glibc.sh \
		${WRKSRC}/scripts/build/libc/mingw.sh \
		${WRKSRC}/scripts/build/libc/musl.sh \
		${WRKSRC}/scripts/build/libc/newlib.sh \
		${WRKSRC}/scripts/build/libc/uClibc.sh \
		${WRKSRC}/scripts/build/test_suite/gcc.sh \
		${WRKSRC}/scripts/build/cc/gcc.sh

do-build:
	@cd ${WRKSRC} && ./ct-ng build

BINFILES =	xtensa-lx106-elf-addr2line xtensa-lx106-elf-c++filt \
		xtensa-lx106-elf-elfedit xtensa-lx106-elf-gcc-ar \
		xtensa-lx106-elf-gdb xtensa-lx106-elf-nm \
		xtensa-lx106-elf-readelf xtensa-lx106-elf-ar \
		xtensa-lx106-elf-cc xtensa-lx106-elf-g++ \
		xtensa-lx106-elf-gcc-nm xtensa-lx106-elf-gprof \
		xtensa-lx106-elf-objcopy xtensa-lx106-elf-size \
		xtensa-lx106-elf-as xtensa-lx106-elf-cpp \
		xtensa-lx106-elf-gcc xtensa-lx106-elf-gcc-ranlib \
		xtensa-lx106-elf-ld xtensa-lx106-elf-objdump \
		xtensa-lx106-elf-strings xtensa-lx106-elf-c++ \
		xtensa-lx106-elf-ct-ng.config xtensa-lx106-elf-gcc-4.8.2 \
		xtensa-lx106-elf-gcov xtensa-lx106-elf-ld.bfd \
		xtensa-lx106-elf-ranlib xtensa-lx106-elf-strip

BUILDDIR =	${WRKSRC}/builds/xtensa-lx106-elf

do-install:
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${BUILDDIR}/bin/${i} \
		${PREFIX}/bin/
.endfor
	@cp -r ${BUILDDIR}/lib/gcc \
		${PREFIX}/lib/
	@cp -r ${BUILDDIR}/lib/ldscripts \
		${PREFIX}/lib/
	@cp -r ${BUILDDIR}/lib/libiberty.a \
		${PREFIX}/lib/
	@cp ${BUILDDIR}/libexec/gcc/xtensa-lx106-elf/4.8.2/liblto_plugin.so.0.0 \
		${BUILDDIR}/libexec/gcc/xtensa-lx106-elf/4.8.2/liblto_plugin.so
	@cp -r ${BUILDDIR}/libexec/gcc \
		${PREFIX}/libexec/
	@cp -r ${BUILDDIR}/xtensa-lx106-elf \
		${PREFIX}/

.include <bsd.port.mk>
