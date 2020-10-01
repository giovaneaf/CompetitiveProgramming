#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 210
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<ii> vii;

bool visited[1010];
double dist[1010];
map<ii, ii> myMap;
int n, m;

double dijkstra(vi* adj, double time)
{
	for(int i = 0; i < n; ++i)
	{
		dist[i] = 1000000000000000000.0;
		visited[i] = false;
	}
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	dist[0] = 0.0;
	pq.push({0.0, 0});
	while(pq.size())
	{
		int cur = pq.top().second;
		pq.pop();
		if(cur == n-1) return dist[cur];
		if(visited[cur]) continue;
		visited[cur] = true;
		for(int i = 0; i < adj[cur].size(); ++i)
		{
			int u = adj[cur][i];
			if(visited[u]) continue;
			ii ray = myMap[{min(cur, u), max(cur, u)}];
			double newdist = dist[cur] + ray.first*time + ray.second;
			if(dist[u] > newdist)
			{
				dist[u] = newdist;
				pq.push({newdist, u});
			}
		}
	}
	return dist[n-1];
}

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vi adj[n];
		for(int i = 0; i < m; ++i)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
			myMap[{min(a, b), max(a, b)}] = {c, d};
		}
		double l = 0;
		double cl = dijkstra(adj, 0.0);
		double h = 1440;
		double ch = dijkstra(adj, 1440.0);
		while(h-l > EPS)
		{
			double mid1 = (h+2.0*l)/3.0;
			double cm1 = dijkstra(adj, mid1);
			double mid2 = (2.0*h+l)/3.0;
			double cm2 = dijkstra(adj, mid2);
			if(cm1 < cm2)
			{
				l = mid1;
				cl = cm1;
			}
			else
			{
				h = mid2;
				ch = cm2;
			}
		}
		printf("%.5f\n", max(cl, ch));
		myMap.clear();
	}
	return 0;
}