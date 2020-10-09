#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    getchar();
    char M[2005][2005];
    for(int i = 0; i < n; ++i) {
        fgets(M[i], m+2, stdin); // m+2 to get '\n'
    }
    
    int times = 0;
    int cnt;
    for(int i = 0; i < n; ++i) {
      cnt = 0;
      for(int j = 0; j < m; ++j) {
        if(M[i][j] == '*') {
          cnt = 0;
        } else {
          if(cnt == k-1) times++;
          else cnt++;
        }
      }
    }
    if(k > 1) {
      for(int j = 0; j < m; ++j) {
        cnt = 0;
        for(int i = 0; i < n; ++i) {
          if(M[i][j] == '*') {
            cnt = 0;
          } else {
            if(cnt == k-1) times++;
            else cnt++;
          }
        }
      }
    }
    cout << times << endl;
    return 0;
}
