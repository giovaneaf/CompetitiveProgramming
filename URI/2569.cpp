#include <bits/stdc++.h>

using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  for(int i = 0; i < a.size(); ++i) {
    if(a[i] == '7') {
      a[i] = '0';
    }
  }
  for(int i = 0; i < c.size(); ++i) {
    if(c[i] == '7') {
      c[i] = '0';
    }
  }
  string ans;
  if(b[0] == '+') {
    ans = to_string(stoi(a) + stoi(c));
  } else {
    ans = to_string(stoi(a) * stoi(c));
  }
  for(int i = 0; i < ans.size(); ++i) {
    if(ans[i] == '7') {
      ans[i] = '0';
    }
  }
  cout << stoi(ans) << endl;
  return 0;
}