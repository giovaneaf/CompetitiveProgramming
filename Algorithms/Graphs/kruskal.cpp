/*

Find minimum spanning tree of a weighted undirected graph in O(E*log(E)) where:
E is the number of edges in the graph
Tested in problem MST from SPOJ

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(a, b, c) for(int a = b; a < c; ++a)

#define vi vector<int>
#define MAXN 100010

// this code is kruskal inside graphs folder
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

int n, m;
int a, b, c;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		FOR(i, 0, m)
		{
			cin >> a >> b >> c;
			a--, b--;
			edges.emplace_back(a, b, (ll) c);
		}
		printf("%lld\n", Kruskal(n));
		edges.clear();
	}
}
