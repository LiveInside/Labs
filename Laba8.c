#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#include  <omp.h>

#define NPOINTS 100000

struct Point
{
    double x;
    double y;
};

typedef struct Point Point;

struct SearchArea
{
    Point center;
    double r;
};

typedef struct SearchArea SearchArea;

double getRandomNumber();
SearchArea getSearchArea(double r);
int isValid(Point p, SearchArea area);

int main(void)
{

    int i, N, true;
    double x,y;
    Point points[NPOINTS];
    SearchArea area;
    double start, end;
    double r = 1.0;

    start = omp_get_wtime();
    area = getSearchArea(r);
    for (i = 0; i < NPOINTS; i++)
    {
        points[i].x = getRandomNumber();
        points[i].y = getRandomNumber();
    }

    for (i = 0; i < NPOINTS; i++)
    {

        true = isValid(points[i], area);
        if(true == 1)
        {
            N = N+1;
        }
    }

    printf("Колличество точек в области %d\n", N);
    end = omp_get_wtime();
    printf("Elapsed time: %lf s.\n", (end-start));
    FILE *file;
    file = fopen("laba8.txt", "a+");
    if ((file = fopen("laba8.txt","a+")) == NULL)
    {
        printf("Ошибка при открытии файла.\n");
        exit(1);
    }
    fprintf(file,"%d\t %f\n", NPOINTS, end-start);
    fclose(file);
    return 0;
}

SearchArea getSearchArea(double r)
{
    SearchArea area;
    area.center.x = getRandomNumber();
    area.center.y = getRandomNumber();
    area.r = r;
    return area;
}

double getRandomNumber()
{
    return fmod(rand(), 10.0f) + (1.0 / fmod(rand(), 10.0f));
}


int isValid(Point p, SearchArea area)
{
    int N = 0;
    if(sqrt(((p.x - area.center.x)*(p.x - area.center.x))+((p.y - area.center.y)*(p.y - area.center.y))) <= area.r)
    {
        return 1;
    }
    return 0;
}


