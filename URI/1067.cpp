#include <stdio.h>

int main()
{
    int X,i;
    while (scanf("%d",&X) != EOF)
    {
        for (i=1;i<=X;i+=2)
            printf("%d\n",i);
    }
    return 0;
}