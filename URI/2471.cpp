#include <iostream>

using namespace std;

int main()
{
    int i,j,N;
    cin >> N;
    int M[N][N];
    bool achou = false;
    int ix, iy;
    int MVal = 0;
    int lin, aux;
    for (i = 0; i < N; i++)
    {
        lin = 0;
        for (j = 0; j < N; j++)
        {
            cin >> M[i][j];
            lin += M[i][j];
        }
        if (!MVal)
            MVal = lin;
        else if (!achou)
        {
            if (i == 1)
            {
                if (MVal == lin)
                {
                    achou = true;
                }
                else
                {
                    aux = lin;
                }
            }
            else
            {
                if (MVal == lin)
                {
                    achou = true;
                }
                else
                {
                    MVal = aux;
                    achou = true;
                }
            }
        }
    }
    for (i = 0; i < N; i++)
    {
        lin = 0;
        for (j = 0; j < N; j++)
        {
            lin += M[i][j];
        }
        if (lin != MVal)
        {
            ix = i;
            break;
        }
    }
    int col;
    for (j = 0; j < N; j++)
    {
        col = 0;
        for (i = 0; i < N; i++)
        {
            col += M[i][j];
        }
        if (col != MVal)
        {
            iy = j;
            break;
        }
    }
    lin = 0;
    for (i = 0; i < N; i++)
    {
        if (i != ix)
        {
            lin += M[i][iy];
        }
    }
    cout << (MVal-lin) << " " << M[ix][iy] << endl;
    return 0;
}
