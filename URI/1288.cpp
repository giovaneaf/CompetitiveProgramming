#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            v[i] = make_pair(a, b);
        }
        int size;
        scanf("%d", &size);
        int memo[n+1][size+1];
        for(int i = 0; i <= n; ++i) {
            memo[i][0] = 0;
        }
        for(int i = 0; i <= size; ++i) {
            memo[0][i] = 0;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= size; ++j) {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                int cost = v[i-1].second;
                int dmg = v[i-1].first;
                if(j >= cost) {
                    memo[i][j] = max(memo[i][j], dmg + memo[i-1][j-cost]);
                }
            }
        }
        int needed;
        scanf("%d", &needed);
        if(memo[n][size] >= needed) {
            printf("Missao completada com sucesso");
        } else {
            printf("Falha na missao");
        }
        putchar('\n');
    }
    return 0;
}
