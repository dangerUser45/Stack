
#include "Common.h"
#include "Main.h"
#include "Debug.h"


int main ()
{
    stack_t Data = {};
    ONDEBUG (Create_file (&Data);)

    CTOR (&Data, 10);
    fprintf (Data.fp, "data.bufer = %p\n", Data.buffer);
    ONDEBUG (Dump (&Data);)
    fprintf (Data.fp, "Data.buffer + Data.size + 1 = %p\n", Data.buffer + Data.size + 1);

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

int Ctor (stack_t* Data, ssize_t capacity ONDEBUG(, const char* name, const char* file, int line))
{
    CHECK ()

    Data -> capacity = capacity;
    Data -> size = 0;
    stack_el_t* buffer = (stack_el_t*) calloc (capacity ONDEBUG(+ 2), sizeof (stack_el_t));
    if (buffer == NULL)
       { return 0;/* code_error*/;}
    Data -> buffer = buffer;

    ONDEBUG (Data -> name = name;)
    ONDEBUG (Data -> file = file;)
    ONDEBUG (Data -> line = line;)

    ONDEBUG (Fill_Poison (Data -> buffer + Data -> size + 1, Data -> capacity);)

    CHECK ()

    return 0;
}

//==================================================================================================
int Push (stack_t* Data, stack_el_t elem)
{

    CHECK (return 0;)

    if (Data -> size >= Data -> capacity - 1)
    {
        fprintf (Data -> fp, "its realloc up\n");
        Stack_Realloc_Up (Data);
        ONDEBUG (Fill_Poison (Data -> buffer + Data -> size + 1, Data -> capacity);)
    }

    ssize_t size = Data->size;
    Data -> buffer [size ONDEBUG( + 1)] = elem;
    Data -> size += 1;

    CHECK (return 0;)

    return elem;
}
//==================================================================================================
int Pop (stack_t* Data)
{

    CHECK (return 0;)

    if (Data -> size < Data -> capacity / 4)
    {
        fprintf (Data -> fp, "Its realloc_down\n");
        Stack_Realloc_Down (Data);
        ONDEBUG (Fill_Poison (Data -> buffer + Data -> size + 1, Data -> capacity);)
    }

    ssize_t size = Data -> size;
    fprintf (Data -> fp, "size = %zd\n", size);
    fprintf(Data -> fp, "addr_popa = %p\n",  Data -> buffer +size ONDEBUG( + 1 ));

    Data -> buffer [size] = POISON;
    Data -> size -= 1;
    return 0;

    CHECK (return 0;)

}
//==================================================================================================
int Dtor (stack_t* Data)
{

    CHECK (return 0;)

    free (Data->buffer);
    fprintf(Data ->fp, "зафричилось\n");

    CHECK (return 0;)

    return 0;
}
//==================================================================================================

#define PLEASE_NOTE_THAT_DNLX_DID_THAT(...) __VA_ARGS__

int Stack_Realloc_Up (stack_t* Data)
{
    Data -> buffer = (stack_el_t*) realloc (Data -> buffer,
                                            PLEASE_NOTE_THAT_DNLX_DID_THAT (Data -> capacity *= MAGIC_NUM)); //capacity is

    return 0;
}
//==================================================================================================
int Stack_Realloc_Down (stack_t* Data)
{
    Data -> buffer = (stack_el_t*) realloc (Data -> buffer, Data -> capacity /= MAGIC_NUM);
    return 0;
}
//==================================================================================================
