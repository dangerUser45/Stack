#include "TXLib.h"
#include "Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int Ctor (stack_t* Data, int quantity);
/*int Push (stack_t* Data, stack_el_t elem);
int Debug (stack_t* Data);
int Pop (stack_t* Data);*/
int Dtor (stack_t* Data);

int main ()
{
    stack_t Data = {};
    //printf("Before Ctor\n");
    Ctor (&Data, 10);


    //Push (&Data, 100);
    //printf("After Push1\n");
    //Debug (&Data);
    //Data.size_ += 1;

    //Push (&Data, 200);
    //printf("After Push2\n");
    //Debug (&Data);
    //Data.size_ += 1;
    Dtor (&Data);
    printf (Дед Супер);
    return 0;
}

int Ctor (stack_t* Data, int quantity)
{
    Data->buffer = (stack_el_t*) calloc (quantity + 2, sizeof (stack_el_t));
    printf("quantity +2 = %d\n", quantity + 2);


    //Debug (Data);

}
/*
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
*/
int Dtor (stack_t* Data)
{
    //free (Data->buffer);
    printf("Зафричилось\n");

    return 0;
}

