#include <stdio.h>

int fatorial(int n)
{
    int i,soma;
    for (i=2,soma=1;i<=n;i++)
        soma *= i;
    return soma;
}

int main()
{
    int i,N,cont,val;
    while (scanf("%d",&N) != EOF)
    {
        val=N;
        cont=0;
        while (val != 0)
        {
            for (i=1;(int)((float)val/fatorial(i))>0;i++)
                ;
            val -= fatorial(i-1);
            cont++;
        }
        printf("%d\n",cont);
    }
    return 0;
}