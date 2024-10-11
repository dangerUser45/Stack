
#include <stdio.h>
#include <stdlib.h>
void Func (const char* str);
int main ()
{
    char* data = (char*) calloc (13, sizeof (char));
    printf ("data = %p\n", data);
    data = NULL;
    printf ("data = %p\n", data);

    return 0;
}
void Func (const char* str)
{
    printf ("%s\n", str);
}
