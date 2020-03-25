#include <bits/stdc++.h>

using namespace std;

int c, p;
int memo[1005][1005];

bool B(int x, int y, vector<vector<int>>& adj) {
  if(x == 0) return 1;
  if(x == y) return 0;
  if(memo[x][y] != -1) return memo[x][y];
  int ans = 0;
  for(int i = 0; i < adj[y].size(); ++i) {
    if(B(min(adj[y][i], x), max(adj[y][i], x), adj)) {
      ans = 1;
      break;
    }
  }
  return memo[x][y] = ans;
}

int main() {
  while(scanf("%d %d", &c, &p) != EOF) {
    vector<vector<int>> adj(c);
    for(int i = 0; i < c+2; ++i) {
      for(int j = i+1; j < c+2; ++j) {
        memo[i][j] = -1;
      }
    }
    for(int i = 0; i < p; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--, b--;
      adj[b].push_back(a);
    }
    int ans = 0;
    for(int i = 0; i < c; ++i) {
      for(int j = i+1; j < c; ++j) {
        if(B(i, j, adj)) ans++;
      }
    }
    printf("%d\n", ans);
  }
}