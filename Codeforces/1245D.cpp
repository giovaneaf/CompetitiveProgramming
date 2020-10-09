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
#define MAXN 2010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

struct point 
{
	ll x, y;
};

struct Edge
{
	int from, to;
	ll cost;
	Edge(int from = 0, int to = 0, ll cost = 0LL) : from(from), to(to), cost(cost) {}
	bool operator< (const Edge& e) const
	{
		return cost < e.cost;
	}
};

int n, sz;
point p[MAXN];
ll c[MAXN];
ll k[MAXN];
Edge e[MAXN*MAXN];

struct UnionFind
{
	vi pset;
	vi szset; // size of the set
	vi minCost;
	UnionFind(int n) 
	{
		pset.resize(n);
		szset.assign(n, 1);
		minCost.resize(n);
		FOR(i, 0, n) 
		{
			pset[i] = i;
			minCost[i] = i;
		}
	}
	int findSet(int i)
	{
		return (pset[i] == i ? i : (pset[i] = findSet(pset[i])));
	}
	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j)
	{
		if(isSameSet(i, j)) return;
		int x, y;
		x = findSet(j); y = findSet(i);
		szset[x] += szset[y];
		minCost[x] = (c[minCost[x]] > c[minCost[y]] ? minCost[y] : minCost[x]);
		pset[y] = x;
	}
};

void Kruskal()
{
	ll cost = 0LL;
	UnionFind uf(n);
	vector<Edge> eAns;
	vi station;
	FOR(i, 0, sz)
	{
		if(!uf.isSameSet(e[i].from, e[i].to) && e[i].cost < max(c[uf.minCost[uf.findSet(e[i].from)]], c[uf.minCost[uf.findSet(e[i].to)]]))
		{
			uf.unionSet(e[i].from, e[i].to);
			cost += e[i].cost;
			eAns.emplace_back(e[i].from+1, e[i].to+1);
		}
	}
	vb seen(n, false);
	FOR(i, 0, n)
	{
		int curSet = uf.findSet(i);
		if(!seen[curSet])
		{
			seen[curSet] = true;
			cost += c[uf.minCost[curSet]];
			station.emplace_back(uf.minCost[curSet]+1);
		}
	}
	printf("%lld\n", cost);
	printf("%d\n", (int) station.size());
	FOR(i, 0,(int) station.size())
	{
		if(i > 0) putchar(' ');
		printf("%d", station[i]);
	}
	if((int) station.size() > 0)
		putchar('\n');
	printf("%d\n", (int) eAns.size());
	FOR(i, 0,(int) eAns.size())
	{
		printf("%d %d\n", eAns[i].from, eAns[i].to);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n)
		{
			cin >> p[i].x >> p[i].y;
		}
		FOR(i, 0, n)
		{
			cin >> c[i];
		}
		FOR(i, 0, n)
		{
			cin >> k[i];
		}
		sz = 0;
		FOR(i, 0, n)
		{
			FOR(j, i+1, n)
			{
				e[sz++] = Edge(i, j, (abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y))*(k[i]+k[j]));
			}
		}
		sort(e, e+sz);
		Kruskal();
	}
	return 0;
}

