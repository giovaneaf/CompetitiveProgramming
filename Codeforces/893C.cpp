#include <bits/stdc++.h>

using namespace std;
#define MAX 100000

int n, m;
unsigned long long int cost[MAX+10];
vector<vector<int>> g(MAX+10);
int visited[MAX+10];

unsigned long long int DFS(int i)
{
  if(!visited[i])
  {
    visited[i] = true;
    unsigned long long int ans = cost[i];
    for(int j = 0; j < g[i].size(); j++)
    {
      ans = min(ans, DFS(g[i][j]));
    }
    return ans;
  }
  else
    return 1000000000;
}

int main()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%llu", &cost[i]);
  }
  for(int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i = 0; i < n; i++)
    visited[i] = false;
  unsigned long long int ans = 0;
  for(int i = 0; i < n; i++)
  {
    if(!visited[i])
    {
      ans += DFS(i);
    }
  }
  printf("%llu\n", ans);
  return 0;
}