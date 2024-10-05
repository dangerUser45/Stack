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
    fprintf (fp, "size = %zd\n", Data -> size);
    fprintf (fp, "capacity = %zd\n", Data -> capacity);

    fprintf (fp, "\tSTACK:\n");
    for (ssize_t i = 0; i < Data -> capacity + 2; ++i)
        fprintf (fp, "\t%zd) <%d> --- address: %p\n", i, Data -> buffer[i], Data -> buffer + i);
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

    if (Data->buffer == NULL)               // 1111'1111
        error = error | BUFFER_NULL;     // 1 csb

    if (Data->size < 0)
        error = error | BAD_SIZE;     // 2

    if (Data ->capacity < 0)
        error = error | BAD_CAPACITY;     // 3

    if (Data -> fp == NULL)
        error = error | FILE_NULL;     // 4

    if (Data -> canary1 == CANARY)
        error = error | BAD_CANARY1;     // 5

    if (Data -> canary2 == CANARY)
        error = error | BAD_CANARY2;     // 6


    return error;
}
//==================================================================================================
int Decoder_error (stack_t* Data, int error)
{

    fprintf (Data -> fp, "=======================================================================\n");
    fprintf (Data -> fp, "\tERRORS\n");


    if (error & BUFFER_NULL)
        fprintf (Data -> fp, "Buffer = 0\n");

    if (error & BAD_SIZE)
        fprintf (Data -> fp, "Size = 0\n");

    if (error & BAD_CAPACITY)
        fprintf (Data -> fp, "Capacity is bad\n");

    if (error & FILE_NULL)
        fprintf (Data -> fp, "File pointer = NULL\n");

    if (error & BAD_CANARY1)
        fprintf (Data -> fp, "Canary1 is bad\n");

    if (error & BAD_CANARY2)
        fprintf (Data -> fp, "Canary2 is bad\n");

    if (error == 0)
        fprintf (Data -> fp, "All it is OK\n");

    fprintf (Data -> fp, "==================================================\n");

    return error;
}
//==================================================================================================
/*int Hash (stack_t Data)
{
    for (uint_t i = 0; i < ; ++i)

}
//==================================================================================================
*/

