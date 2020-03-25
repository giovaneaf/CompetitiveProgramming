#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while(cin >> N && N > 0)
    {
      int perm[N+5];
      int inv[N+5];
      for(int i = 1; i <= N; i++)
      {
        cin >> perm[i];
        inv[perm[i]] = i;
      }
      bool ambig = true;
      for(int i = 1; i <= N; i++)
      {
        if(perm[i] != inv[i])
        {
          ambig = false;
          break;
        }
      }
      if(ambig)
        cout << "ambiguous";
      else
        cout << "not ambiguous";
      cout << endl;
    }
    return 0;
}
