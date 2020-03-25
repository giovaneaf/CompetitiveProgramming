#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  char M[1000][1000];
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      scanf(" %c", &M[i][j]);
  bool visited[N];
  for(int i = 0; i < N; i++)
    visited[i] = false;
  bool solvable = true;
  vector<int> v;
  for(int i = 0; i < N && solvable; i++)
  {
    if(!visited[i])
    {
      int num = 1;
      for(int j = 0; j < N; j++)
      {
        if(i != j && M[i][j] == 'S')
        {
          num++;
          visited[j] = true;
          for(int k = 0; k < N; k++)
          {
            if(M[i][k] != M[j][k])
            {
              solvable = false;
              break;
            }
          }
        }
      }
      if(solvable)
        v.push_back(num);
    }
  }
  if(!solvable)
    printf("-1\n");
  else
  {
    sort(v.begin(), v.end(), greater<int>());
    int size = v.size();
    printf("%d\n", size);
    for(int i = 0; i < v.size(); i++)
    {
      printf("%d", v[i]);
      if(i < v.size()-1)
        putchar(' ');
    }
    putchar('\n');
  }
  return 0;
}
