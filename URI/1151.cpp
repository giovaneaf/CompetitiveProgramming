#include <stdio.h>

main()
{
    int aux1,aux2,N,i;
    scanf("%d",&N);
    if (N>0 && N<46)
    {
        for (i = 0,aux1=1,aux2=0;i < N-1; i++)
        {
            printf("%d", aux2);
            aux2 = aux1 + aux2;
            aux1 = aux2 - aux1;
            putchar(' ');
        }
        printf("%d\n",aux2);
    }
}