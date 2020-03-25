#include <stdio.h>

int main()
{
    int N,var;
    while (scanf("%d",&N) != EOF)
    {
        var = N/3600.0;
        printf("%d:",var);
        if (var>0)
        {
            N %= 3600;
        }
        var = N/60.0;
        printf("%d:",var);
        if (var>0)
        {
            N %= 60;
        }
        printf("%d\n",N);
    }
    return 0;
}