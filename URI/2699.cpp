#include <bits/stdc++.h>

using namespace std;

int memo[1005][1005];
string num;
int n;

bool B(int pos, int mod) {
  if(pos == num.size()) return mod == 0;
  if(memo[pos][mod] != -1) return memo[pos][mod];
  bool possible = false;
  if(num[pos] == '?') {
    for(int i = 0; i < 10; ++i) {
      if(i == 0 && pos == 0) continue;
      possible |= B(pos+1, (mod*10+i)%n);
    }
  } else {
    possible |= B(pos+1, (mod*10+(num[pos]-'0'))%n);
  }
  return memo[pos][mod] = possible;
}

int main() {
  while(cin >> num >> n) {
    for(int i = 0; i < num.size(); i++) {
      for(int j = 0; j < n+5; ++j) {
        memo[i][j] = -1;
      }
    }
    if(!B(0, 0)) printf("*\n");
    else {
      string ans = "";
      int mod = 0;
      for(int i = 0; i < num.size(); ++i) {
        if(num[i] == '?') {
          for(int j = 0; j < 10; j++) {
            if(j == 0 and i == 0) continue;
            if(B(i+1, (mod*10+j)%n)) {
              ans += '0'+j;
              mod = (mod*10+j)%n;
              break;
            }
          }
        } else {
          ans += num[i];
          mod = (10*mod+(num[i]-'0'))%n;
        }
      }
      cout << ans << endl;
    }
  }
}