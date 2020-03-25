#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t = 1;
  int n, q;
  while(scanf("%d %d", &n, &q) != EOF)
  {
    if(n == 0 && q == 0)
      break;
    printf("CASE# %d:\n", t);
    vector<int> v(n);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    map<int, int> m;
    for(int i = 0; i < n; i++)
    {
      if(m.find(v[i]) == m.end())
        m[v[i]] = i+1;
    }
    for(int i = 0; i < q; i++)
    {
      int val;
      scanf("%d", &val);
      if(m.find(val) != m.end())
        printf("%d found at %d", val, m[val]);
      else
        printf("%d not found", val);
      putchar('\n');
    }
    t++;
  }
  return 0;
}