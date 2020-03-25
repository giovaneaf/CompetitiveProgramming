#include <stdio.h>

int main()
{
    int N,i,j;
    scanf("%d",&N);
    for (i=0;i<N;i++)
    {
        double food;
        scanf("%lf",&food);
        for (j=0;food>1.0;j++)
            food /= 2;
        printf("%d dias\n",j);
    }
    return 0;
}
