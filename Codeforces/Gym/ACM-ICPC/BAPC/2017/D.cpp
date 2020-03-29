#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 110
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
const double pi = atan(1)*4;
 
int n, m;
 
bool Dijkstra(vector<pair<int, ll>>* adj, set<ii>& s)
{
	vector<ll> dist(n, INF);
	vector<int> parent(n, -1);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[1] = 0LL;
	pq.push(mp(0, 1));
	while(pq.size())
	{
		int cur = pq.top().snd;
		int w = pq.top().fst;
		pq.pop();
		if(w > dist[cur]) continue;
		s.insert(mp(cur, parent[cur]));
		for(pair<int, ll>& p : adj[cur])
		{
			int u = p.fst;
			ll w = p.snd;
			if(dist[u] > w + dist[cur])
			{
				dist[u] = w + dist[cur];
				parent[u] = cur;
				pq.push(mp(dist[u], u));
			}
		}
	}
	return dist[0] < INF;
}
 
void DFS(int cur, vector<pair<int, ll>>* adj, vi& parent, vb& seen, set<ii>& s)
{
	seen[cur] = true;
	int u;
	for(pair<int, ll>& p : adj[cur])
	{
		u = p.fst;
		if(s.find(mp(cur, u)) != s.end()) continue;
		if(!seen[u])
		{
			parent[u] = cur;
			DFS(u, adj, parent, seen, s);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n >> m)
	{
		vector<pair<int, ll>> adj[n];
		set<ii> s;
		int a, b;
		ll c;
		FOR(i, 0, m)
		{
			cin >> a >> b >> c;
			adj[a].emplace_back(mp(b, c));
			adj[b].emplace_back(mp(a, c));
		}
		bool can = Dijkstra(adj, s);
		if(!can)
		{
			printf("impossible\n");
		}
		else
		{
			vi parent(n, -1);
			vb seen(n, false);
			DFS(0, adj, parent, seen, s);
			if(parent[1] == -1)
			{
				printf("impossible\n");
			}
			else
			{
				vi ans;
				int cur = 1;
				while(cur != -1)
				{
					ans.emplace_back(cur);
					cur = parent[cur];
				}
				printf("%d", (int) ans.size());
				RFOR(i, (int) ans.size()-1, 0)
				{
					printf(" %d", ans[i]);
				}
				putchar('\n');
			}
		}
	}
	return 0;
}