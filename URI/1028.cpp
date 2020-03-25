#include <stdio.h>

int MDC (int a,int b)
{
    int q,r;
    while (b != 0)
    {
        q = a / b;
        r = a % b;
        a = b;
        b = r;
    }
   return a;
}

int main()
{
    int i,N,F1,F2;
    scanf("%d",&N);
    for (i=0;i<N;i++)
    {
        scanf("%d %d",&F1,&F2);
        printf("%d\n",MDC(F1,F2));
    }
    return 0;
}
