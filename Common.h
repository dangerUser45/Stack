
#include "TXLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEBUG

#ifdef  DEBUG
    #define ONDEBUG( ... ) __VA_ARGS__
    #define CTOR(Data, capacity) Ctor (Data, capacity, #Data, __FILE__, __LINE__)
    #define CHECK( code ) { int error = Verificator (Data); Decoder_error (Data, error);  if (error != 0) code;}
#else
    #define ONDEBUG( ... )
    #define CTOR(Data, capacity) Ctor (Data, capacity);
#endif


enum code_error
    {
        BUFFER_NULL    = (1<<0),
        BAD_SIZE      = (1<<1),
        BAD_CAPACITY  = (1<<2),
        FILE_NULL      = (1<<3),
        BAD_CANARY1   = (1<<4),
        BAD_CANARY2  = (1<<5),



    };
typedef int stack_el_t;
typedef long long unsigned int uint_t;
const stack_el_t POISON = -666;
const stack_el_t CANARY = -123401234;
const int MAGIC_NUM = 2;


struct stack_t
{
    ONDEBUG(stack_el_t canary1;)
    ONDEBUG(const char* name;)
    ONDEBUG(const char* file;)
    ONDEBUG(int line;)
    ONDEBUG(FILE* fp;)


    stack_el_t* buffer;
    ssize_t size;
    ssize_t capacity;
    ONDEBUG(uint_t hash_stack;)
    ONDEBUG(uint_t hash_buffer;)
    ONDEBUG(stack_el_t canary2;)


};
