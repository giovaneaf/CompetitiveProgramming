#include <bits/stdc++.h>

using namespace std;

int M[105][105];

#define INF 1000000000

int main()
{
  int n, m;
  int t = 1;
  while(scanf("%d %d", &n, &m) != EOF) {
    if(n == 0 and m == 0) break;
    printf("Instancia %d\n", t);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i == j) {
          M[i][j] = 0;
        } else {
          M[i][j] = INF;
        }
      }
    }
    for(int i = 0; i < m; ++i) {
      int a, b, h;
      scanf("%d %d %d", &a, &b, &h);
      a--, b--;
      M[a][b] = M[b][a] = h;
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          M[i][j] = min(M[i][j], max(M[i][k], M[k][j]));
        }
      }
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--, b--;
      printf("%d\n", a == b ? 0 : M[a][b]);
    }
    t++;
    putchar('\n');
  }
  return 0;
}