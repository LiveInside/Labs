#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float g1, y1, G, F, Y, a, x_P, x, x1, x2, Step, maxg, ming, maxf, minf, maxy, miny,  max, min;
    int k, ch, Exit, i, N;
    char mystring_a[255];
    char mystring_x_P[255];
    char mystring_Step[255];
    char mystring_Lx[255];
    char mystring_Hx[255];
    char stg[255];
    char stf[255];
    char sty[255];
    char sh[255];
    char* sovp;
    char blok[255];

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
        scanf ("%s", &mystring_a);
        a = atof(mystring_a);
        getchar();
        printf ("Введите число x \n");
        scanf ("%s", &mystring_x_P);
        x_P = atof(mystring_x_P);


        printf ("Ввести нижнюю границу - x \n");
        scanf ("%s", &mystring_Lx);
        x1 = atof(mystring_Lx);

        printf ("Ввести верхнюю границу - x \n");
        scanf ("%s", &mystring_Hx);
        x2 = atof(mystring_Hx);

        printf ("Ввести шаг изменения переменной x \n");
        scanf  ("%s",&mystring_Step);
        Step = atof(mystring_Step);
        printf("Выбрать номер функции 1-3 \n");
        scanf("%int",&ch);

        if (ch == 1)
        {   sovp = 0;
            k = 0;
            N = 0;
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
            memset(stg, 0, sizeof(stg));
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
            for(i = 0; i!=N; i++)
            {
                sprintf(blok,"%2f\t",Massiv_G[i]);
                strcat(stg,blok);
            }
            printf("%s\n", stg);

            printf ("Задайте шаблон для поиска совпадения\n");
            scanf("%s", sh);
            sovp = strstr(stg, sh);
            while(sovp != NULL)
            {
                sovp = strstr(sovp + 1, sh);
                k++;
            }

            printf("\nКолличество совпадений %d\n",k);
            maxg = Get_Max(Massiv_G,max);
            ming = Get_Min(Massiv_G,min);
            printf("\nMaximum = %f\n",maxg);
            printf("Minimum = %f\n",ming);
        }

        if (ch == 2)
        {   N = 0;
            k = 0;

            sovp = 0;
            i = 0;
            x = x_P;
            while (x1<=x && x<=x2)
            {
                x = x + Step;
                N++;
            }
            memset(stf, 0, sizeof(stf));
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
            for(i = 0; i!=N; i++)
            {
                sprintf(blok,"%2f\t",Massiv_F[i]);
                strcat(stf,blok);
            }
            printf("%s\n", stf);

            printf ("Задайте шаблон для поиска совпадения\n");
            scanf("%s", sh);
            sovp = strstr(stf, sh);
            while(sovp != NULL)
            {
                sovp = strstr(sovp + 1, sh);
                k++;
            }

            printf("\nКолличество совпадений %d\n",k);
            maxf = Get_Max(Massiv_F,max);
            minf = Get_Min(Massiv_F,min);
            printf("\nMaximum = %f\n",maxf);
            printf("Minimum = %f\n",minf);
        }

        if (ch == 3)
        {   N = 0;
            k = 0;
            sovp = 0;
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
            memset(sty, 0, sizeof(sty));
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
            for(i = 0; i!=N; i++)
            {
                sprintf(blok,"%2f\t",Massiv_Y[i]);
                strcat(sty,blok);
            }
            printf("%s\n", sty);

            printf ("Задайте шаблон для поиска совпадения\n");
            scanf("%s", sh);
            sovp = strstr(sty, sh);
            while(sovp != NULL)
            {
                sovp = strstr(sovp + 1, sh);
                k++;
            }

            printf("\nКолличество совпадений %d\n",k);
            maxy = Get_Max(Massiv_Y,max);
            miny = Get_Min(Massiv_Y,min);
            printf("\nMaximum = %f\n",maxy);
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



