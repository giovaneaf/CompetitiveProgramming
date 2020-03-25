#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 1010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
 
int n, m;
 
void BFS(int cur, vi* adj, vi& dist)
{
	dist[cur] = 0;
	queue<int> q;
	q.push(cur);
	while(q.size())
	{
		cur = q.front();
		q.pop();
		FOR(i, 0, adj[cur].size())
		{
			int u = adj[cur][i];
			if(dist[u] > -1) continue;
			dist[u] = 1 + dist[cur];
			q.push(u);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vi adj[n];
		vi dist(n, -1);
		FOR(i, 0, n-1)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		BFS(0, adj, dist);
		int l = 0;
		FOR(i, 1, n)
		{
			if(dist[l] < dist[i]) l = i;
		}
		dist.assign(n, -1);
		BFS(l, adj, dist);
		printf("%d\n", *max_element(dist.begin(), dist.end()));
	}
	return 0;
}  