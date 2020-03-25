#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

typedef unsigned long long int ull;

int main()
{
  string s;
  while(cin >> s) {
    int ans = 0;
    int pot = 1;
    for(int i = s.size()-1; i >= 0; --i) {
      ans = ((ull) ans + (((ull) (s[i]-'A'))*pot))%mod;
      pot = (((ull) pot) * 26) % mod;
    }
    printf("%d\n", ans);
  }
}