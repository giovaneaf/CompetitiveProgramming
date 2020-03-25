#include <stdio.h>

int main()
{
    int n=0;
    double num,med=0.0;
    do
    {
        scanf("%lf",&num);
        if (num<0 || num>10)
            printf("nota invalida\n");
        else
        {
            n++;
            med += num;
        }
    }
    while (n<2);
    med /= n;
    printf("media = %.2lf\n",med);
    return 0;
}