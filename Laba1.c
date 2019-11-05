#include <stdio.h>
#include <math.h>

int main()
{
float g1, y1, G, F, Y, a, x;

printf ("Введите число a \n");
scanf ("%f", &a);
printf ("Введите число x \n");
scanf ("%f", &x);

g1 = -45*a*a+26*a*x+7*x*x;
G = -1 * (7*(4*a*a+15*a*x-4*x*x)/g1);
printf("G=%f\n",G);

F = powl(2,40*a*a-107*a*x+63*x*x);
printf("F=%f\n",F);

y1 = a*a-2*a*x+3*x*x+1;
Y = log(y1);
printf("Y=%f\n",Y);

return 0;
}