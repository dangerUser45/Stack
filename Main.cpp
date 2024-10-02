
#include "Main.h"
#include "Debug.h"

int Ctor (stack_t* Data, size_t capacity ONDEBUG(,const char* name, const char* file, int line));
int Push (stack_t* Data, stack_el_t elem);
int Pop (stack_t* Data);
int Dtor (stack_t* Data);
int Stack_Recalloc (stack_t Data);

int main ()
{
    stack_t Data = {};

    CTOR (&Data, 10);
    ONDEBUG (Dump (&Data);)
    printf ("Data.buffer + Data.size + 2 = %llu; Data.buffer + Data.capacity = %llu",Data.buffer + Data.size + 2, Data.buffer + Data.capacity);
    ONDEBUG (Fill_Poison (Data.buffer + Data.size + 2, Data.buffer + Data.capacity);)
    ONDEBUG (Dump (&Data);)

    ONDEBUG (Canary (&Data);)
    ONDEBUG (Dump (&Data);)

    Push (&Data, 100);
    ONDEBUG (Dump (&Data);)

    Push (&Data, 200);
    ONDEBUG (Dump (&Data);)

    stack_el_t elpop = Pop (&Data);
    printf ("elpop = %d\n", elpop);
    ONDEBUG (Dump (&Data);)

    Dtor (&Data);

    return 0;
}

int Ctor (stack_t* Data, size_t capacity ONDEBUG(, const char* name, const char* file, int line))
{
    Data -> capacity = capacity;
    Data -> size = 0;
    Data -> buffer = (stack_el_t*) calloc (capacity ONDEBUG(+ 2), sizeof (stack_el_t));
    Data -> buffer[0] = CANARY;
    ONDEBUG (Data -> name = name;)
    ONDEBUG (Data -> file = file;)
    ONDEBUG (Data -> line = line;)

    return 0;
}

//==================================================================================================
int Push (stack_t* Data, stack_el_t elem)
{
    size_t size = Data->size;
    Data -> buffer [size ONDEBUG( + 1)] = elem;
    Data -> size += 1;

    return elem;
}
//==================================================================================================
int Pop (stack_t* Data)
{
    size_t size = Data->size;

    Data -> buffer [size ONDEBUG( + 1 )] = POISON;
    Data -> size -= 1;
    return 0;
}
//==================================================================================================
int Dtor (stack_t* Data)
{
    free (Data->buffer);
    printf("зафричилось\n");

    return 0;
}
//==================================================================================================
int Stack_Recalloc (stack_t Data)
{
    return 0;
}
