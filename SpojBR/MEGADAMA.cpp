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
#define MAXN 50010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, q;
int dr[] = {1, 1, -1, -1};
int dc[] = {1, -1, 1, -1};
int M[21][21];
 
int capture(int r, int c)
{
	int ans = 0;
	FOR(i, 0, 4)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nr >= n || nc < 0 || nc >= m || M[nr][nc] < 2) continue;
		int nnr = r + 2*dr[i];
		int nnc = c + 2*dc[i];
		if(nnr < 0 || nnr >= n || nnc < 0 || nnc >= m || M[nnr][nnc] > 0) continue;
		M[nr][nc] = 0;
		ans = max(ans, 1 + capture(nnr, nnc));
		M[nr][nc] = 2;
	}
	return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		FOR(i, 0, n) FOR(j, 0, m) M[i][j] = 0;
		int xr = 0;
		RFOR(i, n-1, 0)
		{
			for(int j = xr; j < m; j += 2)
			{
				cin >> M[i][j];
			}
			xr ^= 1;
		}
		int ans = 0;
		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				if(M[i][j] == 1)
				{
					M[i][j] = 0;
					ans = max(ans, capture(i, j));
					M[i][j] = 1;
				}
			}
		}
		printf("%d\n", ans);
	}
    return 0;
} 