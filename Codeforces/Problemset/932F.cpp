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
#define MAXN 100010
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
	LineContainer(bool maxCHT = false) : maxCHT(maxCHT) {}
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
		if(!maxCHT) { k = -k, m = -m; }
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

struct node
{
	ll a, b;
	bool isLeaf;
	int ptr, sz;
	node(ll a = 0LL, ll b = 0LL, bool isLeaf = false, int ptr = -1, int sz = 0) : a(a), b(b), isLeaf(isLeaf), ptr(ptr), sz(sz) {}	
};

int n;
node v[MAXN];
vi inDeg;
vi adj[MAXN];
LineContainer vl[MAXN];
ll memo[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	FOR(i, 0, n) cin >> v[i].a;
	FOR(i, 0, n) cin >> v[i].b;
	int a, b;
	inDeg.assign(n, 0);
	FOR(i, 0, n-1)
	{
		cin >> a >> b;
		a--, b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
		inDeg[a]++; inDeg[b]++;
	}
	queue<int> q;
	int cnt = 0;
	vb inQueue(n, false);
	FOR(i, 1, n)
	{
		if(inDeg[i] == 1)
		{				
			v[i].isLeaf = true;
			v[i].ptr = cnt++;
			v[i].sz = 1;
			q.push(i);
		}
	}
	int cur;
	vb seen(n, false);
	while(q.size())
	{
		cur = q.front();
		q.pop();
		seen[cur] = true;
		if(v[cur].isLeaf)
		{
			memo[cur] = 0LL;
			vl[v[cur].ptr].add(v[cur].b, 0LL);
		}
		else
		{
			if((int) adj[cur].size() > 1)
			{
				// need to merge
				for(int& x : adj[cur])
				{
					if(seen[x] && v[cur].ptr != v[x].ptr)
					{
						for(auto it = vl[v[x].ptr].begin(); it != vl[v[x].ptr].end(); ++it)
						{
							vl[v[cur].ptr].add(-it->k, -it->m);
						}
					}
				}
			}
			memo[cur] = vl[v[cur].ptr].query(v[cur].a);
			vl[v[cur].ptr].add(v[cur].b, memo[cur]);
			v[cur].sz = (int) vl[v[cur].ptr].size();
		}
		for(int& x : adj[cur])
		{
			if(!seen[x])
			{
				inDeg[x]--;
				if((inDeg[x] == 1 && x > 0) || (inDeg[x] == 0 && x == 0)) q.push(x);
				if(v[x].sz < v[cur].sz)
				{
					v[x].sz = v[cur].sz; v[x].ptr = v[cur].ptr;
				}
			}
		}
	}
	printf("%lld", memo[0]);
	FOR(i, 1, n)
	{
		printf(" %lld", memo[i]);
	}
	putchar('\n');
	return 0;
}