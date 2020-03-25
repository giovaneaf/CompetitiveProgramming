#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

long long int Dijkstra(int src, int dst, vector<vector<int> >& v, int* soldiers, int N)
{
	bool visited[N];
	long long int dist[N];
	for(int i = 0; i < N; i++)
	{
		visited[i] = false;
		dist[i] = -1;
	}
	priority_queue<pair<long long int, int>, vector<pair<long long int, int> >, greater<pair<long long int, int> > > pq;
	dist[src] = soldiers[src];
	pq.push(make_pair(dist[src], src));
	while(pq.size())
	{
		int u = pq.top().second;
		int w = pq.top().first;
		if(u == dst)
			return dist[u];
		pq.pop();
		if(!visited[u])
		{
			visited[u] = true;
			for(int i = 0; i < v[u].size(); i++)
			{
				if(dist[v[u][i]] == -1 || dist[v[u][i]] > dist[u] + soldiers[v[u][i]])
				{
					dist[v[u][i]] = dist[u] + soldiers[v[u][i]];
					pq.push(make_pair(dist[v[u][i]], v[u][i]));
				}
			}
		}
	}
	return 1001;
}

int main()
{
	int N, M, K;
	double prob;
	while(scanf("%d %d %d %lf", &N, &M, &K, &prob) != EOF)
	{
		vector<vector<int> > v(N);
		for(int i = 0; i < M; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			a--, b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int soldiers[N];
		for(int i = 0; i < N; i++)
			soldiers[i] = 0;
		long long int A;
		scanf("%lld", &A);
		for(int i = 0; i < A; i++)
		{
			int a;
			scanf("%d", &a);
			soldiers[a-1]++;
		}
		int a, b;
		scanf("%d %d", &a, &b);
		long long int minSoldiers = Dijkstra(a-1, b-1, v, soldiers, N);
		if(minSoldiers > (long long int) K)
			printf("0.000\n");
		else
			printf("%.3lf\n", pow(prob, minSoldiers));
	}
	return 0;
}