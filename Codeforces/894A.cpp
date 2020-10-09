#include <bits/stdc++.h>

int main()
{
  char s[110];
  scanf("%s", s);
  int len = strlen(s);
  int count = 0;
  for(int i = 0; i < len-2; i++)
  {
    if(s[i] != 'Q')
      continue;
    for(int j = i+1; j < len-1; j++)
    {
      if(s[j] != 'A')
        continue;
      for(int k = j+1; k < len; k++)
      {
        if(s[k] != 'Q')
          continue;
        count++;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}