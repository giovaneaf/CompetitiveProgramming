#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  int cnt = 0;
  while(cin >> n && n) {
    int a;
    while(cin >> a) {
      if(a == 0) {
        putchar('\n');
        break;
      }
      vector<int> v;
      v.push_back(a);
      for(int i = 1; i < n; ++i) {
        cin >> a;
        v.push_back(a);
      }
      stack<int> s;
      int j = 0;
      for(int i = 0; i < n; ++i) {
        if(s.empty() && j < n) {
          s.push(j+1);
          j++;
        }
        while(j < n && s.top() != v[i]) {
          s.push(j+1);
          j++;
        }
        if(v[i] == s.top()) {
          s.pop();
        }
      }
      cout << (s.empty() ? "Yes" : "No") << endl;
    }
    if(cnt == 0) cnt++;
  }
  return 0;
}
