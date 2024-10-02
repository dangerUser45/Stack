#include "Main.h"
#include "Debug.h"


int Dump (stack_t* Data)
{
    printf ("name of struct = %s\n", Data -> name);
    printf ("file = %s\n", Data -> file);
    printf ("line = %d\n", Data -> line);

    return 0;
}
