#include <stdio.h>

int main()
{
    double x;
    while(scanf("%lf",&x) != EOF)
    {
        if (x<=400)
            printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 15 %%\n",x*1.15,x*0.15);
        else if (x<=800)
            printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 12 %%\n",x*1.12,x*0.12);
        else if (x<=1200)
            printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 10 %%\n",x*1.1,x*0.1);
        else if (x<=2000)
            printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 7 %%\n",x*1.07,x*0.07);
        else
            printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 4 %%\n",x*1.04,x*0.04);
    }
    return 0;
}