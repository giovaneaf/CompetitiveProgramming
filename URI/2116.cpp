#include <bits/stdc++.h>

using namespace std;

bool prime[1005];

void Sieve(int n) {
  for(int i = 2; i < n; ++i) {
    prime[i] = true;
  }
  prime[0] = prime[1] = false;
  for(int i = 2; i*i <= n; ++i) {
    if(prime[i]) {
      for(int j = i*2; j < n; j += i) {
        prime[j] = false;
      }
    }
  }
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int pn, pm;
  Sieve(max(n, m) + 1);
  for(int i = n; i >= 2; --i) {
    if(prime[i]) {
      pn = i;
      break;
    }
  }
  for(int i = m; i >= 2; --i) {
    if(prime[i]) {
      pm = i;
      break;
    }
  }
  printf("%d\n", pm*pn);
}