#include <bits/stdc++.h>

using namespace std;

#define INF 1e18

typedef long long ll;
typedef pair<int, ll> il;
typedef vector<il> vil;

int n, m;

ll Dijkstra(int cur, vil* adj, vector<int> &parent)
{
	vector<ll> dist;
	dist.assign(n, (ll) INF);
	priority_queue<pair<ll, int>> pq;
	dist[cur] = 0LL;
	parent[cur] = -1;
	pq.push({0LL, cur});
	while(pq.size())
	{
		cur = pq.top().second;
		ll w = -pq.top().first;
		pq.pop();
		if(dist[cur] != w) continue;
		if(cur == 0)
			return w;
		for(int i = 0; i < adj[cur].size(); ++i)
		{
			int u = adj[cur][i].first;
			w = adj[cur][i].second;
			if(dist[u] > dist[cur] + w)
			{
				dist[u] = dist[cur] + w;
				parent[u] = cur;
				pq.push({-dist[u], u});
			}
		}
	}
	return dist[0];
}

int main()
{
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		vil adj[n];
		for(int i = 0; i < m; ++i)
		{
			ll c;
			int a, b;
			cin >> a >> b >> c;
			a--, b--;
			adj[a].push_back({b, c});
			adj[b].push_back({a, c});
		}
		vector<int> parent;
		parent.assign(n, -1);
		int src;
		cin >> src;
		src--;
		ll ans = Dijkstra(src, adj, parent);
		if(ans <= 120)
		{
			printf("Will not be late. Travel time - %lld - best way -", ans);
		}
		else
		{
			printf("It will be %lld minutes late. Travel time - %lld - best way -", ans - 120LL, ans);
		}
		int u = 0;
		vector<int> path;
		while(u != -1)
		{
			path.push_back(u);
			u = parent[u];
		}
		for(int i = path.size()-1; i >= 0; --i)
			printf(" %d", path[i]+1);
		putchar('\n');
	}
	return 0;
}