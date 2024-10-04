#include "Common.h"
#include "Debug.h"

int Create_file (stack_t* Data)
{
    FILE* fp = 0;
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
        fprintf (fp, "\t%zu) <%d> --- address: %p\n", i, Data -> buffer[i], Data -> buffer + i);
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
    int error = 0;

    if (Data->buffer == 0)               // 1111'1111
        error = error | BUFFER_NULL;     // 1 csb

    if (Data->size < 0)
        error = error | SIZE_NULL;     // 2

    if (Data ->capacity < 0)
        error = error | 0b00000000000000000000000000000100;     // 3

    if ()
        error = error | 0b00000000000000000000000000001000;     // 4

    if ()
        error = error | 0b00000000000000000000000000010000;     // 5

    if ()
        error = error | 0b00000000000000000000000000100000;     // 6

    if ()
        error = error | 0b00000000000000000000000001000000;     // 7

    if ()
        error = error | 0b00000000000000000000000010000000;     // 8

    if ()
        error = error | 0b00000000000000000000000100000000;     // 9

    if ()
        error = error | 0b00000000000000000000001000000000;     // 10

    if ()
        error = error | 0b00000000000000000000010000000000;     // 11

    if ()
        error = error | 0b00000000000000000000100000000000;     // 12

    if ()
        error = error | 0b00000000000000000001000000000000;     // 13

    if ()
        error = error | 0b00000000000000000010000000000000;     // 14

    if ()
        error = error | 0b00000000000000000100000000000000;     // 15

    if ()
        error = error | 0b00000000000000001000000000000000;     // 16

    return error;
}
//==================================================================================================
int Decoder_error (stack_t* Data, int error)
{
    if (error & 0b00000000000000000000000000000001)
        fprintf (Data -> fp, "Buffer = 0\n");

    if ()
}
//==================================================================================================
int Hash (stack_t Data)
{
    for (uint_t i = 0; i < ; ++i)

}
//==================================================================================================
