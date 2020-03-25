#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 60
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m;
const ll mod = 1e9+7;
ll dp[2510][2510];

ll nck(int n, int k)
{
	if(k == 0 || k == n || n <= 1) return 1LL;
	if(dp[n][k] == -1LL)	
	{
		ll ans = (nck(n-1, k-1) + nck(n-1, k))%mod;
		dp[n][k] = ans;
	}
	return dp[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		memset(dp, -1LL, sizeof(dp));
		string M[MAXN];
		FOR(i, 0, n)
			cin >> M[i];
		int memo[MAXN][MAXN];
		FOR(i, 0, n+1) memo[i][0] = 0;
		FOR(i, 0, m+1) memo[0][i] = 0;
		FOR(i, 1, n+1)
		{
			FOR(j, 1, m+1)
			{
				memo[i][j] = memo[i-1][j] + memo[i][j-1] - memo[i-1][j-1] + (M[i-1][j-1] == '#');
				//printf("%2d ", memo[i][j]);
			}
			//putchar('\n');
		}
		int minr, minc, maxr, maxc;
		while(cin >> minr >> minc >> maxr >> maxc)
		{
			
			int num = memo[maxr][maxc] - memo[minr-1][maxc] - memo[maxr][minc-1] + memo[minr-1][minc-1];
			ll ans = 0LL;
			ans = nck((maxr-minr+1)*(maxc-minc+1), num) - 1;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
