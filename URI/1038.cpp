#include <stdio.h>

int main()
{
    int a,b;
    double val;
    while (scanf("%d %d",&a,&b) != EOF)
    {
        if (a==1)
            val = 4.0;
        else if (a==2)
            val = 4.5;
        else if (a==3)
            val = 5.0;
        else if (a==4)
            val = 2.0;
        else if (a==5)
            val = 1.5;
        printf("Total: R$ %.2lf\n",val*b);
    }
    return 0;
}