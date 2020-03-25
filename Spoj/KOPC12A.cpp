#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, m, t;
ll h[MAXN];
ll c[MAXN];
 
ll f(ll x)
{
	ll ans = 0LL;
	FOR(i, 0, n)
	{
		ans += abs(h[i]-x)*c[i];
	}
	return ans;
}
 
ll ans(int l, int r)
{
	ll cost = f(l);
	FOR(i, l+1, r+1)
	{
		cost = min(cost, f(i));
	}
	return cost;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> t)
	{
		while(t--)
		{
			cin >> n;
			FOR(i, 0, n) cin >> h[i];
			FOR(i, 0, n) cin >> c[i];
			ll l, r, fh, sh;
			l = 0LL; r = 10000LL;
			while(r-l > 2)
			{
				fh = l + (r-l)/3;
				sh = l + (2*(r-l))/3;
				if(f(fh) <= f(sh))
					r = sh;
				else
					l = fh;
			}
			printf("%lld\n", ans(l, r));
		}
	}
	return 0;
} 