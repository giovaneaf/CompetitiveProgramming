#include <bits/stdc++.h>

using namespace std;

int n, m;

void DFS(int cur, vector<vector<int>>& g, vector<bool>& visited)
{
    visited[cur] = true;
    for(int i = 0; i < g[cur].size(); ++i)
    {
        int u = g[cur][i];
        if(visited[u]) continue;
        DFS(u, g, visited);
    }
}


int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        vector<vector<int>> g(n);
        for(int i = 0; i < m; ++i)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool> visited;
        visited.assign(n, 0);
        int cmp = 0;
        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                cmp++;
                DFS(i, g, visited);
            }
        }
        printf("%d\n", cmp);
    }
    return 0;
}
