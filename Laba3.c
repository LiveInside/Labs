#include <stdio.h>
#include <math.h>

int main()
{
    float g1, y1, G, F, Y, a, x, x1, x2, Step;
    int ch, Exit;
    Exit = 0;
    while (Exit == 0)
    {    
        printf ("Введите число a \n");
        scanf ("%f", &a);
        printf ("Введите число x \n");
        scanf ("%f", &x);

        printf ("Ввести нижнюю границу - x \n");
        scanf ("%f", &x1);
        printf ("Ввести верхнюю границу - x \n");
        scanf ("%f", &x2);

        printf ("Ввести шаг изменения переменной x \n");
        scanf ("%f", &Step);

        printf("Выбрать номер функции 1-3 \n");
        scanf("%int",&ch);

        if (ch == 1)
        {
            while (x1<=x && x<=x2)
            {   
                g1 = -45*a*a+26*a*x+7*x*x;
                if (g1 != 0)
                {
                    G = -1 * (7*(4*a*a+15*a*x-4*x*x)/g1);
                    printf("G=%f\n",G);
                    x = x + Step;
                }
                else
                {
                    printf("Входные значения не принадлежат области определения функции.\n");
                    continue;
                }
            }
            
        }

        if (ch == 2)
        {
            while (x1<=x && x<=x2)
            {           
                F = powl(2,40*a*a-107*a*x+63*x*x);
                printf("F=%f\n",F);
                x = x + Step;
            }
        }

        if (ch == 3)
        {
            while (x1<=x && x<=x2)
            {            
                y1 = a*a-2*a*x+3*x*x+1;
                if (y1 >= 0)
                {
                    Y = log(y1);
                    printf("Y=%f\n",Y);
                    x = x + Step;
                }
                else 
                {
                    printf("Входные значения не принадлежат области определения функции.\n");
                    continue;
                }
            }
        }

        if (ch < 1 || ch > 3)
        {
            printf("Номер функции выбран не верно.\n");
        }
        printf("Выйти из программы?(1-да, 0-нет)\n");
        scanf("%int", &Exit);
    }    
return 0;
}