#include <stdio.h>
#include <math.h>

int main()
{
    int i,N,j,k;
    long long int X;
    scanf("%d",&N);
    for (i=0;i<N;i++)
    {
        scanf("%lld",&X);
        if (X%2 == 0 && X > 2)
            printf("Not Prime\n");
        else
            if (X==2 || X==3 || X==5 || X==7)
                printf("Prime\n");
            else
            {
                for (j=2;(int)pow(j,2)<=X;j++)
                    ;
                if (j%2==0)
                    j--;
                else
                    j-=2;
                for (k=3;k<=j && X%k != 0;k+=2)
                    ;
                if (k==j+2 && X%j != 0)
                    printf("Prime\n");
                else
                    printf("Not Prime\n");
            }
    }
    return 0;
}
