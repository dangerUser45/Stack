#include "Common.h"
#include "Debug.h"

int Create_file (stack_t* Data)
{
    FILE* fp = NULL;
    if ((fp = fopen("StackLog.txt", "w+")) == NULL)
    {
        fprintf (stdout, "Не удается открыть файл\n") ;
        return 0;
    }
    setvbuf (fp, 0, 0, _IONBF);
    Data -> fp = fp;

    return 0;/* code_error */
}
//==================================================================================================
int Dump (stack_t* Data)
{
    FILE* fp = Data -> fp;
    assert (fp);
    fprintf (fp, "//================================================================================================\n");

    fprintf (fp, "\tSTRUCT:\n");
    fprintf (fp, "name of struct = %s\n", Data -> name);
    fprintf (fp, "file = %s\n", Data -> file);
    fprintf (fp, "line = %d\n", Data -> line);
    fprintf (fp, "buffer = %p\n", Data -> buffer);
    fprintf (fp, "size = %zu\n", Data -> size);
    fprintf (fp, "capacity = %zu\n", Data -> capacity);

    fprintf (fp, "\tSTACK:\n");
    for (size_t i = 0; i < Data -> capacity + 2; ++i)
        fprintf (fp, "\t<%d> --- address: %p\n", Data -> buffer[i], Data -> buffer + i);
    fprintf (fp, "\n");
    fprintf (fp,"//================================================================================================\n");
    return 0;
}
//==================================================================================================
int Canary (stack_t* Data)
{
    Data -> buffer[0] = CANARY;
    Data -> buffer[Data -> capacity + 1] = CANARY;

    return 0;
}
//==================================================================================================
int Fill_Poison (stack_el_t* begin, uint_t quantity)
{
    for (uint_t i = 0; i < quantity; ++i)
        begin[i] = POISON;

    return 0;
}
//==================================================================================================
int Verificator (stack_t* Data)
{
    if (Data->buffer == 0)
    ;



    return 0;
}

