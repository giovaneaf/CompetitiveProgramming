#include <stdio.h>

int main()
{
    int N,var;
    while (scanf("%d",&N) != EOF)
    {
        printf ("%d\n",N);
        var = N/100.0;
        printf("%d nota(s) de R$ 100,00\n",var);
        if (N/100.0>0)
        {
            N %= 100;
        }
        var = N/50.0;
        printf("%d nota(s) de R$ 50,00\n",var);
        if (N/50.0>0)
        {
            N %= 50;
        }
        var = N/20.0;
        printf("%d nota(s) de R$ 20,00\n",var);
        if (N/20.0>0)
        {
            N %= 20;
        }
        var = N/10.0;
        printf("%d nota(s) de R$ 10,00\n",var);
        if (N/10.0>0)
        {
            N %= 10;
        }
        var = N/5.0;
        printf("%d nota(s) de R$ 5,00\n",var);
        if (N/5.0>0)
        {
            N %= 5;
        }
        var = N/2.0;
        printf("%d nota(s) de R$ 2,00\n",var);
        if (N/2.0>0)
        {
            N %= 2;
        }
        printf("%d nota(s) de R$ 1,00\n",N);
    }
    return 0;
}