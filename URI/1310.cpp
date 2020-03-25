#include <stdio.h>

int main()
{
    int N,i,j,k,perDayCost,TotalRevenue,max;
    while (scanf("%d",&N) != EOF)
    {
        scanf("%d",&perDayCost);
        int revenue[N];
        int profit[N][N];
        for (i=0;i<N;i++)
            scanf("%d",&revenue[i]);
        for (i=0;i<N;i++)
            for (j=i;j<N;j++)
            {
                for (k=i,TotalRevenue=0;k<=j;k++)
                    TotalRevenue+=revenue[k];
                profit[i][j] = TotalRevenue - (j-i+1)*perDayCost;
            }
        for (i=0,max=0;i<N;i++)
            for (j=i;j<N;j++)
                if (profit[i][j]>max)
                    max = profit[i][j];
        printf("%d\n",max);
    }
}
