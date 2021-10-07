 $OpenBSD: Makefile.inc,v 1.2 2020/04/05 21:55:01 tracey Exp $

BROKEN-sparc64 = 'in gcc-bootstrap multiple wide-int.h:370:10: error: too many template-parameter-lists'

CONFIG =	xtensa-lx106-elf
CATEGORIES +=	devel

# GPLv3
# For newlib: multiple copyrights, but basically BSD.
#   See: ${INSTALLDR}/share/doc/newlib
# For lx106-hal MIT
PERMIT_PACKAGE =	Yes

COMPILER =		base-clang ports-gcc base-gcc

BUILD_DEPENDS +=	devel/bison \
			sysutils/coreutils

SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes
YACC =			bison -y

INSTALLDIR =		"${LOCALBASE}/${CONFIG}"

CONFIGURE_STYLE =	simple

NO_TEST =		Yes
