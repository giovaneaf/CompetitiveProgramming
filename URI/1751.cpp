#include <bits/stdc++.h>

using namespace std;

bool inPath[100005];
int n, f;

bool usedNodes(int node, vector<vector<pair<int, int>>>& adj) {
  for(int i = 0; i < adj[node].size(); ++i) {
    inPath[node] |= usedNodes(adj[node][i].first, adj);
  }
  return inPath[node];
}

int cost(int node, vector<vector<pair<int, int>>>& adj, bool acc) {
  if(!inPath[node]) return 0;
  int total = 0;
  for(int i = 0; i < adj[node].size(); ++i) {
    if(inPath[adj[node][i].first]) {
      if(acc) {
        total += cost(adj[node][i].first, adj, acc) + adj[node][i].second;
      } else {
        total = max(total, cost(adj[node][i].first, adj, acc) + adj[node][i].second);
      }
    }
  }
  return total;
}

int main()
{
  memset(inPath, false, sizeof(inPath));
  scanf("%d %d", &n, &f);
  vector<vector<pair<int, int>>> adj(n+5);
  for(int i = 0; i < n-1; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a--, b--;
    adj[a].push_back(make_pair(b, c));
  }
  for(int i = 0; i < f; ++i) {
    int a;
    scanf("%d", &a);
    inPath[--a] = true;
  }
  usedNodes(0, adj);
  printf("%d\n", cost(0, adj, true) - cost(0, adj, false));
}