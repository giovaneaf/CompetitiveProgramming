#include <bits/stdc++.h>

#define INF 1000000000
#define MAXN 300010
#define EPS 1e-9

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

int n, f;
int num[45];
set<char> sz[45];
int dp[45][80010];

bool solve(int pos, int sum)
{
	if(pos == n) return sum == f;
	if(dp[pos][sum] != -1) return dp[pos][sum];
	int ans = 0;
	if(solve(pos+1, sum+num[pos]) == 1)
	{
		sz[pos].insert('+');
		ans = 1;
	}
	if(solve(pos+1, sum-num[pos]) == 1)
	{
		sz[pos].insert('-');
		ans += 2;
	}
	return dp[pos][sum] = ans;
}

int main()
{
	while(cin >> n >> f)
	{
		if(n == 0) break;
		f += 40000;
		for(int i = 0; i < n; ++i)
		{
			sz[i].clear();
			cin >> num[i];
		}
		memset(dp, -1, sizeof(dp));
		solve(0, 40000);
		for(int i = 0; i < n; ++i)
		{
			if(sz[i].size() == 0)
			{
				printf("*");
				break;
			}
			else if(sz[i].size() == 2)
			{
				printf("?");
			}
			else
			{
				printf("%c", *sz[i].begin());
			}
		}
		putchar('\n');
	}
	return 0;
}