#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int Dijkstra(int K, int d, vector< vector< pair<int, int> > >& v, int N)
{
	bool visited[N];
	int dist[N];
	memset(visited, false, sizeof(visited));
	memset(dist, -1, sizeof(dist));
	dist[K] = 0;
	priority_queue< pair<int, int>, vector < pair<int, int> >, greater< pair<int, int> > > pq;
	pq.push(make_pair(0, K));
	while(pq.size())
	{
		int u = pq.top().second;
		visited[u] = true;
		pq.pop();
		if(u == d)
			return dist[d];
		for(int i = 0; i < v[u].size(); i++)
		{
			int s = v[u][i].first; int w = v[u][i].second;
			if(!visited[s])
			{
				if(u < d && s != u+1)
					continue;
				if(dist[s] == -1 || dist[s] > dist[u] + w)
				{
					dist[s] = dist[u] + w;
					pq.push(make_pair(dist[s], s));
				}
			}
		}
	}
	return -1;
}

int main()
{
	int N, M, C, K;
	while(cin >> N >> M >> C >> K && N != 0)
	{
		vector< vector< pair<int, int> > > v(N);
		for(int i = 0; i < M; i++)
		{
			int s, d, w;
			cin >> s >> d >> w;
			v[s].push_back(make_pair(d,w));
			v[d].push_back(make_pair(s,w));
		}
		cout << Dijkstra(K, C-1, v, N) << endl;
	}
	return 0;
}