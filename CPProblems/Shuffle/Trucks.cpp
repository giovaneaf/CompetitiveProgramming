/*
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4384
Maximal spanning tree + LCA with binary lifting. You need to get the minimum value between the a and b path.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, s;

int P[20009][20];
int Min[20009];
int Minimum[20009][20];
int M[20009];
int dad[20009];
int L[20009];

#define INF 100000005

typedef struct Edge Edge;

struct Edge {
  int a, b, c;
  Edge(int a, int b, int c) : a(a), b(b), c(c) {}
  bool operator> (const struct Edge& e) const {
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

void Kruskal(vector<vector<pair<int, int>>>& adj) {
  int size = n;
  initSet();
  for(int i = 0; i < e.size(); ++i) {
    if(not isSameSet(e[i].a, e[i].b)) {
      unionSet(e[i].a, e[i].b);
      adj[e[i].a].push_back(make_pair(e[i].b, e[i].c));
      adj[e[i].b].push_back(make_pair(e[i].a, e[i].c));
      if(--size == 1) break;
    }
  }
}

void DFS(int cur, int prev, vector<bool>& visited, vector<vector<pair<int, int>>>& adj, int level) {
  visited[cur] = true;
  dad[cur] = prev;
  L[cur] = level;
  for(int i = 0; i < adj[cur].size(); ++i) {
    int u = adj[cur][i].first;
    if(!visited[u]) {
      M[u] = adj[cur][i].second;
      Min[u] = min(Min[cur], adj[cur][i].second);
      DFS(u, cur, visited, adj, level+1);
    }
  }
}

void LCA() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; (1 << j) < n; ++j) {
      P[i][j] = -1;
      Minimum[i][j] = INF;
    }
  }
  for(int i = 0; i < n; ++i) {
    P[i][0] = dad[i];
    Minimum[i][0] = M[i];
  }
  for(int j = 1; (1 << j) < n; ++j) {
    for(int i = 0; i < n; ++i) {
      if(P[i][j-1] != -1) {
        P[i][j] = P[P[i][j-1]][j-1];
        Minimum[i][j] = min(Minimum[i][j-1], Minimum[P[i][j-1]][j-1]);
      } else {
        Minimum[i][j] = Minimum[i][j-1];
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

int minimum(int a,int b){  //L[b]<=L[a]
	if(L[a]<L[b]) swap(a, b);
	int ans=INF;
	
	for(int i=16;i>=0;i--)
    	if(L[a]-L[b]>=(1<<i)){
    		ans=min(ans,Minimum[a][i]);
			a=P[a][i];
		}
	return ans;
}

int main() {
  while(scanf("%d %d %d", &n, &m, &s) != EOF) {
    vector<vector<pair<int, int>>> adj(n+5);
    vector<bool> visited;
    visited.assign(n, false);
    for(int i = 0; i < m; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      a--, b--;
      e.push_back(Edge(a, b, c));
    }
    sort(e.begin(), e.end(), greater<Edge>());
    Kruskal(adj);
    for(int i = 0; i < n+5; ++i) {
      M[i] = INF;
      Min[i] = INF;
      dad[i] = -1;
    }
    DFS(0, -1, visited, adj, 0);
    LCA();
    for(int i = 0; i < s; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--, b--;
      if(a == 0) printf("%d\n", Min[b]);
      else if(b == 0) printf("%d\n", Min[a]);
      else {
        int lca = query(a, b);
        if(lca == 0) printf("%d\n", min(Min[a], Min[b]));
        else printf("%d\n", min(minimum(a, lca), minimum(b, lca)));
      }
    }
    e.clear();
    adj.clear();
  }
  return 0;
}