/*

Fully dynamic convex hull trick not implemented by me.
You can insert in any order of slope and query in any position x

* Author: Simon Lindholm
* Date: 2017-04-20
* License: CC0
* Source: own work
* Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
*  Useful for dynamic programming (``convex hull trick'').
* Time: O(\log N)
* Status: stress-tested

The problem solved here is Machine Works from 2011 ACM ICPC World Finals

*/

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
#define MAXN 110
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
ll c, d;
 
struct machine
{
	ll d, p, r, g;
	bool operator< (const machine& m) { return d < m.d; }
};
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while(cin >> n >> c >> d)
	{
		if(n == 0 && c == 0 && d == 0) break;
		LineContainer l(true);
		vector<machine> v(n);
		FOR(i, 0, n)
		{
			cin >> v[i].d >> v[i].p >> v[i].r >> v[i].g;
		}
		sort(v.begin(), v.end());
		ll maxMoney = c;
		FOR(i, 0, n)
		{
			if(l.size()) maxMoney = max(maxMoney, l.query(v[i].d-1));
			if(maxMoney < v[i].p) continue;
			l.add(v[i].g, (maxMoney+v[i].r)-v[i].p-v[i].g*v[i].d);
		}
		printf("Case %d: %lld\n", t++, max(maxMoney, l.size() ? l.query(d) : 0LL));
	}
	return 0;
}