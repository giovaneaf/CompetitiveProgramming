#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

struct Edge
{
	int u, v, w;
};

Edge e[MAXM];

int n, m;

int getNeigh(int cur, int pos)
{
	return (e[pos].u == cur) ? e[pos].v : e[pos].u;
}

int Dijkstra(vi* adj)
{
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	vi dist(n, INF);
	vi dad[n];
	vb seen(n, false);
	dist[0] = 0;
	pq.push(mp(0, 0));
	int u, v, w;
	u = 0;
	while(pq.size())
	{
		u = pq.top().snd;
		pq.pop();
		if(seen[u]) continue;
		if(u == n-1) break;
		seen[u] = true;
		for(int i : adj[u])
		{
			v = getNeigh(u, i), w = e[i].w;
			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				dad[v].clear();
				dad[v].emplace_back(i);
				pq.push(mp(dist[v], v));
			}
			else if(dist[v] == dist[u] + w)
			{
				dad[v].emplace_back(i);
			}
		}
	}
	int ans = 0;
	u = n-1;
	queue<int> q;
	q.push(u);
	fill(seen.begin(), seen.end(), false);
	seen[u] = true;
	while(q.size())
	{
		u = q.front();
		q.pop();
		for(int& i : dad[u])
		{
			v = getNeigh(u, i), w = e[i].w;
			ans += w;
			if(seen[v]) continue;
			seen[v] = true;
			q.push(v);
		}
	}
	return 2*ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vi adj[n];
		FOR(i, 0, m)
		{
			cin >> e[i].u >> e[i].v >> e[i].w;
			adj[e[i].u].emplace_back(i);
			adj[e[i].v].emplace_back(i);
		}
		printf("%d\n", Dijkstra(adj));
	}
	return 0;
}
