#include "Main.h"
#include "Debug.h"


int Dump (stack_t* Data)
{
    printf ("//================================================================================================\n");

    printf ("\tSTRUCT:\n\t");
    printf ("name of struct = %s\n", Data -> name);
    printf ("file = %s\n", Data -> file);
    printf ("line = %d\n", Data -> line);
    printf ("buffer = %p\n", Data -> buffer);
    printf ("size = %lld\n", Data -> size);
    printf ("capacity = %lld\n", Data -> capacity);

    printf ("\tSTACK:\n\t");
    for (size_t i = 0; i < Data -> capacity + 1; ++i)
        printf ("<%d> ", Data -> buffer[i]);
    printf ("\n");
    printf ("//================================================================================================\n");
    return 0;
}
//==================================================================================================
int Canary (stack_t* Data)
{
    Data -> buffer[Data -> capacity + 1] = CANARY;

    return 0;
}
//==================================================================================================
int Fill_Poison (stack_el_t* begin, stack_el_t* end)
{
    uint_t limit = ((uint_t) end - (uint_t) begin) / (uint_t)sizeof (stack_el_t);
    printf ("limit = %llu\n", limit);
    for (uint_t i = 0; i < limit; ++i)
        begin[i] = POISON;

    return 0;
}
