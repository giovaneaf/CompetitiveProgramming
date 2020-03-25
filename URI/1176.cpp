#include <stdio.h>
#include <math.h>
#define BI 1.6180339887498948482045868343656

int main()
{
    int N,x,i;
    double temp;
    scanf("%d",&N);
    for (i=0;i<N;i++)
    {
        scanf("%d",&x);
        temp = round((pow(BI,x) - pow((1-BI),x))/sqrt(5));
        printf("Fib(%d) = %.0lf\n",x,temp);
    }
    return 0;
}