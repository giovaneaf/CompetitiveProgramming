#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, g;
  while(scanf("%d %d", &n, &g) != EOF) {
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      v[i] = a-b;
    }
    sort(v.begin(), v.end(), greater<int>());
    int score = 0;
    for(int i = 0; i < n; ++i) {
      if(v[i] > 0) {
        score += 3;
        continue;
      }
      if(g >= -v[i]+1){
        score += 3;
        g += (v[i]-1);
      }
      else if(g >= -v[i]) {
        score += 1;
        g += v[i];
      }
      else break;
    }
    printf("%d\n", score);
  }
}