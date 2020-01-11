#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float g1, y1, G, F, Y, a, x_P, x, x1, x2, Step, maxg, ming, maxf, minf, maxy, miny,  max, min;
    int k, Exit, i, N;
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

    struct MyStruct
    {
        char znach[255];
    };

    struct MyStruct Massiv_Struct[2];

    float Get_Max(float Mass[100],float max)
    {   max = Mass[1];
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

        sovp = 0;
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
        printf("Значения G: %s\n", stg);

        strcat(Massiv_Struct[0].znach, stg);

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
        printf("Minimum = %f\n\n",ming);
        N = 0;
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

        strcat(Massiv_Struct[1].znach, stf);

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
        printf("Minimum = %f\n\n",minf);

        N = 0;
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

        strcat(Massiv_Struct[2].znach, sty);

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
        printf("Minimum = %f\n\n",miny);

        printf("\nЗначение G: %s\n", Massiv_Struct[0].znach);
        printf("\nЗначение F: %s\n", Massiv_Struct[1].znach);
        printf("\nЗначение Y: %s\n", Massiv_Struct[2].znach);

        FILE *fileMS;
        fileMS = fopen("test.txt", "w+");
        if ((fileMS = fopen("test.txt", "w+"))== NULL)
        {
            printf("Ошибка при открытии файла\n");
            exit(1);
        }
        for(i=0; i < 3; i++)
        {
            fprintf(fileMS, "%s\n", Massiv_Struct[i].znach);
        }
        fclose(fileMS);

        memset(Massiv_Struct[0].znach, 0, sizeof(Massiv_Struct[0].znach));
        memset(Massiv_Struct[1].znach, 0, sizeof(Massiv_Struct[1].znach));
        memset(Massiv_Struct[2].znach, 0, sizeof(Massiv_Struct[2].znach));

        char ZnachF[255];
        fileMS = fopen("test.txt","r");
        if ((fileMS = fopen("test.txt","r"))==NULL)
        {
            printf("Ошибка при открытии файла\n");
            exit(1);
        }
        while(fscanf(fileMS,"%s\n", &ZnachF) == 1)
        {
            printf("%s\n",ZnachF);
        }
        fclose(fileMS);

        printf("Выйти из программы?(1-да, 0-нет)\n");
        scanf("%int", &Exit);
    }
    return 0;
}



