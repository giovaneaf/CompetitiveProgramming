#include <stdio.h>

int main()
{
    int n=0,i=0;
    double a,med=0.0;
    do
    {
        scanf("%lf",&a);
        if (a>0)
        {
            n++;
            med += a;
        }
        i++;
    }
    while (i<6);
    printf("%d valores positivos\n",n);
    printf("%.1lf\n",med/n);
    return 0;
}