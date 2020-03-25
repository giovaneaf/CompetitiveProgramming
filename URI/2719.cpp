#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int carry = m;
    int trips = 1;
    for(int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      if(carry < a) {
        trips++;
        carry = m - a;
      } else {
        carry -= a;
      }
    }
    printf("%d\n", trips);
  }
}