#define DEBUG

#ifdef  DEBUG
    #define ONDEBUG( ... ) __VA_ARGS__
#else
    #define ONDEBUG( ... )
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
    ONDEBUG (char* name;)
    ONDEBUG (char* name2;)

    stack_el_t* buffer;
    size_t size_;
    size_t capacity;
};

