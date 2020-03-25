#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

ull fat[21];

void factorial()
{
    fat[0] = 1;
    fat[1] = 1;
    for(int i = 2; i <= 20; i++)
    {
        fat[i] = i*fat[i-1];
    }
}

int main()
{
  int m, n;
  factorial();
  while(cin >> m >> n)
  {
      cout << (fat[m]+fat[n]) << endl;
  }
}
