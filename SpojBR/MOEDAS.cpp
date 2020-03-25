#include <bits/stdc++.h>
 
#define MAXN 10001
#define MOD 1000000007
#define INF 1000000000
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
 
int n, m;
 
int dp[110][50010];
 
int main()
{
	while(scanf("%d", &m))
	{
		if(m == 0) break;
		scanf("%d", &n);
		int v[n];
		for(int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		for(int i = 0; i <= n; ++i)
		{
			dp[i][0] = 0;
		}
		for(int j = 1; j <= m; ++j)
		{
			dp[0][j] = INF;
		}
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				dp[i][j] = dp[i-1][j];
				if(v[i-1] <= j)
					dp[i][j] = min(dp[i][j], 1 + dp[i][j-v[i-1]]);
			}
		}
		if(dp[n][m] == INF)
			printf("Impossivel");
		else
			printf("%d", dp[n][m]);
		putchar('\n');
	}
	return 0;
}