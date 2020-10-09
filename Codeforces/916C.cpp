#include <bits/stdc++.h>

using namespace std;

int getPrime(int n) {
  if(n <= 2) return 2;
  if(n%2 == 0) n++;
  for(int i = n; ; i += 2) {
    bool isPrime = true;
    for(int j = 3; j <= sqrt(i); j += 2) {
      if(i%j == 0) {
        isPrime = false;
        break;
      }
    }
    if(isPrime) return i;
  }
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int prime = getPrime(n-1);
  printf("%d %d\n", prime, prime);
  for(int i = 0; i < n-2; ++i) {
    printf("%d %d 1\n", i+1, i+2);
  }
  printf("%d %d %d\n", n-1, n, prime - (n-2));
  m -= (n-1);
  bool end = false;
  for(int i = 0; i < n && !end; ++i) {
    for(int j = i+2; j < n; ++j) {
      if(m-- == 0) {
        end = true;
        break;
      }
      printf("%d %d 100000000\n", i+1, j+1);
    }
  }
  return 0;
}
