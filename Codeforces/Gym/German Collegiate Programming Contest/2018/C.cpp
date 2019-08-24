/*
This is a DAG (Directed Acyclic Graph). Therefore, you can store in a memoization table the largest value
for each node and only compute once the value for each node. The best value of i is the maximum between each
neighbor of i.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 1010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
 
int n, m;
int dp[MAXN];
 
int DFS(int cur, vii* adj)
{
    if(dp[cur] == -1)
    {
        int ans = 0;
        for(ii p:adj[cur])
        {
            ans = max(ans, p.second + DFS(p.first, adj));
        }
        dp[cur] = ans;
    }
    return dp[cur];
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
        memset(dp, -1, sizeof(dp));
        vii adj[n];
        FOR(i, 0, m)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            adj[a].emplace_back(mp(b, c));
        }
        int ans = 0;
        FOR(i, 0, n)
        {
            if(dp[i] == -1)
            {
                ans = max(ans, DFS(i, adj));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}