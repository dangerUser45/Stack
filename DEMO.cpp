
#ifdef  DEB
    #define ONDEB( ... ) __VA_ARGS__
    #define CTOR(&Data, capacity) Ctor (&Data, capacity, #Data, __FILE__, __LINE__ );
#else
    #define ONDEB( ... )
    #define CTOR(&Data, capacity) Ctor (&Data, capacity);
#endif

#include <stdio.h>
int main ()
{
    int a = 5;
    5;
    printf ("a\n");
    return 0;
}
