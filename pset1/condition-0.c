#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Please give me an int: ");
    int n = GetInt();
    
    if (n > 0)
    {
        printf("You picked a possitive integer!\n");
        
    }
    else
    {
        printf("You picked a negetive integer!\n");
    }
}f