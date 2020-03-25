#include <stdio.h>

main()
{
    double A,B,C,aux;
    scanf("%lf %lf %lf",&A,&B,&C);
    if (A > 0 && B > 0 && C > 0)
    {
        aux = A;
        if (B>=A && B>=C)
        {
            A=B;
            B=aux;
        }
        if (C>=A && C>=B)
        {
            A=C;
            C=aux;
        }
        if (B<C)
        {
            aux = B;
            B = C;
            C = aux;
        }
        if (A >= (B+C))
            printf("NAO FORMA TRIANGULO\n");
        else
        {
            if ((A*A)==(B*B+C*C))
            printf("TRIANGULO RETANGULO\n");
            if ((A*A) > (B*B+C*C))
                printf("TRIANGULO OBTUSANGULO\n");
            if ((A*A) < (B*B+C*C))
                printf("TRIANGULO ACUTANGULO\n");
            if (A == B && A == C)
                printf("TRIANGULO EQUILATERO\n");
            if ((A == B || A == C || B == C) && (!(A==B && A==C)))
                printf("TRIANGULO ISOSCELES\n");
        }
    }
}