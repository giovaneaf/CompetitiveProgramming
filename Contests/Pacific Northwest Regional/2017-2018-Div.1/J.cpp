#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 35
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m;
ll dp[MAXN][MAXN];
bool seen[MAXN][MAXN];
string M[MAXN];
bool can;
 
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
 
void fill(int r, int c, int v)
{
	seen[r][c] = true;
	FOR(i, 0, 2)
	{
		int nr = r + dr[i+v];
		int nc = c + dc[i+v];
		if(nr < 0 || nr >= n || nc < 0 || nc >= m || seen[nr][nc]) continue;
		if((M[nr][nc] == 'R' && v == 0) || (M[nr][nc] == 'B' && v == 2))
		{
			can = false;
			return ;
		}
		M[nr][nc] = (v == 0 ? 'B' : 'R');
		fill(nr, nc, v);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
		memset(dp, 0LL, sizeof(dp));
		memset(seen, false, sizeof(seen));
		FOR(i, 0, n)
		{
			cin >> M[i];
		}
		can = true;
		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				if(M[i][j] == 'B')
				{
					fill(i, j, 0);
				}
				else if(M[i][j] == 'R')
				{
					fill(i, j, 2);
				}
				if(!can) break;
			}
			if(!can) break;
		}
		if(!can)
		{
			printf("0\n");
		}
		else
		{
			int lastBlue = 0;
			int firstRed = n+1;
			FOR(i, 1, n+1)
			{
				if(M[i-1][0] == 'B') lastBlue = i;
				else if(firstRed == n+1 && M[i-1][0] == 'R') firstRed = i;
			}
			FOR(i, lastBlue, firstRed)
			{
				dp[i][0]++;
			}
			FOR(j, 1, m)
			{
				int lastBlue = 0;
				int firstRed = n+1;
				FOR(i, 1, n+1)
				{
					if(M[i-1][j] == 'B') lastBlue = i;
					else if(firstRed == n+1 && M[i-1][j] == 'R') firstRed = i;
				}
				FOR(i, lastBlue, firstRed)
				{
					FOR(k, i, n+1)
					{
						dp[i][j] += dp[k][j-1];
					}
				}
			}
			ll ans = 0LL;
			FOR(i, 0, n+1)
			{
				ans += dp[i][m-1];
			}
			printf("%lld\n", ans);
		}
    }
	return 0;
}