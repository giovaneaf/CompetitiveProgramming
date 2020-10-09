#include <bits/stdc++.h>

using namespace std;

int memo[105][105][31][7]; // [100] [100] [26] [2]

int n, m;

int dp(int a, int b, int low, bool Max, vector<vector<pair<int, char>>>& v) {
  if(memo[a][b][low][Max] != -1) return memo[a][b][low][Max];
  if(Max) {
    int ans = 0;
    for(int i = 0; i < v[a].size(); ++i) {
      if(v[a][i].second - 'a' >= low) {
        ans = max(ans, dp(v[a][i].first, b, v[a][i].second - 'a', false, v));
      }
    }
    return memo[a][b][low][Max] = ans;
  } else {
    int ans = 1;
    for(int i = 0; i < v[b].size(); ++i) {
      if(v[b][i].second - 'a' >= low) {
        ans = min(ans, dp(a, v[b][i].first, v[b][i].second - 'a', true, v));
      }
    }
    return memo[a][b][low][Max] = ans;
  }
}

int main(){
    scanf("%d %d", &n, &m);
    vector<vector<pair<int, char>>> v(n);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        for(int k = 0; k < 26; ++k) {
          for(int l = 0; l < 2; ++l) {
            memo[i][j][k][l] = -1;
          }
        }
      }
    }
    for(int i = 0; i < m; ++i) {
      int a, b;
      char c;
      cin >> a >> b >> c;
      v[--a].push_back(make_pair(--b, c));
    }
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        printf("%c", dp(i, j, 0, true, v) == 1 ? 'A' : 'B');
      }
      putchar('\n');
    }
}
