# $OpenBSD$

COMMENT=	newlib for ${CONFIG} cross-development

DISTNAME=	newlib-2.2.0-1
VERSION=	2.2.0.1
PKGNAME=	${CONFIG}-newlib-${VERSION}

CONFIGURE_ENV=CC_FOR_TARGET="${LOCALBASE}/${CONFIG}/bootstrap/bin/${CONFIG}-gcc"

MAKE_ENV+=	${CONFIGURE_ENV}

HOMEPAGE=	http://sourceware.org/newlib/

MASTER_SITES=	ftp://sourceware.org/pub/newlib/

EXTRACT_SUFX=	.tar.gz

BUILD_DEPENDS=	devel/${CONFIG}/binutils \
		${RUN_DEPENDS}
RUN_DEPENDS=	devel/${CONFIG}/gcc-lx106-bootstrap

# cope with user settings in /etc/mk.conf
MAKE_FLAGS=	CFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	Yes
USE_GROFF=	No
CONFIGURE_ARGS+=--enable-interwork \
		--enable-multilib \
		--enable-languages=c,c++ \
		--disable-newlib-supplied-syscalls

post-extract:
	@cp -r ${FILESDIR}/* ${WRKSRC}
	@mkdir -p ${WRKSRC}/newlib/libc/machine/xtensa/
	@touch ${WRKSRC}/Makefile.am
	@touch ${WRKSRC}/aclocal.m4
	@touch ${WRKSRC}/configure.in
	@touch ${WRKSRC}/errno.h
	@touch ${WRKSRC}/fcntl.h
	@touch ${WRKSRC}/xtensa-asm.h
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/Makefile.am
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/Makefile.in
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/aclocal.m4
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/configure
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/configure.in
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/memcpy.S
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/memset.S
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/setjmp.S
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/strcmp.S
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/strcpy.S
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/strlen.S
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/strncpy.S
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/xtensa-asm.h
	@touch ${WRKSRC}/newlib/libc/machine/xtensa/xtensa.tex
	@mkdir -p ${WRKSRC}/newlib/libc/sys/xtensa/
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/Makefile.am
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/Makefile.in
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/_atexit.c
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/aclocal.m4
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/clibrary_init.c
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/configure
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/configure.in
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/creat.c
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/crt0.c
	@mkdir -p ${WRKSRC}/newlib/libc/sys/xtensa/include/
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/include/fenv.h
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/include/unistd.h
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/isatty.c
	@mkdir -p ${WRKSRC}/newlib/libc/sys/xtensa/sys/
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/sys/errno.h
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/sys/fcntl.h
	@touch ${WRKSRC}/newlib/libc/sys/xtensa/sys/file.h
	@mkdir -p ${WRKSRC}/newlib/libm/machine/xtensa/
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/Makefile.am
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/Makefile.in
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/aclocal.m4
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/configure
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/configure.in
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/feclearexcept.c
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/fegetenv.c
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/fegetexcept.c
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/fegetexceptflag.c
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/fegetround.c
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/feholdexcept.c
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/feraiseexcept.c
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/fetestexcept.c
	@touch ${WRKSRC}/newlib/libm/machine/xtensa/feupdateenv.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/newlib
	${INSTALL_DATA} ${WRKDIST}/COPYING.NEWLIB \
		${PREFIX}/share/doc/newlib
	${INSTALL_DATA} \
	    ${WRKDIST}/newlib/libc/sys/xtensa/include/xtensa/simcall-errno.h \
		${PREFIX}/${CONFIG}/include/xtensa
	${INSTALL_DATA} \
	    ${WRKDIST}/newlib/libc/sys/xtensa/include/xtensa/simcall-fcntl.h \
		${PREFIX}/${CONFIG}/include/xtensa

.include <bsd.port.mk>
