#include <stdio.h>

int main()
{
    double a;
    while (scanf("%lf",&a) != EOF)
    {
        if (a<=2000)
            printf("Isento\n");
        else if (a<=3000)
            printf("R$ %.2lf\n",(a-2000)*0.08);
        else if (a<=4500)
            printf("R$ %.2lf\n",1000*0.08 + (a-3000)*0.18);
        else
            printf("R$ %.2lf\n",1000*0.08 + 1500*0.18 + (a-4500)*0.28);
    }
    return 0;
}