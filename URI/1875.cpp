#include <stdio.h>

int main()
{
    int i,j,C,P,R,G,B;
    scanf("%d",&C);
    for (i=0;i<C;i++)
    {
        R=G=B=0;
        scanf("%d",&P);
        char v1,v2;
        for (j=0;j<P;j++)
        {
            scanf(" %c %c",&v1,&v2);
            if (v1 == 'R' && v2 == 'G')
                R += 2;
            else if (v1 == 'R' && v2 == 'B')
                R += 1;
            else if (v1 == 'G' && v2 == 'R')
                G += 1;
            else if (v1 == 'G' && v2 == 'B')
                G += 2;
            else if (v1 == 'B' && v2 == 'R')
                B += 2;
            else if (v1 == 'B' && v2 == 'G')
                B += 1;
        }
        if (R == G && R == B)
            printf("trempate\n");
        else if (R>G && R>B)
            printf("red\n");
        else if (G>B && G>R)
            printf("green\n");
        else if (B>G && B>R)
            printf("blue\n");
        else
            printf("empate\n");
    }
    return (0);
}