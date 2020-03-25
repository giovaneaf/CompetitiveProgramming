#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define MAXN 1010

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
int n, m, q;
bool ambulance[MAXN];

int Dijkstra(vii* adj)
{
	vector<int> dist(n, INF);
	vector<bool> seen(n, false);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for(int i = 0; i < n; ++i)
	{
		if(ambulance[i])
		{
			dist[i] = 0;
			pq.push(make_pair(0, i));
		}
	}
	while(pq.size())
	{
		int cur = pq.top().second;
		pq.pop();
		seen[cur] = true;
		for(int i = 0; i < adj[cur].size(); ++i)
		{
			int u = adj[cur][i].first;
			int w = adj[cur][i].second;
			if(!seen[u] && dist[u] > dist[cur] + w)
			{
				dist[u] = dist[cur]+w;
				pq.push(make_pair(dist[u], u));
			}
		}
	}
	return *max_element(dist.begin(), dist.end());
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> q)
	{
		for(int i = 0; i < n; ++i)
		{
			ambulance[i] = false;
		}
		vii adj[n];
		for(int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			adj[a].push_back({b, c});
			adj[b].push_back({a, c});
		}
		for(int i = 0; i < q; ++i)
		{
			int u;
			cin >> u;
			u--;
			ambulance[u] = true;
		}
		int ans = Dijkstra(adj);
		printf("%d\n", ans);
	}
	return 0;
}