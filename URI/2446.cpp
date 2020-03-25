#include <bits/stdc++.h>

using namespace std;

bool memo[100005];
bool ant[100005];

int main() {
  int v, m;
  scanf("%d %d", &v, &m);
  int A[m+5];
  for(int i = 0; i < m; ++i) {
    scanf("%d", &A[i]);
  }
  for(int i = 0; i <= v; ++i) {
      ant[i] = false;
      memo[i] = false;
  }
  ant[0] = memo[0] = true;
  for(int i = 0; i < m; ++i) {
    for(int j = 1; j <= v; ++j) {
      if(A[i] <= j) {
        memo[j] |= ant[j-A[i]];
      }
    }
    for(int j = 1; j <= v; ++j) {
      ant[j] = memo[j];
    }
  }
  printf("%c\n", memo[v] ? 'S' : 'N');
  return 0;
}