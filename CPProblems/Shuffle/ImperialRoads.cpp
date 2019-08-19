/*
https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=6218
Compute the minimum spanning tree then for each query (u, v) remove the highest cost edge between u and v path
to add the given edge. You can only remove the edges between (u, v) path because any other edge will disconnect the
graph. You can compute the highest cost edge between u and v path with LCA with binary lifting in O(log(n)).
*/

#include <bits/stdc++.h>

using namespace std;

int n, r;

int P[100009][20];
int Max[100009];
int Maximum[100009][20];
int M[100009];
int dad[100009];
int L[100009];

typedef struct Edge Edge;

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

int Kruskal(vector<vector<pair<int, int>>>& adj) {
  int size = n;
  initSet();
  int sum = 0;
  for(int i = 0; i < e.size(); ++i) {
    if(not isSameSet(e[i].a, e[i].b)) {
      unionSet(e[i].a, e[i].b);
      sum += e[i].c;
      adj[e[i].a].push_back(make_pair(e[i].b, e[i].c));
      adj[e[i].b].push_back(make_pair(e[i].a, e[i].c));
      if(--size == 1) break;
    }
  }
  return sum;
}

void DFS(int cur, int prev, vector<bool>& visited, vector<vector<pair<int, int>>>& adj, int level) {
  visited[cur] = true;
  dad[cur] = prev;
  L[cur] = level;
  for(int i = 0; i < adj[cur].size(); ++i) {
    int u = adj[cur][i].first;
    if(!visited[u]) {
      M[u] = adj[cur][i].second;
      Max[u] = max(Max[cur], adj[cur][i].second);
      DFS(u, cur, visited, adj, level+1);
    }
  }
}

void LCA() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; (1 << j) < n; ++j) {
      P[i][j] = -1;
      Maximum[i][j] = 0;
    }
  }
  for(int i = 0; i < n; ++i) {
    P[i][0] = dad[i];
    Maximum[i][0] = M[i];
  }
  for(int j = 1; (1 << j) < n; ++j) {
    for(int i = 0; i < n; ++i) {
      if(P[i][j-1] != -1) {
        P[i][j] = P[P[i][j-1]][j-1];
        Maximum[i][j] = max(Maximum[i][j-1], Maximum[P[i][j-1]][j-1]);
      } else {
        Maximum[i][j] = Maximum[i][j-1];
      }
    }
  }
}

int query(int a, int b) {
  if(L[a]<L[b]) swap(a,b);
    
  for(int i=18;i>=0;i--)
    if(L[a]-(1<<i)>=L[b] )
        a=P[a][i];    
    
  if(a==b) return b;
    
  for(int i=16;i>=0;i--)
    if(P[a][i]!= P[b][i]){
        a=P[a][i];
        b=P[b][i];    
    }
    
  return dad[a];
}

int maximum(int a,int b){
	if(L[a]<L[b]) swap(a, b);
	int ans=0;
	
	for(int i=16;i>=0;i--)
    	if(L[a]-L[b]>=(1<<i)){
    		ans=max(ans, Maximum[a][i]);
			a=P[a][i];
		}
	return ans;
}

int main() {
  while(scanf("%d %d", &n, &r) != EOF) {
    vector<vector<pair<int, int>>> adj(n+5);
    vector<bool> visited;
    map<pair<int, int>, int> m;
    visited.assign(n, false);
    for(int i = 0; i < r; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      a--, b--;
      m[make_pair(a, b)] = c;
      e.push_back(Edge(a, b, c));
    }
    sort(e.begin(), e.end());
    int mst = Kruskal(adj);
    for(int i = 0; i < n+5; ++i) {
      M[i] = 0;
      Max[i] = 0;
      dad[i] = -1;
    }
    DFS(0, -1, visited, adj, 0);
    LCA();
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--, b--;
      if(a == 0) printf("%d\n", mst + m[make_pair(min(a,b), max(a,b))] - Max[b]);
      else if(b == 0) printf("%d\n", mst + m[make_pair(min(a,b), max(a,b))] - Max[a]);
      else {
        int lca = query(a, b);
        if(lca == 0) printf("%d\n", mst + m[make_pair(min(a,b), max(a,b))] - max(Max[a], Max[b]));
        else printf("%d\n", mst + m[make_pair(min(a,b), max(a,b))] - max(maximum(a, lca), maximum(b, lca)));
      }
    }
    e.clear();
    adj.clear();
  }
  return 0;
}