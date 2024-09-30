#include "TXLib.h"
#include <stdio.h>
#include "Main.h"
#include <stdlib.h>
#include <assert.h>

code_error Ctor (stack_t* Data, size_t quantity);

int main ()
{
    stack_t Data = {};
    int* a = (int*) calloc (12, sizeof (int));
    free (a);

    Ctor (&Data, 10);
    free (Data.buffer);
    printf("EGd\n");

    return 0;
}

code_error Ctor (stack_t* Data, size_t quantity)
{
    Data->buffer = (stack_el_t*) calloc (quantity + 2, sizeof (stack_el_t));
    printf ("BM BM BM\n");

    return err;
}
