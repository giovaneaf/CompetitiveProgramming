#include <stdio.h>

int main()
{
    int A,B;
    while (scanf("%d %d",&A,&B) != EOF)
    {
        if (A == B || A>B)
            printf("%d\n",A);
        else
            printf("%d\n",B);
    }
    return 0;
}
