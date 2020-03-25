#include <bits/stdc++.h>

using namespace std;

#define INF 99999999

int main()
{
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++)
  {
    int dp[1000001];
    int n, m;
    scanf("%d %d", &n, &m);
    dp[0] = 0;
    for(int i = 1; i <= m; i++)
      dp[i] = INF;
    for(int i = 0; i < n; i++)
    {
      int a;
      scanf("%d", &a);
      for(int j = 1; j <= m; j++)
      {
        if(a <= j)
          dp[j] = min(dp[j], 1 + dp[j-a]);
      }
    }
    printf("%d\n", dp[m]);
  }
  return 0;
}