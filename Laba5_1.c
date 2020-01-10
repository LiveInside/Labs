#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a,sum;
    int N = 0;
    char mystring[255];
    char check = '.';
    char save;
    printf("Введите число\n");
    scanf("%s", &mystring);
    save = strchr (mystring,check);
    if (save == NULL)
    {   N = atoi (mystring);
        while(N>0)
        {
            a = N % 10;
            if (a % 2 == 0)
            {
                sum++;
            }
            N = N/10;
        }
        printf("%d\n", sum);
    }
    else
        printf("%d\n",0);
    return 0;
}

