#include <stdio.h>

inic(int v[],int n)
{
    int i;
    for (i=0;i<n;i++)
        v[i] = i+1;
}

void mostra(int v[],int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%d ",v[i]);
    putchar('\n');
}

ordena(int v[],int n,int j) // J e N do V ou F
{
    int i;
    for (i=j;i<n;i++)
    {
        v[i] = v[i+1];
        if (i == n-1)
        {
            v[n-1] = v[j];
            v[j] = 0;
        }
    }
}

main()
{
    int n,i;
    while (1)
    {
        scanf("%d",&n);
        if (n == 0)
            return 0;
        int v[n];
        inic(v,n);
        printf("Discarded cards: ");
        for (i=0;i<n-1;i++)
        {
            if (i<n-2)
                printf("%d, ",v[i]);
            else
                printf("%d\n",v[i]);
            ordena(v,n,i);
        }
        printf("Remaining card: %d\n",v[n-1]);
    }
}