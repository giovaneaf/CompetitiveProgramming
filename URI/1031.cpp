#include <stdio.h>

int main()
{
    int N,m,stop,i,j,cont;
    while(scanf("%d",&N) != EOF)
    {
        if (N==0)
            break;
        int v[N];
        for (m=1,stop=1;stop;m++)
        {
            for (i=0;i<N;i++)
                v[i]=i+1;
            for (i=0,cont=0,j=m;cont<N-1;j++,i++)
            {
                if(v[i]==0)
                    j--;
                else if (j==m)
                {
                    v[i]=0;
                    j=0;
                    cont++;
                }
                if (i==N-1)
                    i=-1;
            }
            i=-1;
            do
            {
                i++;
            }
            while (v[i] == 0);
            if (v[i] == 13)
                stop=0;
        }
        printf("%d\n",m-1);
    }
    return 0;
}
