AC_INIT([helloworld], [01], [blabla@blabla.de])
AM_INIT_AUTOMAKE([])
AC_PROG_CC


AC_PATH_PROG([MTOOLS], [mtools])
# AC_CHECK_PROG(MTOOLS, [mtools], yes)
if test x"${MTOOLS}" == x""; then
        AC_MSG_ERROR([mtools not found])
fi
AC_MSG_CHECKING([Checking if mtools >= 4.0.43...])

$("/bin/bash"
ver=$("${MTOOLS}" --version | grep mtools | cut -d' ' -f4)
AX_COMPARE_VERSION([${ver}],[ge],[4.0.43],
        AC_MSG_RESULT([Found version ${ver} - OK]),
        AC_MSG_ERROR([Your version ${ver} is too old!])
        )
)

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

