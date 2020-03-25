#include <stdio.h>

int main()
{
    int A,B;
    double C;
    while (scanf("%d %d %lf",&A,&B,&C) != EOF)
    {
        C *= B;
        printf("NUMBER = %d\n",A);
        printf("SALARY = U$ %.2lf\n",C);
    }
    return 0;
}
