#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                int c = i^j;
                if(j<=c and (i+j) > c and c <= n) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
