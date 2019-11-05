#include <stdio.h>
#include <math.h>

int main()
{
float g1, y1, G, F, Y, a, x;
int ch;

printf ("Введите число a \n");
scanf ("%f", &a);
printf ("Введите число x \n");
scanf ("%f", &x);

printf("Выбрать номер функции 1-3 \n");
scanf("%int",&ch);

if (ch == 1)
    {
        g1 = -45*a*a+26*a*x+7*x*x;
        if (g1 != 0)
    {
        G = -1 * (7*(4*a*a+15*a*x-4*x*x)/g1);
        printf("G=%f\n",G);
    }
    else
    {
        printf("Входные значения не принадлежат области определения функции.");
    }
    
    }
if (ch == 2)
{
    F = powl(2,40*a*a-107*a*x+63*x*x);
    printf("F=%f\n",F);
}

if (ch == 3)
{
    y1 = a*a-2*a*x+3*x*x+1;
    if (y1 >= 0)
    {
        Y = log(y1);
        printf("Y=%f\n",Y);
    }
    else 
    {
        printf("Входные значения не принадлежат области определения функции.");
    }
}
else
{
     printf("Номер функции выбран не верно.");
}

return 0;
}