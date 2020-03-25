#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 40
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9


int n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	FOR(t, 0, T)
	{
		cin >> n;
		int maxW;
		cin >> maxW;
		int memo[2][1010];
		memset(memo, 0, sizeof(memo));
		int V[110];
		int W[110];
		FOR(i, 0, n) cin >> V[i] >> W[i];
		int it = 0;
		FOR(i, 0, n)
		{
			int next = it^1;
			FOR(j, 0, maxW+1)
			{
				if(j < W[i]) memo[it][j] = memo[next][j];
				else memo[it][j] = max(memo[next][j], V[i] + memo[next][j-W[i]]);
			}
			it = next;
		}
		it ^= 1;
		printf("Galho %d:\n", t+1);
		printf("Numero total de enfeites: %d\n\n", memo[it][maxW]);
	}
	return 0;
} 