#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 300010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
 
struct app
{
	int d, s, id;
	bool operator< (const app& a) const
	{
		return s-d < a.s-a.d;
	}
};
 
int n, c;
app v[510];
int dp[501][10001];
 
int solve(int cur, int mem)
{
	if(cur == n) return 0;
	if(dp[cur][mem] == -1)
	{
		int ans = solve(cur+1, mem);
		if(max(v[cur].d, v[cur].s) <= mem)
		{
			ans = max(ans, 1 + solve(cur+1, mem - v[cur].s));
		}
		dp[cur][mem] = ans;
	}
	return dp[cur][mem];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> c)
	{
		memset(dp, -1, sizeof(dp));
		FOR(i, 0, n)
		{
			cin >> v[i].d >> v[i].s;
			v[i].id = i+1;
		}
		sort(v, v+n);
		int ans = solve(0, c);
		printf("%d\n", ans);
		if(ans > 0)
		{
			vi vv;
			int j = c;
			FOR(i, 0, n)
			{
				if(dp[i][j] == 0) break;
				if(i < n-1 && dp[i][j] != dp[i+1][j])
				{
					vv.emplace_back(v[i].id);
					j -= v[i].s;
				}
				else if(i == n-1 && dp[i][j] == 1)
				{
					vv.emplace_back(v[i].id);
				}
			}
			FOR(i, 0, (int) vv.size())
			{
				if(i > 0) putchar(' ');
				printf("%d", vv[i]);
			}
			putchar('\n');
		}
	}
}