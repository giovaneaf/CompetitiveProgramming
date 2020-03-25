#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, k;
    while(scanf("%d %d", &r, &k) != EOF) {
       vector<int> v(r);
       for(int i = 0; i < k; ++i) {
           int a, b;
           scanf("%d %d", &a, &b);
           v[--a]++, v[--b]++;
       }
       bool memo[r+1][k+1];
       for(int i = 0; i <= k; ++i) {
           memo[0][i] = false;
       }
       for(int i = 0; i <= r; ++i) {
           memo[i][0] = true;
       }
       for(int i = 1; i <= r; ++i) {
           for(int j = 1; j <= k; ++j) {
               int cnt = v[i-1];
               memo[i][j] = memo[i-1][j];
               if(j >= cnt) {
                   memo[i][j] |= memo[i-1][j-cnt];
               }
           }
       }
       if(memo[r][k]) {
           putchar('S');
       } else {
           putchar('N');
       }
       putchar('\n');
    }
    return 0;
}
