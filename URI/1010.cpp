#include <stdio.h>

int main()
{
    int A,B;
    double C,total;
    while (scanf("%d %d %lf",&A,&B,&C) != EOF)
    {
        total = B*C;
        scanf("%d %d %lf",&A,&B,&C);
        printf("VALOR A PAGAR: R$ %.2lf\n",total + B*C);
    }
    return 0;
}
