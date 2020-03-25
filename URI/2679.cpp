#include <bits/stdc++.h>

using namespace std;

int main()
{
  int X;
  cin >> X;
  if(X&1)
    X+=1;
  else
    X+=2;
  cout << X << endl;
}
