#include <stdio.h>

int main()
{
    int A,B,C,maior;
    while (scanf("%d %d %d",&A,&B,&C) != EOF)
    {
        maior = (A+B+abs(A-B))/2.0;
        maior = (maior+C+abs(maior-C))/2.0;
        printf("%d eh o maior\n",maior);
    }
    return 0;
}
