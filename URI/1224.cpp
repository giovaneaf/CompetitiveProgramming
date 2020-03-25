#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 10010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
#define comp(a, b) ((a)+(b))

int n, m, s;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		ll v[n];
		FOR(i, 0, n) cin >> v[i];
		ll dp[MAXN][2];
		memset(dp, 0, sizeof(dp));
		int it = 0;
		for(int len = 2; len <= n; len += 2)
		{
			int lastIt = it^1;
			for(int i = 0, j = len-1; j < n; i++, j++)
			{
				dp[i][it] = max(v[i] + min(dp[i+1][lastIt], dp[i+2][lastIt]), 
								v[j] + min(dp[i][lastIt], dp[i+1][lastIt]));
			}
			it = lastIt;
		}
		it = it^1;
		printf("%lld\n", dp[0][it]);
	}
	return 0;
} 