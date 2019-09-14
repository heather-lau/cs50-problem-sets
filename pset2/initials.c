#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = GetString();
    
    //get the first letter
    printf("%c", toupper(name[0]));
    
    //get the letter after space
    for ( int i = 1, n = strlen(name); i < n; i++ )
    {
        if ( name[i] == ' ' )
        printf("%c", toupper(name[i+1]));
    }
    printf("\n");
}