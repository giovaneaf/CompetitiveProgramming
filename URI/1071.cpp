#include <stdio.h>

int main()
{
    int x,y,aux,i;
    while (scanf("%d %d",&x,&y) != EOF)
    {
        int sum=0;
        if (y>x)
        {
            aux = y;
            y = x;
            x = aux;
        }
        for (i=y+1;i<x;i++)
            if (i%2)
                sum += i;
        printf("%d\n",sum);
    }
    return 0;
}