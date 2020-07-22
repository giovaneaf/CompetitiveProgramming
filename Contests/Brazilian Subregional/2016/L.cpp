#include <iostream>

using namespace std;

int area(int M[][200],int i, int j, int H, int L, bool visitado[][200]) // calcula a área da lajota
{
    int val = 1; // inicializa a área com tamanho 1
    visitado[i][j] = true; // marca como visitado
    if (i > 0) // se o i é maior que zero
    {
        if (M[i][j] == M[i-1][j] && !visitado[i-1][j])
        {
            val += area(M,i-1,j,H,L,visitado);
        }
    }
    if (i < H-1) // se o i é menor que H-1
    {
        if (M[i][j] == M[i+1][j] && !visitado[i+1][j])
        {
            val += area(M,i+1,j,H,L,visitado);
        }
    }
    if (j > 0) // se o j é maior que zero
    {
        if (M[i][j] == M[i][j-1] && !visitado[i][j-1])
        {
            val += area(M,i,j-1,H,L,visitado);
        }
    }
    if (j < L-1) // se o j é menor que L-1
    {
        if (M[i][j] == M[i][j+1] && !visitado[i][j+1]) // se as cores são iguais
        {
            val += area(M,i,j+1,H,L,visitado); // soma a área dele com a dos outros
        }
    }
    return val; // retorna o valor da área
}

int menor(int M[][200], int H, int L)
{
    int i, j, aux, minimo = H*L;
    bool visitado[200][200];
    for (i = 0; i < H; i++)
        for (j = 0; j < L; j++)
            visitado[i][j] = false;
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < L; j++)
        {
            if (!visitado[i][j])
            {
                aux = area(M,i,j,H,L,visitado);
                if (aux < minimo)
                    minimo = aux;
            }
        }
    }
    return minimo;
}

int main()
{
    int H,L;
    cin >> H >> L;
    int M[200][200];
    int color;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < L; j++)
            cin >> M[i][j];
    cout << menor(M,H,L) << endl;
    return 0;
}