
#include "TXLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEBUG

#ifdef  DEBUG
    #define ONDEBUG( ... ) __VA_ARGS__
    #define CTOR(Data, capacity) Ctor (Data, capacity, #Data, __FILE__, __LINE__)
#else
    #define ONDEBUG( ... )
    #define CTOR(Data, capacity) Ctor (Data, capacity);
#endif

enum code_error
    {
        err = 0,
        SIZE_OVER_FLOW = (1<<0),
        QWEW           = (1<<1),
        ASD            = (1<<2),
        RTYU           = (1<<3)

    };
typedef int stack_el_t;

struct stack_t
{
    ONDEBUG(const char* name;)
    ONDEBUG(const char* file;)
    ONDEBUG(int line;)

    stack_el_t* buffer;
    size_t size;
    size_t capacity;
};

