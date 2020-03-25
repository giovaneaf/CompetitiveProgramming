#include <stdio.h>

void inic (int v[],int N)
{
    int i;
    for (i=0;i<N;i++)
        v[i] = 0;
}

int overtakes (int start[],int end[],int passou[],int N)
{
    int i,j,k,over,pos;
    for (i=0,over=0;i<N;i++)
    {
        for(j=i,pos=-1;end[i]!=start[j];j++)
        {
            over++;
            pos=j;
        }
        for (k=pos+1;k!=0 && k>i;k--)
            start[k] = start[k-1];
    }
    return over;
}

int main()
{
    int N,i;
    while (scanf("%d",&N) != EOF)
    {
        int start[N];
        int end[N];
        int passou[N];
        inic(passou,N);
        for (i=0;i<N;i++)
            scanf("%d",&start[i]);
        for (i=0;i<N;i++)
            scanf("%d",&end[i]);
        printf("%d\n",overtakes(start,end,passou,N));
    }
    return 0;
}