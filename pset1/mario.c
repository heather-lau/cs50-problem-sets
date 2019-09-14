#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; 
    do
    {
    printf("Height: ");
    n = GetInt();
    }
    while(n < 0 || n > 23);
    

    for ( int i = 1 ; i <= n ; i++ )
    {
       for ( int j = 0 ; j < n - i ; j++ )
       {
        printf(" ");
       }
       for ( int k = 0 ; k <= i ; k++ )
       {
        printf("#");
       }
       printf("\n");
    }
}