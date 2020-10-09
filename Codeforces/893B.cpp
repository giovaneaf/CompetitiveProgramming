#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  bool b[100010];
  memset(b, false, sizeof(b));
  int k = 1;
  while(true)
  {
    int beautiful = round((pow(2.0,k)-1)*(pow(2.0, k-1)));
    if(beautiful > 100000)
      break;
    b[beautiful] = true;
    k++;
  }
  for(int i = n; i > 0; i--)
  {
    if(n%i == 0 && b[i])
    {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}