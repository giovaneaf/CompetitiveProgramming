#include <iostream>
#include <stdlib.h>
using namespace std;

int knapsack(int,int*,int,int*,int*);
int max(int,int);
int compare(const void*,const void*);

int main()
{
    int tam;
    int v[100];
    int k[3];
    int N,K;
    int i,j,h,l;
    int soma = 0;
    cin >> N;
    cin >> K;
    for (i=0;i<N;i++)
        cin >> v[i];
    for (i=0;i<K;i++)
        cin >> k[i];
    qsort(v,N,sizeof(int),compare);
    h=0;
    while (h<K)
    {
        int used[100] = {};
        soma += knapsack(k[h],v,N,used,&tam);
        int cont = 0;
        i = N-1;
        while (cont<tam)
        {
            if (used[cont] == v[i])
            {
                v[i] = -1;
                cont++;
            }
            i--;
        }
        i = 0;
        while (i < N)
        {
            if (v[i] == -1)
            {
                for (j=i; j<N-1; j++)
                {
                    v[j] = v[j+1];
                }
                N--;
                i--;
            }
            i++;
        }
        h++;
    }
    cout << soma << endl;
    return 0;
}

int knapsack(int max_val,int* vec, int N,int* used,int* tam)
{
    int i,j,fi,fj,cpy;
    int M[100][51]={};
    j = 1;
    while (vec[0] > j && j < max_val+1)
    {
        j++;
    }
    while (j < max_val+1)
    {
        M[0][j] = vec[0];
        j++;
    }
    for (i = 1;i < N; i++)
    {
        for (j = 1;j < max_val+1; j++)
        {
            if (vec[i] > j)
                M[i][j] = M[i-1][j];
            else
            {
                M[i][j] = max(M[i-1][j], vec[i]+M[i-1][j-vec[i]]);
            }
        }
    }
    int maximum = 0;
    for (i=0;i<N;i++)
        if (M[i][max_val] >= maximum)
        {
            maximum = M[i][max_val];
            fi = i;
            fj = j;
        }
    fj--;
    cpy = maximum;
    *tam = 0;
    while (cpy > 0 && fi > 0)
    {
        if (vec[fi]+M[fi-1][fj-vec[fi]] < M[fi-1][fj])
        {
            fi -= 1;
        }
        else if (vec[fi]+M[fi-1][fj-vec[fi]] <= cpy)
        {
            used[(*tam)] = vec[fi];
            cpy -= vec[fi];
            fj -= vec[fi];
            fi -= 1;
            (*tam)++;
        }
        else
            fi -= 1;
    }
    if (cpy != 0)
    {
        used[(*tam)] = vec[fi];
        (*tam)++;
    }
    return maximum;
}

int max (int a, int b)
{
    return (a > b ? a : b);
}

int compare(const void* a,const void* b)
{
    return ( *(int*)a - *(int*)b );
}