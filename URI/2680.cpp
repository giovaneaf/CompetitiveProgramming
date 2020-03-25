#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
      int N;
      cin >> N;
      int sum = 0;
      for(int i = 1; i*i <= N; i++)
      {
        if(N%i == 0)
        {
          int a2 = N/i;
          sum += i;
          if(a2 != i)
            sum += a2;
        }
      }
      cout << sum << endl;
  }
  return 0;
}
