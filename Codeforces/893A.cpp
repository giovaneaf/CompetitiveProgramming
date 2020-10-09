#include <bits/stdc++.h>

int main()
{
  int n;
  scanf("%d", &n);
  int p1 = 1;
  int p2 = 2;
  int spec = 3;
  bool invalid = false;
  for(int i = 0; i < n; i++)
  {
    int a;
    scanf("%d", &a);
    if(a == spec)
    {
      invalid = true;
      break;
    }
    if(a == p1)
    {
      int tmp = p2;
      p2 = spec;
      spec = tmp;
    }
    else
    {
      int tmp = p1;
      p1 = spec;
      spec = tmp;
    }
  }
  if(invalid)
    printf("NO");
  else
    printf("YES");
  putchar('\n');
  return 0;
}