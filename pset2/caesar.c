#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check error if the program is executed without or more than one arguments
        if(argc!=2)
    {
        //yell at the user
        printf("\n");
        return 1;
    }
    // convert the string to an integer
    int k = atoi(argv[1]);


    string p = GetString();
    
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        
        if ( isalpha(p[i]) && isupper(p[i]) )
            {
                int l = ((p[i]-'A') + k) % 26;
                printf("%c", (l + 'A'));
            }
        else if ( isalpha(p[i]) && islower(p[i]) )
            {
                int u = ((p[i]- 'a') + k) % 26;
                printf("%c", (u + 'a'));
            }
        else
            {
                printf("%c",p[i]);
            }
    }
    printf("\n");
    return 0;
}