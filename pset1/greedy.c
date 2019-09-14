#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;

    int c_quarters = 0;
    int c_dimes = 0;
    int c_nickels = 0;
    int c_pennies = 0;
    int c_coin = 0;
    
    float n;
    int nI;

    //get user input
    do
    {
        printf(" O hai! How much change is owed? ");
        n = GetFloat( );
    }
    while(n <= 0);
    nI = (int) round(n*100);

    //get coins
    int remain = nI;
    
    if ( remain >= quarters )
    {
        c_quarters = remain / quarters;
        remain %= quarters ;
    };

    if ( remain >= dimes )
    { 
        c_dimes = remain / dimes;
        remain %= dimes ;
    };

    if ( remain >= nickels )
    {
        c_nickels = remain / nickels;
        remain %= nickels ;
    };
    
    c_pennies = remain;
    c_coin = c_quarters + c_dimes + c_nickels + c_pennies;

    //print out coin
    printf("%d\n",c_coin);

}