#include <stdio.h>

int main()
{
    int A,B,C,D;
    while (scanf("%d %d %d %d",&A,&B,&C,&D) != EOF)
        printf("DIFERENCA = %d\n",A*B-C*D);
    return 0;
}
