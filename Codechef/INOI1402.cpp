#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int g[250][250];

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(i == j) g[i][j] = 0;
      else g[i][j] = INF;
    }
  }
  for(int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a][b] = g[b][a] = c;
  }
  for(int k = 0; k < n; ++k) {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
      }
    }
  }
  int ans = -1;
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      if(g[i][j] < INF)
        ans = max(ans, g[i][j]);
    }
  }
  printf("%d\n", ans);
}