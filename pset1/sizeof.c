#include <stdio.h>
#include <stddef.h>

int main(void)
{
    char c;
    double d;
    float f;
    int i;
    
    printf("char: %lu\n", sizeof(c));
    printf("double: %lu\n", sizeof(d));
    printf("float: %lu\n", sizeof(f));
    printf("int: %lu\n", sizeof(i));
}