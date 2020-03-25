#include <bits/stdc++.h>

using namespace std;

#define INF 10e8
#define EPS 10e-9

bool eq(double a, double b) {
  return fabs(a-b) < EPS;
}

double memo[100005][105];

bool visited[100005][105];

int P[105];

int m, n;

double dp(int pos, int lpos, vector<pair<int, double>>& v) {
  if(lpos == m) return 0;
  if(pos == n) return INF;
  if(visited[pos][lpos]) return memo[pos][lpos];
  visited[pos][lpos] = true;
  if(v[pos].first == P[lpos]) {
    return memo[pos][lpos] = min(dp(pos+1, lpos+1, v) + v[pos].second, dp(pos+1, lpos, v));
  } else {
    return memo[pos][lpos] = dp(pos+1, lpos, v);
  }
}

int main()
{
  while(scanf("%d %d", &m, &n) != EOF) {
    if(n == 0 and m == 0) break;
    for(int i = 0; i < n+3; ++i) {
      for(int j = 0; j < m+3; ++j) {
        memo[i][j] = INF;
        visited[i][j] = false;
      }
    }
    for(int i = 0; i < m; ++i) {
      scanf("%d", P+i);
    }
    vector<pair<int, double>> v(n);
    for(int i = 0; i < n; ++i) {
      int a;
      double c;
      cin >> a >> c;
      v[i] = make_pair(a, c);
    }
    dp(0, 0, v);
    if(eq(memo[0][0], INF)) printf("Impossible\n");
    else printf("%.2f\n", memo[0][0]);
  }
}