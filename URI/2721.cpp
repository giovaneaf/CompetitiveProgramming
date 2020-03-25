#include <bits/stdc++.h>

using namespace std;

int main() {
  char s[9][101] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};
  int sum = -1;
  for(int i = 0; i < 9; ++i) {
    int a;
    scanf("%d", &a);
    sum += a;
  }
  sum %= 9;
  cout << s[sum] << endl;
}