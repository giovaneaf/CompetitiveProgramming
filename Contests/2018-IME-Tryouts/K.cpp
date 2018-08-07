// Dijkstra for shortest path, but the number of nodes in the graph
// should be multiplied by 3 because you need the remainder of division
// by 3 because you can be at position i with a path which the number of
// roads(nr) can be divisible by 3, (nr-1) divisible by 3 or (nr-2)
// divisible by 3. Then check the 3 remainder of division by 3 in 
// the nth intersection
// Time Complexity: O(m*log(v)) - Dijkstra's algorithm

// Dijkstra's algorithm: https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/

#include <bits/stdc++.h>

#define INF 1e9
#define MAXN 100010

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m;
string ans[3];

void Dijkstra(vii* adj)
{
	int dist[MAXN][3];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			dist[i][j] = (int) INF;
		}
	}
	dist[0][0] = 0;
	priority_queue<pair<int, ii>> pq;
	pq.push({0, {0, 0}});
	while(pq.size())
	{
		int cur = pq.top().second.first;
		int rem = pq.top().second.second;
		pq.pop();
		if(cur == n-1) continue;
		for(int i = 0; i < adj[cur].size(); ++i)
		{
			int u = adj[cur][i].first;
			int w = adj[cur][i].second;
			int nrem = (rem+1)%3;
			if(dist[u][nrem] > w + dist[cur][rem])
			{
				dist[u][nrem] = w + dist[cur][rem];
				pq.push({-dist[u][nrem], {u, nrem}});
			}
		}
	}
	vector<ii> v(3);
	for(int i = 0; i < 3; ++i)
	{
		v[i] = {dist[n-1][i], i};
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < 3; ++i)
	{
		if(v[i].second == 0)
			ans[i] = "me";
		else if(v[i].second == 1)
			ans[i] = "Gon";
		else
			ans[i] = "Killua";
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vii adj[n];
		for(int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			--a, --b;
			adj[a].push_back({b, c});
			adj[b].push_back({a, c});
		}
		Dijkstra(adj);
		for(int i = 0; i < 3; ++i)
			cout << ans[i] << "\n";
	}
	return 0;
}