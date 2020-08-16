#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 10010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

vi pset;

struct UnionFind
{
	void init(int n) 
	{
		pset.assign(n, 0);
		FOR(i, 0, n) pset[i] = i;
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
		pset[findSet(i)] = findSet(j);
	}
};

int n, m, q, t;
vi adj[MAXN];
bool seen[MAXN];
UnionFind uf;
vi tin, low;

void dfs(int v, int p = -1) 
{
    seen[v] = true;
    tin[v] = low[v] = t++;
    for (int to : adj[v]) 
	{
        if (to == p) continue;
        if (seen[to]) 
		{
            low[v] = min(low[v], tin[to]);
        } 
		else 
		{
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                uf.unionSet(v, to); // bridge
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> q)
	{
		if(n == 0 && m == 0 && q == 0) break;
		FOR(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		memset(seen, false, sizeof(seen));
		tin.resize(n); low.resize(n);
		uf.init(n);
		t = 0;
		FOR(i, 0, n)
		{
			if(!seen[i])
				dfs(i);
		}
		FOR(i, 0, q)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			printf("%c\n", uf.isSameSet(a, b) ? 'Y' : 'N');
		}
		printf("-\n");
		FOR(i, 0, n) adj[i].clear();
	}
    return 0;
}