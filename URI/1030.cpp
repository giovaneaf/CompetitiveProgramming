#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++)
  {
    printf("Case %d: ", t);
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
      v[i] = i+1;
    }
    int dead = -1;
    for(int i = 0; i < n-1; i++)
    {
      dead = (dead + k >= v.size() ? (dead + k)%v.size() : dead+k);
      v.erase(v.begin()+dead);
      dead--;
    }
    printf("%d\n", v[0]);
  }
  return 0;
}