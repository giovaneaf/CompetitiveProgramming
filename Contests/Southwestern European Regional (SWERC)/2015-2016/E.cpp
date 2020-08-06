#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 1010
#define MOD 2147483647
#define INF 1e9
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
ll dp[2010][2010];
int v[2010];
 
int n;
 
ll solve(int j, int k)
{
	if(k == n+1) return 1;
	if(dp[j][k] != -1LL) return dp[j][k];
	ll ans;
	if((v[k] < v[k+1] && v[k] < v[j] && v[j] > v[k+1]) || (v[k] > v[k+1] && v[k] > v[j] && v[j] < v[k+1]))
		ans = (solve(j, k+1) + solve(k, k+1))%MOD;
	else if((v[j] < v[k] && v[k] < v[k+1]) || (v[j] > v[k] && v[k] > v[k+1]))
		ans = solve(j, k+1);
	else
		ans = solve(k, k+1);
	return dp[j][k] = ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		for(int i = 0; i <= n; ++i)
		{
			cin >> v[i];
			for(int j = 0; j <= n; ++j) dp[i][j] = -1LL;
		}
		cout << solve(0, 1) << '\n';
	}
    return 0;
}