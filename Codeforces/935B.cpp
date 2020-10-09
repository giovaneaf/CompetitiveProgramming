#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  while(scanf("%d", &n) != EOF)
  {
      string s;
      cin >> s;
      bool north = (s[0] == 'U');
      int y = (north ? 1 : 0);
      int x = (north ? 0 : 1);
      int cnt = 0;
      for(int i = 1; i < s.size(); ++i)
      {
        if(y == x)
        {
            if(north and s[i] == 'R')
            {
                north = false;
                cnt++;
            }
            if(!north and s[i] == 'U')
            {
                north = true;
                cnt++;
            }
        }
        if(s[i] == 'R') x++;
        else y++;
      }
      printf("%d\n", cnt);
  }
  return 0;
}