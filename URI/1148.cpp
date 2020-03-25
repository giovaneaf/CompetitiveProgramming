#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 200010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, k;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int N, E;
    while(true)
    {
        cin >> N >> E;
        if (N == 0)
            break;
        int i,j,v1,v2,w;
        int M[N][N];
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
				if(i == j) M[i][j] = 0;
                else M[i][j] = INF;
        for (i = 0; i < E; i++)
        {
            cin >> v1 >> v2 >> w;
            M[v1-1][v2-1] = w;
        }
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
            {
				if (i != j && M[i][j] < INF && M[j][i] < INF)
				{
					M[i][j] = M[j][i] = 0;
				}
            }
		FOR(k, 0, N) FOR(i, 0, N) FOR(j, 0, N) if(M[i][k] < INF && M[k][j] < INF) M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
        int K;
        cin >> K;
        for (i = 0; i < K; i++)
        {
            cin >> v1 >> v2;
			v1--, v2--;
            if (M[v1][v2] == INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", M[v1][v2]);
        }
        putchar('\n');
    }
    return 0;
}