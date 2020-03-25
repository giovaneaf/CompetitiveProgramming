#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, k;
 
int Dijkstra(int src, int dst, vii* adj)
{
	vi dist(n+5, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[src] = 0;
	pq.push(mp(0, src));
	while(pq.size())
	{
		int cur = pq.top().snd;
		pq.pop();
		if(cur == dst) return dist[dst];
		for(ii p : adj[cur])
		{
			int u = p.fst;
			int w = p.snd;
			if(dist[u] > dist[cur] + w)
			{
				dist[u] = dist[cur] + w;
				pq.push(mp(dist[u], u));
			}
		}
	}
	return -1;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vii adj[n+5];
		FOR(i, 0, m)
		{
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].emplace_back(mp(b, c));
			adj[b].emplace_back(mp(a, c));
		}
		int ans = Dijkstra(0, n+1, adj);
		printf("%d\n", ans);
	}
    return 0;
}