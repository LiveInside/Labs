#include <stdio.h>
#include <math.h>

int main()
{
    float g1, y1, G, F, Y, a, x_P, x, x1, x2, Step, maxg, ming, maxf, minf, maxy, miny,  max, min;
    int ch, Exit, i, N;

    float Get_Max(float Mass[100],float max)
    {
        for(i = 0; i<N;  i++)
        {
            if (Mass[i] > max)
                max = Mass[i];
        }
        return max;
    }

    float Get_Min(float Mass[100],float min)
    {
        min = Mass[1];
        for(i = 0; i<N;  i++)
        {
            if (Mass[i] < min)
                min = Mass[i];
        }
        return min;
    }

    Exit = 0;
    i = 0;
    max = 0;
    while (Exit == 0)
    {
        printf ("Введите число a \n");
        scanf ("%f", &a);
        printf ("Введите число x \n");
        scanf ("%f", &x_P);

        printf ("Ввести нижнюю границу - x \n");
        scanf ("%f", &x1);
        printf ("Ввести верхнюю границу - x \n");
        scanf ("%f", &x2);

        printf ("Ввести шаг изменения переменной x \n");
        printf("Выбрать номер функции 1-3 \n");
        scanf("%int",&ch);

        if (ch == 1)
        {   N = 0;
            i = 0;
            x = x_P;
            while (x1<=x && x<=x2)
            {
                g1 = -45*a*a+26*a*x+7*x*x;
                if (g1 != 0)
                {
                    x = x + Step;
                    N++;
                }
                else
                {
                    printf("Входные значения не принадлежат области определения функции.\n");
                    continue;
                }
            }

            float Massiv_G[N];
            x = x_P;
            while (x1<=x && x<=x2)
            {
                g1 = -45*a*a+26*a*x+7*x*x;
                if (g1 != 0)
                {
                    G = -1 * (7*(4*a*a+15*a*x-4*x*x)/g1);
                    Massiv_G[i] = G;
                    printf("Аргумент x = %f\t Значение G = %f\n", x, Massiv_G[i]);
                    x = x + Step;
                    i++;
                }
                else
                {
                    printf("Входные значения не принадлежат области определения функции.\n");
                    continue;
                }
            }
            maxg = Get_Max(Massiv_G,max);
            ming = Get_Min(Massiv_G,min);
            printf("Maximum = %f\n",maxg);
            printf("Minimum = %f\n",ming);
        }

        if (ch == 2)
        {   N = 0;
            i = 0;
            x = x_P;
            while (x1<=x && x<=x2)
            {
                x = x + Step;
                N++;
            }

            float Massiv_F[N];
            x = x_P;
            while (x1<=x && x<=x2)
            {
                F = powl(2,40*a*a-107*a*x+63*x*x);
                Massiv_F[i] = F;
                printf("Аргумент x = %f\t Значение F = %f\n", x,Massiv_F[i]);
                x = x + Step;
                i++;
            }
            maxf = Get_Max(Massiv_F,max);
            minf = Get_Min(Massiv_F,min);
            printf("Maximum = %f\n",maxf);
            printf("Minimum = %f\n",minf);
        }

        if (ch == 3)
        {   N = 0;
            i = 0;
            x = x_P;
            while (x1<=x && x<=x2)
            {
                y1 = a*a-2*a*x+3*x*x+1;
                if (y1 >= 0)
                {
                    x = x + Step;
                    N++;
                }
                else
                {
                    printf("Входные значения не принадлежат области определения функции.\n");
                    continue;
                }
            }

            float Massiv_Y[N];
            x = x_P;
            while (x1<=x && x<=x2)
            {
                y1 = a*a-2*a*x+3*x*x+1;
                if (y1 >= 0)
                {
                    Y = log(y1);
                    Massiv_Y[i] = Y;
                    printf("Аргумент x = %f\t Значение  = %f\n", x, Massiv_Y[i]);
                    x = x + Step;
                    i++;
                }
                else
                {
                    printf("Входные значения не принадлежат области определения функции.\n");
                    continue;
                }
            }
            maxy = Get_Max(Massiv_Y,max);
            miny = Get_Min(Massiv_Y,min);
            printf("Maximum = %f\n",maxy);
            printf("Minimum = %f\n",miny);

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
