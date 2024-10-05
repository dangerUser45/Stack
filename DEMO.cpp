
#include <stdio.h>
void Func (const char* str);
int main ()
{
    Func ("I love you");
    return 0;
}
void Func (const char* str)
{
    printf ("%s\n", str);
}
