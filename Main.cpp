
#include "Main.h"
#include "Debug.h"

int Ctor (stack_t* Data, size_t capacity ONDEBUG(,const char* name, const char* file, int line));
int Push (stack_t* Data, stack_el_t elem);
int Debug (stack_t* Data);
int Pop (stack_t* Data);
int Dtor (stack_t* Data);

int main ()
{

    stack_t Data = {};

    CTOR (&Data, 10);
    Push (&Data, 100);
    Debug (&Data);
    Data.size_ += 1;

    Push (&Data, 200);
    printf("After Push2\n");
    Debug (&Data);
    Data.size_ += 1;
    Dtor (&Data);

    return 0;
}

int Ctor (stack_t* Data, size_t capacity ONDEBUG(, const char* name, const char* file, int line))
{
    Data->capacity = capacity;
    Data->buffer = (stack_el_t*) calloc (capacity + 2, sizeof (stack_el_t));
    ONDEBUG (Data -> name = name;)
    ONDEBUG (Data -> file = file;)
    ONDEBUG (Data -> line = line;)
    ONDEBUG (Dump (Data);)

    return 0;

    //Debug (Data);

}

//==================================================================================================
int Push (stack_t* Data, stack_el_t elem)
{
    size_t size_ = Data->size_;
    *(Data->buffer + size_) = elem;
    Debug (Data);

    return elem;
}
//==================================================================================================
int Debug (stack_t* Data)
{
    printf("Address Buffer = %p\n", Data->buffer);
    printf("Elem = %d\n", *(Data->buffer + Data->size_));
    printf("Size_ = %llu\n", Data->size_);
    return 0;
}
//==================================================================================================
int Pop (stack_t* Data)
{
    size_t size_ = Data->size_;
    *(Data->buffer + size_) = 0;
    Data->size_ -= 1;
    return 0;
}

int Dtor (stack_t* Data)
{
    free (Data->buffer);
    printf("зафричилось\n");

    return 0;
}

