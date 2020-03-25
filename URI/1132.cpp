#include <stdio.h>

int main()
{
    int X,Y,i,aux;
    while (scanf("%d %d",&X,&Y) != EOF)
    {
        if (X>Y)
        {
            aux = Y;
            Y=X;
            X=aux;
        }
        unsigned long long int sum=0;
        for (i=X;i<=Y;i++)
            if (i%13)
                sum += i;
        printf("%llu\n",sum);
    }
    return 0;
}