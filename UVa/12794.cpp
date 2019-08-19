/*
Run Dijkstra for each query storing the shortest path from u (starting node) to any other node and then verifies with
DFS all the cycles computing it's length that is impossible if the cycle length starting at x is less than 
Miss Worm body length, otherwise it's equal to 2*(Dijkstra value from u to x) + cycle length, get the minimum value
between all possible cycles.
The 2*(Dijkstra value from u to x) + cycle length it's because you can go the fastest way from u to x (Dijkstra value)
then need to use the cycle to go back.
*/

#include <bits/stdc++.h>

#define mp make_pair
#define INF 1e9

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int S, T;
int sdist[10010];
int dist[10010];
int len;
int ans;

void DFS(int cur, int parent, vii* adj, vector<int>& visited)
{
	visited[cur] = 1;
	for(int i = 0; i < (int) adj[cur].size(); ++i)
	{
		int u = adj[cur][i].first;
		int w = adj[cur][i].second;
		if(parent == u) continue;
		if(visited[u] == 0)
		{
			dist[u] = dist[cur] + w;
			DFS(u, cur, adj, visited);
		}
		else if(visited[u] == 1 and w + dist[cur] - dist[u] >= len)
		{
			ans = min(ans, w + dist[cur] - dist[u] + 2*sdist[u]);
		}
	}
	visited[cur] = 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> S >> T)
	{
		vii adj[S];
		while(T--)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			adj[a].push_back(mp(b, c));
			adj[b].push_back(mp(a, c));
		}
		int Q;
		cin >> Q;
		while(Q--)
		{
			int cur;
			cin >> cur >> len;
			cur--;
			for(int j = 0; j < S; ++j)
			{
				dist[j] = sdist[j] = INF;
			}
			dist[cur] = sdist[cur] = 0;
			priority_queue<ii> pq;
			pq.push(mp(0, cur));
			while(pq.size())
			{
				int u = pq.top().second;
				int d = -pq.top().first;
				pq.pop();
				if(d > sdist[u]) continue;
				for(int j = 0; j < (int) adj[u].size(); ++j)
				{
					int v = adj[u][j].first;
					int w = adj[u][j].second;
					if(sdist[v] > sdist[u] + w)
					{
						sdist[v] = sdist[u] + w;
						pq.push(mp(-sdist[v], v));
					}
				}
			}
			ans = INF;
			vector<int> visited;
			visited.assign(S, 0);
			DFS(cur, -1, adj, visited);
			cout << (ans == INF ? -1 : ans) << "\n";
		}
	}
}
