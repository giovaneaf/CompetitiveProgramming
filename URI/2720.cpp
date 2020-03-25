#include <bits/stdc++.h>

using namespace std;

struct p {
  int v, id;
  p(int v, int id) : v(v), id(id) {}
  bool operator>(const struct p& p) const {
    if(v == p.v) return id < p.id;
    return v > p.v;
  }
  bool operator<(const struct p& p) const {
    return id < p.id;
  }
};

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<struct p> v;
    for(int i = 0; i < n; ++i) {
      int id, a, b, c;
      scanf("%d %d %d %d", &id, &a, &b, &c);
      v.push_back(p(a*b*c, id));
    }
    sort(v.begin(), v.end(), greater<struct p>());
    sort(v.begin(), v.begin()+k);
    for(int i = 0; i < k; ++i) {
      printf("%d", v[i].id);
      if(i < k-1) putchar(' ');
    }
    putchar('\n');
  }
  return 0;
}