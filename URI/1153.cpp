#include <stdio.h>

int main()
{
    int N,i;
    long long int soma;
    while (scanf("%d",&N) != EOF)
    {
        for (i=1,soma=1;i<=N;i++)
            soma *= i;
        printf("%lld\n",soma);
    }
    return 0;
}
