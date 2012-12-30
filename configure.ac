AC_PREREQ([2.59])
AC_INIT([example], [0.1], [js AT piratejon DOT com])
AC_CONFIG_SRCDIR([src/example.c])

# place to put some extra build scripts installed
AC_CONFIG_AUX_DIR([build-aux])

# fairly severe build strictness
# change foreign to gnu or gnits to comply with gnu standards
AM_INIT_AUTOMAKE([-Wall -Werror foreign 1.9.6])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for header files.
#AC_HEADER_STDC
#AC_PROG_CC_STDC
#AC_CHECK_HEADERS([any headers needed, separated by commas])
#AC_CHECK_HEADERS([stdlib.h, stdbool.h])
AC_CHECK_HEADERS([stdlib.h, unistd.h])

# Output files
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 tests/Makefile])

AC_OUTPUT
