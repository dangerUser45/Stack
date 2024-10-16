
int main ()
{
    stack_t Data = {};

    Create_file () OR DIE;

    STACK_CTOR (&Data, 1) OR DIE;
    Dump (&Data); 

    Stack_Push (&Data, 100) OR DIE;
    ONDEBUG (Dump (&Data);)

    Stack_Push (&Data, 200) OR DIE;
    ONDEBUG (Dump (&Data);)

    Stack_Push (&Data, 300) OR DIE;
    ONDEBUG (Dump (&Data);)

    Stack_Push (&Data, 400) OR DIE;
    ONDEBUG (Dump (&Data);)

    Stack_Push (&Data, 500) OR DIE;
    ONDEBUG (Dump (&Data);)
    
    Stack_Pop (&Data) OR DIE;
    ONDEBUG (Dump (&Data);)

    Stack_Pop (&Data) OR DIE;
    ONDEBUG (Dump (&Data);)

    Stack_Pop (&Data) OR DIE;
    ONDEBUG (Dump (&Data);)

    Stack_Pop (&Data) OR DIE;
    ONDEBUG (Dump (&Data);)

    Stack_Pop (&Data) OR DIE;
    ONDEBUG (Dump (&Data);)

    Stack_Dtor (&Data) OR DIE;

    Close_file ();

    return NO_ERROR_;
}