#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 100010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;
int n, m, k;
int dist[MAXN][3];

void BFS(int cur, int id, vi* adj)
{
	dist[cur][id] = 0;
	queue<int> q;
	if(id > 0)
	{
		for(int& v: adj[cur])
		{
			dist[v][id] = 0;
			q.push(v);
		}
	}
	else q.push(cur);
	while(q.size())
	{
		cur = q.front();
		q.pop();
		for(int& v: adj[cur])
		{
			if(dist[v][id] == -1)
			{
				dist[v][id] = 1 + dist[cur][id];
				q.push(v);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> k)
	{
		vi adj[n+2];
		vi radj[n+2];
		int a, b;
		FOR(i, 0, m)
		{
			cin >> b;
			b--;
			adj[b].emplace_back(n);
			radj[n].emplace_back(b);
		}
		FOR(i, 0, k)
		{
			cin >> b;
			b--;
			adj[b].emplace_back(n+1);
			radj[n+1].emplace_back(b);
		}
		FOR(i, 0, n)
		{
			cin >> a;
			FOR(j, 0, a)
			{
				cin >> b;
				b--;
				adj[i].emplace_back(b);
				radj[b].emplace_back(i);
			}
		}
		memset(dist, -1, sizeof(dist));
		BFS(0, 0, adj); BFS(n, 1, radj); BFS(n+1, 2, radj);
		int ans = INF;
		FOR(i, 0, n)
		{
			if(dist[i][0] == -1 || dist[i][1] == -1 || dist[i][2] == -1) continue;
			ans = min(ans, dist[i][0] + dist[i][1] + dist[i][2]);
		}
		if(ans == INF) printf("impossible\n");
		else printf("%d\n", ans);
	}
	return 0;
}