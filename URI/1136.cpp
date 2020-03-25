#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, B;
    while(cin >> N >> B)
    {
      if(N == 0 && B == 0)
        break;
      bool v[N+1];
      v[0] = true;
      for(int i = 1; i <= N; i++)
        v[i] = false;
      int numbers[B];
      for(int i = 0; i < B; i++)
      {
        cin >> numbers[i];
      }
      for(int i = 0; i < B-1; i++)
        for(int j = i+1; j < B; j++)
          v[abs(numbers[i]-numbers[j])] = true;
      bool can = true;
      for(int i = 0; i <= N; i++)
        if(!v[i])
        {
          can = false;
          break;
        }
      cout << (can? "Y" : "N") << endl;
    }
    return 0;
}
