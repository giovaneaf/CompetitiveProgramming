#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 2510
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007;

int n, k;
ll memo[MAXN];

ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
	// Base Case 
	if (a == 0) 
	{ 
		*x = 0, *y = 1; 
		return b; 
	}
	ll x1, y1; // To store results of recursive call 
	ll gcd = gcdExtended(b%a, a, &x1, &y1); 
	// Update x and y using results of recursive call 
	*x = y1 - (b/a) * x1; 
	*y = x1; 
	return gcd; 
}

ll modInverse(ll a, ll m) 
{ 
	ll x, y; 
	ll g = gcdExtended(a, m, &x, &y); 
	// m is added to handle negative x 
	ll res = (x%m + m) % m; 
	return res;
}

ll solveA(int cur, int p, vi* adj, int sizeofK)
{
	if(memo[cur] == -1LL)
	{
		ll ans = 1LL;
		for(int& v : adj[cur])
		{
			if(v == p) continue;
			ans *= solveA(v, cur, adj, sizeofK);
			ans %= mod;
		}
		ans *= (ll) (p == -1 ? sizeofK : sizeofK-1);
		ans %= mod;
		memo[cur] = ans;
	}
	return memo[cur];
}

ll solve(int cur, int p, vi* adj, int sizeofK)
{
	memset(memo, -1LL, sizeof(memo));
	ll ans = solveA(cur, p, adj, sizeofK);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		vi adj[n];
		int v;
		FOR(i, 1, n)
		{
			cin >> v;
			adj[v].emplace_back(i);
			adj[i].emplace_back(v);
		}
		ll ans = 0LL; 
		bool odd = true;
		ll multiplier = 1LL;
		RFOR(i, k, 2)
		{
			ans += (((odd ? 1 : -1)*solve(0, -1, adj, i))*multiplier)%mod;
			ans = (ans + mod)%mod;
			multiplier *= (i*modInverse(k-i+1LL, mod))%mod;
			multiplier %= mod;
			odd = !odd;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
