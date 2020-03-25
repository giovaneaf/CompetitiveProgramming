#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
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
	while(cin >> n)
	{
		int e, t;
		cin >> e >> t >> m;
		e--;
		int M[110][110];
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				if(i == j) M[i][j] = 0;
				else M[i][j] = INF;
			}
		}
		FOR(i, 0, m)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			if(M[a][b] > c)
				M[a][b] = c;
		}
		FOR(k, 0, n)
		{
			FOR(a, 0, n)
			{
				FOR(b, 0, n)
				{
					if(M[a][k] < INF && M[k][b] < INF) M[a][b] = min(M[a][b], M[a][k] + M[k][b]);
				}
			}
		}
		int ans = 0;
		FOR(i, 0, n)
		{
			if(M[i][e] <= t) ans++;
		}
		printf("%d\n", ans);
	}
    return 0;
}