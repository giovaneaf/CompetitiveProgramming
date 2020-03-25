#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

typedef long long int ll;

int N, C;
int ouro[10010];
bool visited[10010];
vector<pair<int, int> > v[10010];

ll B(int idx)
{
  ll ans = 0;
  visited[idx] = true;
  for(int i = 0; i < v[idx].size(); i++)
  {
    int u = v[idx][i].first;
    int w = v[idx][i].second;
    if(!visited[u])
    {
      ans += B(u) + 2*w*ceil((double) ouro[u]/C);
      ouro[idx] += ouro[u];
    }
  }
  return ans;
}

int main()
{
  scanf("%d %d", &N, &C);
  for(int i = 1; i <= N; i++)
    scanf("%d", &ouro[i]);
  for(int i = 0; i < N-1; i++)
  {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    v[a].push_back(make_pair(b, w));
    v[b].push_back(make_pair(a, w));
  }
  for(int i = 1; i <= N; i++)
    visited[i] = false;
  printf("%lld\n", B(1));
  return 0;
}
