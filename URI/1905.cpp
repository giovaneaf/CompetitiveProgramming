#include <iostream>
using namespace std;

int winner;

bool busca(int M[5][5], bool Vis[5][5], int i, int j)
{
    if(i>-1 && i<5 && j>-1 && j<5 && !winner)
    {
        Vis[i][j] = true;
        if (i==4 && j==4)
            winner=1;
        else
        {
            if(i+1<5 && M[i+1][j]==0 && !Vis[i+1][j])
                busca(M, Vis,i+1,j);
            if(i-1>-1 && M[i-1][j]==0 && !Vis[i-1][j])
                busca(M, Vis,i-1,j);
            if(j+1<5 && M[i][j+1]==0 && !Vis[i][j+1])
                busca(M, Vis,i,j+1);
            if(j-1>-1 && M[i][j-1]==0 && !Vis[i][j-1])
                busca(M, Vis,i,j-1);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    while(N>0)
    {
        bool Visitados[5][5];
        int M[5][5];
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
            {
                cin >> M[i][j];
                Visitados[i][j]=false;
            }
        Visitados[0][0] = true;
        winner = 0;
        busca(M,Visitados,0,0);
        if (winner)
            cout << "COPS\n";
        else
            cout << "ROBBERS\n";
        N--;
    }
    return 0;
}