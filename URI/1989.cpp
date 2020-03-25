#include <stdio.h>

int main()
{
    int N,M,i,j;
    unsigned long long int soma,total;
    while(scanf("%d %d",&N,&M) != EOF)
    {
        if (N==-1 && M==-1)
            break;
        int cap[N];
        for (i=0,soma=0,j=N;i<N;i++,j--)
        {
            scanf("%d",&cap[i]);
            soma += j*cap[i];
        }
        total = soma*M;
        printf("%llu\n",total);
    }
    return 0;
}