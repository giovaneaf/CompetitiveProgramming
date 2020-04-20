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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
 
int T;
int n, k, u, v, cur, sz;
 
int DFS(int cur, vi& stree, vb& seen, vi* adj)
{
	seen[cur] = true;
	int ans = 1;
	for(int& v : adj[cur])
	{
		if(!seen[v])
		{
			ans += DFS(v, stree, seen, adj);
		}
	}
	return stree[cur] = ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		vi adj[n];
		vi dist(n, -1);
		FOR(i, 0, n-1)
		{
			cin >> u >> v;
			u--, v--;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}
		vb seen(n, false);
		vi stree(n);
		DFS(0, stree, seen, adj);
		vii v(n);
		queue<int> q;
		dist[0] = 0;
		q.push(0);
		sz = 0;
		while(q.size())
		{
			cur = q.front();
			q.pop();
			v[sz++] = mp(dist[cur] - (stree[cur]-1), cur);
			for(int& v : adj[cur])
			{
				if(dist[v] == -1)
				{
					dist[v] = 1 + dist[cur];
					q.push(v);
				}
			}
		}
		sort(v.begin(), v.end());
		cur = n-1;
		vb mark(n, false);
		FOR(i, 0, k)
		{
			mark[v[cur--].snd] = true;
		}
		queue<ii> qq;
		ll ans, val;
		ans = 0LL;
		qq.push(mp(0, 0));
		fill(seen.begin(), seen.end(), false);
		seen[0] = true;
		while(qq.size())
		{
			cur = qq.front().snd;
			val = qq.front().fst;
			qq.pop();
			if(mark[cur]) ans += val;
			else val++;
			for(int& v : adj[cur])
			{
				if(!seen[v])
				{
					seen[v] = true;
					qq.push(mp(val, v));
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}