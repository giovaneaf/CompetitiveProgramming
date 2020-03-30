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
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, m;
map<ii, int> mm;
ll t[MAXN];
ll nNodes[MAXN];
ii edge[MAXN];
pair<ll, ll> tax[MAXN];
ll sumdist;
ll totalTax;
ll ans[MAXN];
 
pair<int, ll> DFS(int u, vb& seen, vii* adj)
{
	seen[u] = true;
	int nodes, v, taxx;
	pair<int, ll> tmp;
	nodes = 1; taxx = t[u];
	for(ii& p : adj[u])
	{
		v = p.fst;
		if(!seen[v])
		{
			tmp = DFS(v, seen, adj);
			int id = mm[{min(u, v), max(u, v)}];
			edge[id] = {n-tmp.fst, tmp.fst};
			tax[id] = {totalTax-tmp.snd, tmp.snd};
			nodes += tmp.fst;
			taxx += tmp.snd;
		}
	}
	return mp(nodes, taxx);
}
 
pair<ll, ll> compute(int u, vb& seen, vii* adj, ll dist)
{
	seen[u] = true;
	int v, w;
	ll d = dist;
	ll dd = dist*t[u];
	pair<ll, ll> pp;
	for(ii& p : adj[u])
	{
		v = p.fst;
		if(!seen[v])
		{
			w = p.snd;
			pp = compute(v, seen, adj, dist+w);
			d += pp.fst;
			dd += pp.snd;
		}
	}
	return mp(d, dd);
}
 
void computeAll(int u, vb& seen, vii* adj, pair<ll, ll> p)
{
	seen[u] = true;
	ans[u] = p.fst*t[u] + p.snd;
	int v, w;
	pair<ll, ll> newP;
	for(ii& pp : adj[u])
	{
		v = pp.fst;
		if(!seen[v])
		{
			w = pp.snd;
			int id = mm[{min(u, v), max(u, v)}];
			newP.fst = p.fst + w*(edge[id].fst-edge[id].snd);
			newP.snd = p.snd + w*(tax[id].fst-tax[id].snd);
			computeAll(v, seen, adj, newP);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vii adj[n];
		totalTax = 0;
		FOR(i, 0, n) 
		{
			cin >> t[i];
			totalTax += t[i];
		}
		int a, b, w;
		FOR(i, 0, n-1)
		{
			cin >> a >> b >> w;
			a--, b--;
			adj[a].emplace_back(mp(b, w));
			adj[b].emplace_back(mp(a, w));
			mm[{min(a, b), max(a, b)}] = i;
		}
		vb seen(n, false);
		DFS(0, seen, adj);
		seen.assign(n, false);
		pair<ll, ll> p = compute(0, seen, adj, 0LL);
		seen.assign(n, false);
		computeAll(0, seen, adj, p);
		FOR(i, 0, n)
		{
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}