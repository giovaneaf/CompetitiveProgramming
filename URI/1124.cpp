#include <stdio.h>
#include <math.h>

float hyp(a,b)
{
    return (float)sqrt(pow(a,2.0) + pow(b,2.0));
}

int main()
{
    int L,C,R1,R2,aux;
    while (scanf ("%d %d %d %d",&L,&C,&R1,&R2) != EOF)
    {
        if (L == 0 && C == 0 && R1 == 0 && R2 == 0)
            break;
        if (C>L)
        {
            aux = C;
            C = L;
            L = aux;
        }
        if (R2>R1)
        {
            aux = R2;
            R2 = R1;
            R1 = aux;
        }
        if (R1 <= C/2.0 && hyp(L-R1-R2,C-R1-R2) >= (R1+R2))
            printf("S\n");
        else
            printf("N\n");
    }
    return 0;
}