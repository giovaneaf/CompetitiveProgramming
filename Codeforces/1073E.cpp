#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 210
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<ii> vii;

ll l, r;
int k;
ll mod = 998244353;

pair<ll, ll> dp[20][2][2][(1<<10)+5];
ll poww[20];

void precompute()
{
	poww[0] = 1LL;
	for(int i = 1; i < 20; ++i)
	{
		poww[i] = (poww[i-1]*10LL)%mod;
	}
}

pair<ll, ll> f(int cur, bool tight, bool zero, string& s, int mask, int diff, bool r)
{
	if(diff > k) return {0LL, 0LL};
	if(cur == (int) s.size()) return {1LL, 0LL};
	if(dp[cur][tight][zero][mask].first != -1LL)
	{
		return dp[cur][tight][zero][mask];
	}
	ll ans = 0LL;
	ll value = 0LL;
	for(int i = 0; i < 10; ++i)
	{
		if(tight && i > s[cur]-'0') continue;
		pair<ll, ll> fval = f(cur+1, tight && ((s[cur]-'0') == i), zero && (i == 0), s, ((zero && (i == 0)) ? mask : (mask | (1 << i))), (((mask & (1 << i)) || (zero && (i == 0))) ? diff : diff + 1), r);
		ans += fval.first;
		ans %= mod;
		value += (i*((fval.first*poww[(int) s.size()-1-cur])%mod))%mod;
		value = (value+fval.second)%mod;
	}
	return dp[cur][tight][zero][mask] = {ans, value};
}

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	precompute();
	while(cin >> l >> r >> k)
	{
		for(int i = 0; i < 20; ++i)
		{
			for(int j = 0; j < 2; ++j)
			{
				for(int l = 0; l < 2; ++l)
				{
					for(int m = 0; m < (1<<10)+5; ++m)
					{
						dp[i][j][l][m] = {-1LL, -1LL};
					}
				}
			}
		}
		string str = to_string(r);
		pair<ll, ll> p1 = f(0, true, true, str, 0, 0, true);
		for(int i = 0; i < 20; ++i)
		{
			for(int j = 0; j < 2; ++j)
			{
				for(int l = 0; l < 2; ++l)
				{
					for(int m = 0; m < (1<<10)+5; ++m)
					{
						dp[i][j][l][m] = {-1LL, -1LL};
					}
				}
			}
		}
		str = to_string(l-1);
		pair<ll, ll> p2 = f(0, true, true, str, 0, 0, false);
		cout << (p1.second - p2.second + mod)%mod << '\n';
	}
	return 0;
}