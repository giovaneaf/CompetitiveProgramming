#include <stdio.h>

int main()
{
    int N;
    while (scanf("%d",&N) != EOF)
    {
        int i=0;
        if (N%2)
        {
            printf("%d\n",N);
            i++;
            N += 2;
        }
        else
            N += 1;
        while (i<6)
        {
            printf("%d\n",N);
            N += 2;
            i++;
        }
    }
    return 0;
}