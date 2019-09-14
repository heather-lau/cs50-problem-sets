#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//get the key
int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("\n");
        return 1;
    }
        
    string k = argv[1];
    
    for (int i = 0, n = strlen(k); i < n; i++ )
    {
        if (!isalpha(k[i]))
        {
            printf("\n");
            return 1;
        }
    }

    int ka[strlen(k)];
    
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        int a = toupper(k[i]) -'A';
        ka[i] = a;
    }
    
    string p = GetString();
    
    //encrypt
    int n = 0;
    for (int i = 0, pn = strlen(p); i < pn; i++)
    {
        int j = n % (strlen(k));
        n++;
        
            if ( isalpha(p[i]) && isupper(p[i]) )
                {
                    int l = ((p[i]-'A') + ka[j]) % 26;
                    printf("%c", (l + 'A'));
                }
            else if ( isalpha(p[i]) && islower(p[i]) )
                {
                    int u = ((p[i]-'a') + ka[j]) % 26;
                    printf("%c", (u + 'a'));
                }
            else
                {
                    printf("%c",p[i]);
                    n--;
                }
    }
    
    printf("\n");
    
    return 0;
}