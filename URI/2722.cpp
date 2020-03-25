#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  getchar();
  for(int i = 0; i < n; ++i) {
    string a, b;
    string ans = "";
    getline(cin, a);
    getline(cin, b);
    int ia = 0;
    int ib = 0;
    bool isA = true;
    for(int i = 0; i < a.size()+b.size(); ++i) {
      if(isA) {
        if(ia < a.size()) {
          ans += a[ia];
        }
        ia++;
        if(ia < a.size()) {
          ans += a[ia];
        }
        ia++;
        isA = false;
      } else {
        if(ib < b.size()) {
          ans += b[ib];
        }
        ib++;
        if(ib < b.size()) {
          ans += b[ib];
        }
        ib++;
        isA = true;
      }
    }
    cout << ans << endl;
  }
}