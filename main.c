#include <stdio.h>
#include "config.h"

int main(int argc, char **argv)
{
#ifdef CONFIG_FLOPPY_SOUND
        printf("Floppy seek sound enabled\n");
#endif
        printf("Hello world\n");
        return 0;
}
