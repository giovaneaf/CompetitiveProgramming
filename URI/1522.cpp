#include <bits/stdc++.h>

using namespace std;

int memo[105][105][105];
int A[105];
int B[105];
int C[105];

int n;

bool dp(int a, int b, int c) {
  if(a == n && b == n && c == n) return 1;
  if(a < n and b < n and c < n and memo[a][b][c] != -1) return memo[a][b][c];
  bool ans = 0;
  if(a < n and A[a]%3 == 0) ans |= dp(a+1, b, c);
  if(b < n and B[b]%3 == 0) ans |= dp(a, b+1, c);
  if(c < n and C[c]%3 == 0) ans |= dp(a, b, c+1);
  if(a < n and b < n and (A[a]+B[b])%3 == 0) ans |= dp(a+1, b+1, c);
  if(a < n and c < n and (A[a]+C[c])%3 == 0) ans |= dp(a+1, b, c+1);
  if(b < n and c < n and (B[b]+C[c])%3 == 0) ans |= dp(a, b+1, c+1);
  if(a < n and b < n and c < n and (A[a]+B[b]+C[c])%3 == 0) ans |= dp(a+1, b+1, c+1);
  return memo[a][b][c] = ans;
}

int main() {
  while(scanf("%d", &n) != EOF & n > 0) {
    for(int i = 0; i < n; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      A[i] = a;
      B[i] = b;
      C[i] = c;
    }
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        for(int k = 0; k < n; ++k)
          memo[i][j][k] = -1;
    if(dp(0, 0, 0)) printf("1"); 
    else printf("0");
    putchar('\n');
  }
}