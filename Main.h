int Ctor (stack_t* Data, size_t capacity ONDEBUG(,const char* name, const char* file, int line));
int Push (stack_t* Data, stack_el_t elem);
int Pop (stack_t* Data);
int Dtor (stack_t* Data);
int Stack_Realloc (stack_t* Data);
