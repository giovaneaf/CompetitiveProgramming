#include <bits/stdc++.h>

using namespace std;

bool has7(int a, int b) {
  int rem;
  while(b > 0) {
    rem = b%10;
    if(rem == 7) return true;
    b /= 10;
  }
  while(a > 0) {
    rem = a%10;
    if(rem == 7) return true;
    a /= 10;
  }
  return false;
}

int main(){
  int x;
  scanf("%d", &x);
  int h, m;
  scanf("%d %d", &h, &m);
  int t = 0;
  int ch = h;
  int cm = m;
  while(true) {
    if(has7(ch, cm)) {
      printf("%d\n", t);
      break;
    }
    cm -= x;
    if(cm < 0) {
      cm += 60;
      ch--;
      if(ch < 0) ch = 23;
    }
    t++;
  }
  return 0;
}
