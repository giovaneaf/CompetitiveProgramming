#include <stdio.h>

int main()
{
    char s[50];
    while (scanf("%s",&s) != EOF)
    {
        double A,B;
        scanf("%lf %lf",&A,&B);
        A += B*0.15;
        printf("TOTAL = R$ %.2lf\n",A);
    }
    return 0;
}