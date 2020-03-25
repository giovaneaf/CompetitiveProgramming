#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int BFS(int O, int D, bool* used)
{
  queue<int> q;
  int dist[100001];
  memset(dist, -1, sizeof(dist));
  dist[O] = 0;
  q.push(O);
  while(q.size())
  {
    int u = q.front();
    q.pop();
    if(u == D)
      return dist[u];
    if(u > 1 && !used[u-1] && dist[u-1] == -1)
    {
      q.push(u-1);
      dist[u-1] = dist[u] + 1;
    }
    if(u < 100000 && !used[u+1] && dist[u+1] == -1)
    {
      q.push(u+1);
      dist[u+1] = dist[u] + 1;
    }
    if(2*u <= 100000 && !used[2*u] && dist[2*u] == -1)
    {
      q.push(2*u);
      dist[2*u] = dist[u] + 1;
    }
    if(3*u <= 100000 && !used[3*u] && dist[3*u] == -1)
    {
      q.push(3*u);
      dist[3*u] = dist[u] + 1;
    }
    if(u%2 == 0 && !used[u/2] && dist[u/2] == -1)
    {
      q.push(u/2);
      dist[u/2] = dist[u] + 1;
    }
  }
  return -1;
}

int main()
{
  int O, D, K;
  while(cin >> O >> D >> K && O)
  {
    bool used[100001];
    memset(used, false, sizeof(used));
    for(int i = 0; i < K; i++)
    {
      int val;
      cin >> val;
      used[val] = true;
    }
    int ans = BFS(O, D, used);
    cout << ans << endl;
  }
  return 0;
}
