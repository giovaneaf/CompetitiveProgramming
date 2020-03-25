#include <stdio.h>

int main()
{
    int num,n=0;
    double media=0.0;
    scanf("%d",&num);
    while (num>-1)
    {
        n++;
        media += num;
        scanf("%d",&num);
    }
    media /= n;
    printf("%.2lf\n",media);
    return 0;
}