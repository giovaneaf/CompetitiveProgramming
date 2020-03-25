/*
    Dijkstra algorithm in O(V + E*log(V)) where
    V is the number of vertices and E is the number of edges
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define fst first
#define snd second
#define mp(a, b) make_pair(a, b)
#define INFLL 1000000000000000000LL

int n, m;   // n vertices and m edges

// Run Dijkstra from src to dst in the adj adjacency list
ll Dijkstra(int src, int dst, vector<pair<int, ll>>* adj)
{
    vector<ll> dist(n+5, INFLL);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[src] = 0LL;
    pq.push(mp(0LL, src));
    while(pq.size())
    {
        int cur = pq.top().snd;
        pq.pop();
        if(cur == dst) return dist[dst];    // remove this line if you want all min dist from src
                                            // then dist[i] have min dist from i to src
        for(pair<int, ll>& p : adj[cur])
        {
            int u = p.fst;
            ll w = p.snd;
            if(dist[u] > dist[cur] + w)
            {
                dist[u] = dist[cur] + w;
                pq.push(mp(dist[u], u));
            }
        }
    }
    return -1LL;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
        vector<pair<int, ll>> adj[n+5];
        int a, b;
        ll c;
        for(int i = 0; i < m; ++i)
        {
            cin >> a >> b >> c;                 // edge (a, b) with cost c
            adj[a].emplace_back(mp(b, c));
            adj[b].emplace_back(mp(a, c));      // add reverse edge if graph is undirected
        }
        ll ans = Dijkstra(0, n-1, adj);
        printf("%lld\n", ans);
    }
    return 0;
}
