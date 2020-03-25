#include <bits/stdc++.h>

using namespace std;

int dp[110][510][20];
int a, b, m, l, k;

void B(int time, int cur, int rem, int boots,vector<vector<pair<int, int>>>& g) {
    if(dp[cur][rem][boots] != -1 && time > dp[cur][rem][boots])
        return;
    dp[cur][rem][boots] = time;
    for(int i = 0; i < g[cur].size(); ++i) {
        int v = g[cur][i].first;
        int w = g[cur][i].second;
        B(w + time, v, l, boots, g);
        if(rem < l and rem >= w and cur < a) {
            B(time, v, rem-w, boots, g);
        } else {
            if(boots > 0 and l >= w) {
                B(time, v, l-w, boots-1, g);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        memset(dp, -1, sizeof(dp));
        cin >> a >> b >> m >> l >> k;
        vector<vector<pair<int, int>>> g(a+b+5);
        int ns, nf, w;
        for(int i = 0; i < m; ++i) {
            cin >> ns >> nf >> w;
            ns--, nf--;
            g[ns].push_back(make_pair(nf, w));
            g[nf].push_back(make_pair(ns, w));
        }
        dp[a+b-1][l][k] = 0;
        B(0, a+b-1, l, k, g);
        int ans = 1000000000;
        for(int i = 0; i <= l; ++i) {
            for(int j = 0; j <= k; ++j) {
                if(dp[0][i][j] != -1)
                    ans = min(ans, dp[0][i][j]);
            }
        }
        cout << ans << "\n";
    }
}