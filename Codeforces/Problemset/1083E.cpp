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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
 
 
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	bool maxCHT;
	LineContainer(bool maxCHT) : maxCHT(maxCHT) {}
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		if(!maxCHT) k = -k, m = -m;
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return maxCHT ? l.k * x + l.m : -(l.k * x + l.m);
	}
};
 
int n;
 
struct st
{
	ll x, y, a;
	bool operator< (const st& s) { return x < s.x; }
};
 
st v[MAXN];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		LineContainer l(true);
		FOR(i, 0, n) cin >> v[i].x >> v[i].y >> v[i].a;
		sort(v, v+n);
		ll ans = 0LL;
		ll tmp;
		FOR(i, 0, n)
		{
			tmp = max(0LL, v[i].x*v[i].y-v[i].a);
			if(l.size())
				tmp = tmp + max(0LL, l.query(v[i].y));
			ans = max(ans, tmp);
			l.add(-v[i].x, tmp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}