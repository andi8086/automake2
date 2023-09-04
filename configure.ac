AC_INIT([helloworld], [01], [blabla@blabla.de])
AM_INIT_AUTOMAKE([])
AC_PROG_CC


dnl Configure switches
AC_ARG_ENABLE(floppy_sound,
        [AS_HELP_STRING([--enable-floppy-sound], [Enables floppy seek sound (default: enabled)])],
        [floppy_sound=$enableval],
        [floppy_sound=yes])


dnl Check for mtools

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

dnl check for SDL2

SDL_VERSION=1.2.0
AM_PATH_SDL2($SDL_VERSION,
            :,
            AC_MSG_ERROR([*** SDL version $SDL_VERSION not found!])
)

CFLAGS="$CFLAGS $SDL_CFLAGS"
LIBS="$LIBS $SDL_LIBS"

if test "$floppy_sound" == "yes"; then
        AC_CHECK_LIB(SDL2_mixer, Mix_PlayChannel, found_sdl_mixer=yes, found_sdl_mixer=no)

        if test x"$found_sdl_mixer" == x"no"; then
                AC_MSG_ERROR([*** Please also install SDL_mixer!])
        fi

        LIBS="$LIBS -lSDL2_mixer"
        AC_DEFINE([CONFIG_FLOPPY_SOUND], 1, [floppy seek sound enabled])
fi


AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

