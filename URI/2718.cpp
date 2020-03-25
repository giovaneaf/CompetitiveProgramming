#include <bits/stdc++.h>

using namespace std;

int main() {
  long long int n;
  scanf("%lld", &n);
  for(int j = 0; j < n; ++j) {
    long long int size;
    scanf("%lld", &size);
    long long int maximum = 0;
    long long int sequence = 0;
    for(long long int i = 0; i <= ceil(log2(size)); ++i) {
      if(size & ((long long int) 1 << i)) sequence++;
      else sequence = 0;
      maximum = max(maximum, sequence);
    }
    printf("%lld\n", maximum);
  }
}