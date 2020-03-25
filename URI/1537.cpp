#include <bits/stdc++.h>

typedef unsigned long long int ull;

#define mod 1000000009

using namespace std;

int C[100005][4];

int nCr(int n, int k) {
  if(n == k) return C[n][k] = 1;
  if(k == 0) return C[n][k] = 1;
  if(k == 1) return C[n][k] = n;
  if(C[n][k] != -1) return C[n][k];
  return C[n][k] = (int) ((ull) nCr(n-1, k) + nCr(n-1,k-1))%mod;
}

int main()
{
  memset(C, -1, sizeof(C));
  int n;
  while(scanf("%d", &n) != EOF & n > 0) {
    int ans = nCr(n, 3);
    for(int i = 2; i <= n-3; ++i) {
      ans = (ans*(ull) i)%mod; 
    }
    printf("%d\n", ans);
  }
}