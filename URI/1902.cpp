#include <bits/stdc++.h>

using namespace std;

int ans;

void DFS(int cur, unordered_map<int, int>& g, vector<int>& visited)
{
    visited[cur] = -1;
    int u = g[cur];
    if(visited[u] == -1)
    {
        ans++;
    }
    else if(visited[u] == 0)
    {
        DFS(u, g, visited);
    }
    visited[cur] = 1;
}

int main()
{
    string from, to;
    unordered_map<string, int> m;
    unordered_map<int, int> g;
    int index = 0;
    while(cin >> from >> to)
    {
        if(m.find(from) == m.end())
            m[from] = index++;
        if(m.find(to) == m.end())
            m[to] = index++;
        g[m[from]] = m[to];
    }
    ans = 0;
    vector<int> visited;
    visited.assign(index, 0);
    for(int i = 0; i < index; ++i)
    {
        if(visited[i] == 0)
        {
            DFS(i, g, visited);
        }
    }
    printf("%d\n", ans);
    return 0;
}