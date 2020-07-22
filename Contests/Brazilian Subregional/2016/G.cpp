#include <stdio.h>

void npecas(int V[500][500],int N)
{
    int i,j,n;
    n=0;
        for(j=0;j<N;j++)
        {
            if (V[0][j] == 1)
                n++;
            V[0][j] = n;
        }
    n=0;
        for (i=0;i<N;i++)
        {
            if (V[i][0] == 1)
                n++;
            V[i][0] = n;
        }
    for (i=1;i<N;i++)
        for (j=1;j<N;j++)
            V[i][j] = V[i][j] + V[i][j-1] + V[i-1][j]-V[i-1][j-1];
}

void square(int B[500][500],int W[500][500],int N,int B_W[2])
{
    int sqr,i,j,nb,nw;
    for(sqr=1;sqr<N;sqr++)
        for(j=0,nb=0,nw=0;j<(N-sqr);j++)
        {
            if(B[sqr+j][sqr]-nb > 0 && W[sqr+j][sqr]-nw == 0)
                B_W[0]++;
            if(W[sqr+j][sqr]-nw > 0 && B[sqr+j][sqr]-nb == 0)
                B_W[1]++;
            nb = B[j][sqr];
            nw = W[j][sqr];
        }
    for(sqr=1;sqr<N-1;sqr++)
        for(i=1;i<N-sqr;i++)
        {
            if(B[sqr][sqr+i]-B[sqr][i-1] > 0 && W[sqr][sqr+i]-W[sqr][i-1] == 0)
                B_W[0]++;
            if(B[sqr][sqr+i]-B[sqr][i-1] == 0 && W[sqr][sqr+i]-W[sqr][i-1] > 0)
                B_W[1]++;
        }
    for (sqr=1;sqr<N-1;sqr++)
        for(j=1;j<N-sqr;j++)
            for(i=1;i<N-sqr;i++)
            {
                if(B[sqr+j][sqr+i]-B[sqr+j][i-1]-B[j-1][sqr+i]+B[j-1][i-1] > 0 && W[sqr+j][sqr+i]-W[sqr+j][i-1]-W[j-1][sqr+i]+W[j-1][i-1] == 0)
                    B_W[0]++;
                if(B[sqr+j][sqr+i]-B[sqr+j][i-1]-B[j-1][sqr+i]+B[j-1][i-1] == 0 && W[sqr+j][sqr+i]-W[sqr+j][i-1]-W[j-1][sqr+i]+W[j-1][i-1] > 0)
                    B_W[1]++;
            }
}

int main()
{
    int N,P,i,j,x,y;
    while (scanf("%d %d",&N,&P) != EOF)
    {
        int Black[500][500] = {};
        int White[500][500] = {};
        for (i=0;i<P;i++)
        {
            scanf("%d %d",&x,&y);
            Black[x-1][y-1] = 1;
        }
        for (i=0;i<P;i++)
        {
            scanf("%d %d",&x,&y);
            White[x-1][y-1] = 1;
        }
        npecas(Black,N);
        npecas(White,N);
        int B_W[2]= {P,P};
        square(Black,White,N,B_W);
        printf("%d %d\n",B_W[0],B_W[1]);
    }
    return 0;
}