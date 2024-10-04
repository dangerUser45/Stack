
#include "Common.h"
#include "Main.h"
#include "Debug.h"


int main ()
{
    stack_t Data = {};
    ONDEBUG (Create_file (&Data);)

    CTOR (&Data, 10);
    ONDEBUG (Dump (&Data);)
    fprintf (Data.fp, "Data.buffer + Data.size + 1 = %n\n", Data.buffer + Data.size + 1);
    ONDEBUG (Fill_Poison (Data.buffer + Data.size + 1, Data.capacity);)
    ONDEBUG (Dump (&Data);)

    ONDEBUG (Canary (&Data);)
    ONDEBUG (Dump (&Data);)

    Push (&Data, 100);
    ONDEBUG (Dump (&Data);)

    Push (&Data, 200);
    ONDEBUG (Dump (&Data);)

    Push (&Data, 400);
    ONDEBUG (Dump (&Data);)

    Pop (&Data);
    ONDEBUG (Dump (&Data);)

    Pop (&Data);
    ONDEBUG (Dump (&Data);)

    Pop (&Data);
    ONDEBUG (Dump (&Data);)

    Dtor (&Data);

    return 0;
}

int Ctor (stack_t* Data, size_t capacity ONDEBUG(, const char* name, const char* file, int line))
{
    Data -> capacity = capacity;
    Data -> size = 0;
    stack_el_t* buffer = (stack_el_t*) calloc (capacity ONDEBUG(+ 2), sizeof (stack_el_t));
    if (buffer)
        return 0;/* code_error*/;

    Data -> buffer = buffer;
    ONDEBUG (Data -> name = name;)
    ONDEBUG (Data -> file = file;)
    ONDEBUG (Data -> line = line;)

    return 0;
}

//==================================================================================================
int Push (stack_t* Data, stack_el_t elem)
{
    if (Data -> size >= Data -> capacity - 1)
        Stack_Realloc (Data);

    size_t size = Data->size;
    Data -> buffer [size ONDEBUG( + 1)] = elem;
    Data -> size += 1;

    return elem;
}
//==================================================================================================
int Pop (stack_t* Data)
{
    size_t size = Data->size;
    fprintf (Data -> fp, "size = %zu", size);
    fprintf(Data -> fp, "addr_popa = %n\n",  Data -> buffer +size ONDEBUG( + 1 ));

    Data -> buffer [size] = POISON;
    Data -> size -= 1;
    return 0;
}
//==================================================================================================
int Dtor (stack_t* Data)
{
    free (Data->buffer);
    fprintf(Data ->fp, "зафричилось\n");

    return 0;
}
//==================================================================================================
int Stack_Realloc (stack_t* Data)
{
    Data -> buffer = (stack_el_t*) realloc (Data -> buffer, MAGIC_NUM * Data -> capacity);
    return 0;
}
//==================================================================================================
