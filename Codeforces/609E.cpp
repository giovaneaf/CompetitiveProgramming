#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define LOGMAXN 20
#define INF 1000000010

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

int n, m;
vector<bool> visited;

int P[MAXN][LOGMAXN];
int dad[MAXN];
ii parent[MAXN];
int L[MAXN];
int cost[MAXN];
int C[MAXN][LOGMAXN];

struct Edge {
  int a, b, c;
  Edge(int a, int b, int c) : a(a), b(b), c(c) {}
  bool operator< (const struct Edge& e) const {
    return c < e.c;
  }
};

vector<Edge> e;
vector<int> pset;

void initSet() {
  pset.assign(n, 0);
  for(int i = 0; i < n; ++i) pset[i] = i;
}

int findSet(int i) {
  return pset[i] == i ? i : (pset[i] = findSet(pset[i]));
}

bool isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}


void unionSet(int i, int j) {
  if(isSameSet(i, j)) return;
  pset[findSet(i)] = findSet(j);
}

ll Kruskal(vii* adj) {
  initSet();
  sort(e.begin(), e.end());
  ll sum = 0;
  for(int i = 0; i < e.size(); ++i) {
    if(not isSameSet(e[i].a, e[i].b)) {
      unionSet(e[i].a, e[i].b);
      sum += e[i].c;
      adj[e[i].a].push_back(make_pair(e[i].b, e[i].c));
      adj[e[i].b].push_back(make_pair(e[i].a, e[i].c));
    }
  }
  return sum;
}

int DFS(int cur, int parent, vii* adj)
{
	visited[cur] = true;
	dad[cur] = parent;
	for(int i = 0; i < adj[cur].size(); ++i)
	{
		int u = adj[cur][i].first;
		if(!visited[u])
		{
			L[u] = 1 + L[cur];
			cost[u] = adj[cur][i].second;
			DFS(u, cur, adj);
		}		
	}
}

void LCA()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < LOGMAXN; j++)
		{
			P[i][j] = -1;
			C[i][j] = -1;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		P[i][0] = dad[i];
		C[i][0] = cost[i];
	}
	for(int j = 1; j < LOGMAXN; ++j)
	{
		for(int i = 0; i < n; ++i)
		{
			if(P[i][j-1] != -1)
			{
				P[i][j] = P[P[i][j-1]][j-1];
				C[i][j] = max(C[P[i][j-1]][j-1], C[i][j-1]);
			}
		}
	}
}

int query(int a, int b)
{
	if(L[a] < L[b]) swap(a, b);
	
	for(int i = LOGMAXN-1; i >= 0; --i)
	{
		if(L[a] - (1 << i) >= L[b])
		{
			a = P[a][i];
		}
	}
	
	if(a == b) return a;
	
	for (int i = LOGMAXN-1; i >= 0; i--)
	{
		if (P[a][i] != P[b][i])
		{
			a = P[a][i];
			b = P[b][i];
		}
	}
	
	return dad[a];
}

int maximum(int a, int b)
{
	if(L[a] < L[b]) swap(a, b);
	
	int ans = 0;
	
	for(int i = LOGMAXN-1; i >= 0; --i)
	{
		if(L[a] - (1 << i) >= L[b])
		{
		    ans = max(ans, C[a][i]);
			a = P[a][i];
		}
	}
	
	return ans;
	
}

int main()
{
	scanf("%d %d", &n, &m);
	vii adj[n];
	vector<Edge> edge;
	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a, --b;
		e.push_back(Edge(a, b, c));
		edge.push_back(Edge(a, b, c));
	}
	ll mstCost = Kruskal(adj);
	visited.assign(n, false);
	L[0] = 0;
	cost[0] = 0;
	DFS(0, -1, adj);
	LCA();
	for(int i = 0; i < edge.size(); ++i)
	{
		int a = edge[i].a;
		int b = edge[i].b;
		int w = edge[i].c;
		int lca = query(a, b);
		printf("%lld\n", (long long) (mstCost + w) - max(maximum(a, lca), maximum(b, lca)));
	}
	return 0;
}