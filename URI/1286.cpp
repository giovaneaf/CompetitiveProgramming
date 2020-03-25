#include <iostream>
#include <cstring>

using namespace std;

typedef struct
{
    int pizzas;
    int time;
} att;

int main()
{
    int N;
    while(cin >> N && N != 0)
    {
        int P, i, j;
        cin >> P;
        int M[N+1][P+1];
        memset(M, 0, sizeof(M));
        att v[N];
        for(i = 0; i < N; i++)
        {
            cin >> v[i].time >> v[i].pizzas;
        }
        for(i = 1; i < N+1; i++)
        {
            for(j = 0; j < P+1; j++)
            {
                if(v[i-1].pizzas > j)
                    M[i][j] = M[i-1][j];
                else
                    M[i][j] = max(M[i-1][j], v[i-1].time + M[i-1][j-v[i-1].pizzas]);
            }
        }
        cout << M[N][P] << " min." << endl;
    }
    return 0;
}