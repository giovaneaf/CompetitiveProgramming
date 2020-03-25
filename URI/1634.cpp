#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  while(cin >> n >> m) {
    if(n == 0 and m == 0) break;
    int num;
    int tot = 0;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
      for(int i = 0; i < m-1; ++i)
        scanf("%d", &num);
      scanf("%d", &num);
      tot += num;
      v[i] = num;
    }
    for(int i = 0; i < n; ++i) {
      int gcd = __gcd(v[i], tot);
      printf("%d / %d\n", v[i]/gcd, tot/gcd);
    }
  }
  return 0;
}