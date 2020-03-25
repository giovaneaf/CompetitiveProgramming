#include <stdio.h>

int main()
{
    int X;
    double Y;
    while (scanf("%d %lf",&X,&Y) != EOF)
        printf("%.3lf km/l\n",X/Y);
    return 0;
}
