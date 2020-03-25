#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  getchar();
  while(N--)
  {
    char s[1005];
    gets(s);
    int n = strlen(s);
    int half = (n-1)/2;
    for(int i = 0; i < n; i++)
    {
      if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        s[i] += 3;
      if(i <= half)
        s[i] -= 1;
    }
    for(int i = n-1; i >= 0; i--)
      printf("%c", s[i]);
    putchar('\n');
  }
  return 0;
}