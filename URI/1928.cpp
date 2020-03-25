#include <bits/stdc++.h>

using namespace std;

#define MAXN 50010

#define INF 1000000000

int n, r;

int P[MAXN][20];
int dist[MAXN];
int Pdist[MAXN][20];
int dad[MAXN];
int L[MAXN];

void DFS(int cur, int prev, vector<bool>& visited, vector<vector<int>>& adj, int level) {
  visited[cur] = true;
  dad[cur] = prev;
  L[cur] = level;
  for(int i = 0; i < adj[cur].size(); ++i) {
    int u = adj[cur][i];
    if(!visited[u]) {
      dist[u] = dist[cur]+1;
      DFS(u, cur, visited, adj, level+1);
    }
  }
}

void LCA() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; (1 << j) < n; ++j) {
      P[i][j] = -1;
    }
  }
  for(int i = 0; i < n; ++i) {
    P[i][0] = dad[i];
    Pdist[i][0] = 1;
  }
  for(int j = 1; (1 << j) < n; ++j) {
    for(int i = 0; i < n; ++i) {
      if(P[i][j-1] != -1) {
        P[i][j] = P[P[i][j-1]][j-1];
        Pdist[i][j] = Pdist[i][j-1] + Pdist[P[i][j-1]][j-1];
      } else {
        Pdist[i][j] = Pdist[i][j-1];
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

int getDist(int a,int b){
	if(L[a]<L[b]) swap(a, b);
	int ans=0;
	
	for(int i=16;i>=0;i--)
    	if(L[a]-L[b]>=(1<<i)){
    		ans += Pdist[a][i];
			a=P[a][i];
		}
	return ans;
}

int main() {
  scanf("%d", &n);
  int map[n];
  vector<bool> used;
  used.assign(n/2, false);
  for(int i = 0; i < n; ++i) {
    int cur;
    scanf("%d", &cur);
    cur--;
    if(used[cur]) {
      map[i] = cur+n/2;
    } else {
      used[cur] = true;
      map[i] = cur;
    }
  }
  vector<vector<int>> g(n+5);
  for(int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    g[map[u]].push_back(map[v]);
    g[map[v]].push_back(map[u]);
    //printf("%d %d = %d %d\n", u, v, map[u], map[v]);
  }
  vector<bool> visited(n);
  visited.assign(n, false);
  dist[0] = 0;
  DFS(0, -1, visited, g, 0);
  LCA();
  int ans = 0;
  for(int i = 0; i < n/2; ++i) {
      int pair = i+n/2;
      int lca = query(i, pair);
      if(lca == i or lca == pair) {
          if(lca == i) ans += getDist(pair, lca);
          else ans += getDist(i, lca);
      } else {
          ans += (getDist(pair, lca) + getDist(i, lca));
      }
  }
  printf("%d\n", ans);
  return 0;
}