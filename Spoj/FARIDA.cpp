#include <bits/stdc++.h>
 
#define MAXN 10001
#define MOD 10000007
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
 
ll dp[MAXN];
int arr[MAXN];
 
int n;
 
ll solve(int cur)
{
	if(cur >= n)
		return 0;
	if(dp[cur] == -1LL)
	{
		dp[cur] = max(solve(cur+1), arr[cur] + solve(cur+2));
	}
	return dp[cur];
}
 
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			dp[i] = -1LL;
		}
		printf("Case %d: %lld\n", t, solve(0));
	}
	return 0;
}