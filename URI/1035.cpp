#include <stdio.h>

main()
{
    int A,B,C,D;
    while(scanf("%d %d %d %d",&A,&B,&C,&D)!=EOF)
        if (B>C && D>A && (C+D)>(A+B) && C>0 && D>0 && A%2 == 0)
            printf("Valores aceitos\n");
        else
            printf("Valores nao aceitos\n");
    return 0;
}