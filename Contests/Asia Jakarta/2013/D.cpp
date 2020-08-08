#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(a, b, c) for(int a = b; a < c; ++a)

#define vi vector<int>
#define MAXN 100010

// this code is inside data structure folder
struct UnionFind
{
    vi pset;
    vi szset;   // size of the set
    UnionFind(int n) 
    {
        pset.assign(n, 0);
        szset.assign(n, 1);
        for(int i = 0; i < n; ++i) pset[i] = i;
    }
    int findSet(int i)
    {
        return (pset[i] == i ? i : (pset[i] = findSet(pset[i])));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)     // make set i point to j
    {
        if(isSameSet(i, j)) return;
        szset[findSet(j)] += szset[findSet(i)];
        pset[findSet(i)] = findSet(j);
    }
};

struct Edge
{
	int from, to;
	ll c;
	Edge(int from = 0, int to = 0, ll c = 0LL) : from(from), to(to), c(c) {}
	bool operator< (const Edge& e) { return c < e.c; }
};

vector<Edge> edges;

ll Kruskal(int n)
{
	sort(edges.begin(), edges.end());
	UnionFind uf(n);
	ll cost = 0LL;
	for(Edge& e : edges)
	{
		if(!uf.isSameSet(e.from, e.to))
		{
			uf.unionSet(e.from, e.to);
			cost += e.c;
		}
	}
	return cost;
}

int n, m, k, T;
int a, b, c;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		cin >> n >> m >> k;
		// Add fake node labeled 0 to connect all power plants with cost 0
		FOR(i, 0, k)
		{
			cin >> a;
			edges.emplace_back(0, a, 0LL);
		}
		FOR(i, 0, m)
		{
			cin >> a >> b >> c;
			edges.emplace_back(a, b, (ll) c);
		}
		printf("Case #%d: %lld\n", t+1, Kruskal(n+1));
		edges.clear();
	}
}