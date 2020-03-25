#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, c, k;
  while(scanf("%d %d %d", &n, &c, &k) != EOF) {
    if(n == 0 and c == 0 and k == 0) break;
    vector<int> acc;
    vector<pair<int, int>> v(k);
    acc.assign(k, 0);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < c; ++j) {
        int a;
        scanf("%d", &a);
        acc[--a]++;
      }
    }
    for(int i = 0; i < k; ++i) {
      v[i] = make_pair(acc[i], i);
    }
    sort(v.begin(), v.end());
    printf("%d", v[0].second+1);
    for(int i = 1; i < k; ++i) {
      if(v[i].first == v[i-1].first)
        printf(" %d", v[i].second+1);
      else
        break;
    }
    putchar('\n');
  }
}