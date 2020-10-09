#include <bits/stdc++.h>

using namespace std;

int main(){
    bool isFib[1005];
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
      isFib[i] = false;
    }
    isFib[1] = true;
    int a = 1;
    int b = 1;
    while(true) {
      int fn = a + b;
      if(fn > n) break;
      isFib[fn] = true;
      a = b;
      b = fn;
    }
    for(int i = 1; i <= n; ++i) {
      putchar(isFib[i] ? 'O' : 'o');
    }
    putchar('\n');
    return 0;
}
