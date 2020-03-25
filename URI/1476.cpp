#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 20010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
#define comp(a, b) ((a)+(b))

int n, m, s;

struct Edge {
  int a, b, c;
  Edge(int a, int b, int c) : a(a), b(b), c(c) {}
  bool operator< (const struct Edge& e) const {
    return c > e.c;
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

void Kruskal(vii* adj) {
  int size = n;
  initSet();
  for(int i = 0; i < e.size(); ++i) {
    if(not isSameSet(e[i].a, e[i].b)) {
      unionSet(e[i].a, e[i].b);
      adj[e[i].a].emplace_back(make_pair(e[i].b, e[i].c));
      adj[e[i].b].emplace_back(make_pair(e[i].a, e[i].c));
      if(--size == 1) break;
    }
  }
}

int dad[MAXN];
int c[MAXN];
int L[MAXN];
int P[MAXN][LOGMAXN];
int cost[MAXN][LOGMAXN];

void DFS(int cur, vii* adj, vb& seen)
{
	seen[cur] = true;
	for(ii p : adj[cur])
	{
		int u = p.fst;
		if(seen[u]) continue;
		int w = p.snd;
		L[u] = L[cur] + 1;
		c[u] = w;
		dad[u] = cur;
		DFS(u, adj, seen);
	}
}

void init()
{
	FOR(i, 0, n)
	{
		P[i][0] = dad[i];
		cost[i][0] = c[i];
	}
	FOR(j, 1, LOGMAXN)
	{
		FOR(i, 0, n)
		{
			if(P[i][j-1] == -1)
			{
				P[i][j] = -1;
				cost[i][j] = 1e9;
			}
			else
			{
				P[i][j] = P[P[i][j-1]][j-1];
				cost[i][j] = min(cost[i][j-1], cost[P[i][j-1]][j-1]);
			}
		}
	}
	/*FOR(j, 0, LOGMAXN)
	{
		FOR(i, 0, n)
		{
			printf("%d ", cost[i][j]);
		}
		puts("");
	}*/
}

int query(int a, int b)
{
	if(L[a] < L[b]) swap(a, b);
	int ans = 1e9;
	RFOR(i, LOGMAXN-1, 0)
	{
		if(L[a] - (1 << i) >= L[b])
		{
			ans = min(ans, cost[a][i]);
			a = P[a][i];
		}
	}
	if(a == b) return ans;
	RFOR(i, LOGMAXN-1, 0)
	{
		if(P[a][i] != P[b][i])
		{
			ans = min(ans, min(cost[a][i], cost[b][i]));
			a = P[a][i];
			b = P[b][i];
		}
	}
	return min(ans, min(c[a], c[b]));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> s)
	{
		vii adj[n];
		FOR(i, 0, m)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			e.emplace_back(Edge(a, b, c));
		}
		sort(e.begin(), e.end());
		Kruskal(adj);
		vb seen(n, false);
		dad[0] = -1;
		c[0] = 1e9;
		L[0] = 0;
		DFS(0, adj, seen);
		init();
		FOR(i, 0, s)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			printf("%d\n", query(a, b));
		}
		e.clear();
	}
	return 0;
} 