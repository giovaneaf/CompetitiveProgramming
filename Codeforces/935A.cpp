#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  while(scanf("%d", &n) != EOF)
  {
      int cnt = 1;
      for(int i = 2; i < n; ++i)
      {
        if((n-i)%i == 0) cnt++;
      }
      printf("%d\n", cnt);
  }
  return 0;
}