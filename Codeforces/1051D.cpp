#include <bits/stdc++.h>

#define MAXN 100010
#define INF 1e9
#define EPS 1e-9
#define MOD 998244353

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef long long ll;

int n, k;

ll dp[1010][2010][7];

int f(int s)
{
	if(s == 0 || s == 3) return 1;
	return 2;
}

ll solve(int pos, int sz, int st)
{
	if(st == -1)
	{
		return ((((solve(pos+1, sz, 0) + solve(pos+1, sz, 1))%MOD + solve(pos+1, sz, 2))%MOD + solve(pos+1, sz, 3))%MOD) ;
	}
	if(pos == n) return (sz + f(st) == k);
	if(sz + f(st) > k) return 0LL;
	if(dp[pos][sz][st] != -1LL) return dp[pos][sz][st];
	ll ans = 0LL;
	if(st == 0)
	{
		ans = solve(pos+1, sz, 0);
		ans = (ans+solve(pos+1, sz, 1))%MOD;
		ans = (ans+solve(pos+1, sz, 2))%MOD;
		ans = (ans+solve(pos+1, sz+1, 3))%MOD;
	}
	else if(st == 1)
	{
		ans = solve(pos+1, sz+1, 0);
		ans = (ans+solve(pos+1, sz, 1))%MOD;
		ans = (ans+solve(pos+1, sz+2, 2))%MOD;
		ans = (ans+solve(pos+1, sz+1, 3))%MOD;
	}
	else if(st == 2)
	{
		ans = solve(pos+1, sz+1, 0);
		ans = (ans+solve(pos+1, sz+2, 1))%MOD;
		ans = (ans+solve(pos+1, sz, 2))%MOD;
		ans = (ans+solve(pos+1, sz+1, 3))%MOD;
	}
	else
	{
		ans = solve(pos+1, sz+1, 0);
		ans = (ans+solve(pos+1, sz, 1))%MOD;
		ans = (ans+solve(pos+1, sz, 2))%MOD;
		ans = (ans+solve(pos+1, sz, 3))%MOD;
	}
	return dp[pos][sz][st] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		memset(dp, -1LL, sizeof(dp));
		cout << solve(0, 0, -1) << '\n';
	}
	return 0;
}
