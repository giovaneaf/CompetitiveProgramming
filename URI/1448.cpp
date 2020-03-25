#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  getchar();
  for(int j = 1; j <= N; j++)
  {
    char a[110];
    char b[110];
    char c[110];
    gets(a);
    gets(b);
    gets(c);
    int t1, t2;
    int firstdiff = -1;
    t1 = t2 = 0;
    for(int i = 0; i < strlen(a); i++)
    {
      if(a[i] == b[i])
        t1++;
      else if(firstdiff == -1 and a[i] == c[i])
        firstdiff = 1;
      if(a[i] == c[i])
        t2++;
      else if(firstdiff == -1 and a[i] == b[i])
        firstdiff = 2;
    }
    printf("Instancia %d\n", j);
    if(t1 > t2)
      cout << "time 1";
    else if(t1 < t2)
      cout << "time 2";
    else if((t1 == t2) and (firstdiff == 1))
      cout << "time 2";
    else if((t1 == t2) and (firstdiff == 2))
      cout << "time 1";
    else
      cout << "empate";
    cout << endl << endl;
  }
  return 0;
}