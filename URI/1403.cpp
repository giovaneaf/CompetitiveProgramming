#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int indice;
    int pontos;
}Jogadores;

int compare (const void *a, const void *b)
{
    return ((*(Jogadores*)b).pontos - (*(Jogadores*)a).pontos);
}

int compar (const void *a, const void *b)
{
    return (*(int*)a)-(*(int*)b);
}

int main()
{
    int i,j;
    int N,M;
    while (scanf("%d %d",&N,&M))
    {
        if (N == 0 && M == 0)
            break;
        int aux;
        Jogadores plyr[10000] = {};
        int players[10000]={};
        for (i=0;i<N;i++)
            for (j=0;j<M;j++)
            {
                scanf("%d",&aux);
                plyr[aux-1].indice = aux;
                plyr[aux-1].pontos++;
            }
        qsort(plyr,10000,sizeof(Jogadores),compare);
        aux = plyr[1].pontos;
        i=1;
        do
        {
            players[i-1] = plyr[i].indice;
            i++;
        }
        while (aux == plyr[i].pontos);
        aux = i-1;
        qsort(players,aux,sizeof(int),compar);
        for (i=0;i<aux;i++)
            printf("%d ",players[i]);
        printf("\n");
    }
    return 0;
}
