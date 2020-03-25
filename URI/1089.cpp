#include <stdio.h>

int main()
{
    while (1)
    {
        int N,i,count=0;
        scanf("%d",&N); // nº de magnitudes
        if (N==0) // para qdo digita 0
            break;
        int magn[N]; // vetor com as N magnitudes
        for (i=0;i<N;i++)
            scanf("%d",&magn[i]);
        if ((magn[0]>magn[1] && magn[0]>magn[N-1]) || (magn[0]<magn[1] && magn[0]<magn[N-1]))
            count++;
        if ((magn[N-1]>magn[0] && magn[N-1]>magn[N-2]) || (magn[N-1]<magn[0] && magn[N-1]<magn[N-2]))
            count++;
        for (i=1;i<N-1;i++)
        {
            if ((magn[i]>magn[i+1] && magn[i]>magn[i-1]) || (magn[i]<magn[i+1] && magn[i]<magn[i-1]))
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
