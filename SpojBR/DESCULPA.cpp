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
 
int c, f;
 
pair<int, int> v[60];
 
int dp[60][1010];
 
int solve(int cf, int cc)
{
	if(cf == f)
		return 0;
	if(dp[cf][cc] == -1)
	{
		int ans = solve(cf+1, cc);
		if(v[cf].first <= cc)
			ans = max(ans, v[cf].second + solve(cf+1, cc - v[cf].first));
		dp[cf][cc] = ans;
	}
	return dp[cf][cc];
}
 
int main()
{
	int t = 1;
	while(scanf("%d %d", &c, &f))
	{
		if(c == 0) break;
		for(int i = 0; i < f; ++i)
			scanf("%d %d", &v[i].first, &v[i].second);
		for(int i = 0; i <= f; ++i)
		{
			for(int j = 0; j <= c; ++j)
			{
				dp[i][j] = -1;
			}
		}
		int ans = solve(0, c);
		printf("Teste %d\n", t++);
		printf("%d\n", ans);
		putchar('\n');
	}
	return 0;
}