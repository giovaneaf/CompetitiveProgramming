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
#define MAXN 110
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
int n, m, x;
ll maxPathCost;
 
ll Dijkstra(ll maxDist, vector<pair<int, ll>>* adj, bool hasLimit)
{
	vector<ll> dist(n, -1LL);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[0] = 0LL;
	pq.push(mp(0LL, 0));
	int cur, curW;
	while(pq.size())
	{
		curW = pq.top().fst;
		cur = pq.top().snd;
		pq.pop();
		if(curW > dist[cur]) continue;
		if(cur == n-1) return dist[n-1];
		int v;
		ll w;
		for(pair<int, ll>& p : adj[cur])
		{
			v = p.fst; w = p.snd;
			if(hasLimit && w > maxDist) continue;
			if(dist[v] == -1LL || dist[v] > dist[cur] + w)
			{
				dist[v] = dist[cur] + w;
				pq.push(mp(dist[v], v));
			}
		}
	}
	return dist[n-1];
}
 
bool can(ll maxDist, vector<pair<int, ll>>* adj)
{
	ll minCost = Dijkstra(maxDist, adj, true);
	if(minCost == -1LL) return false;
	return minCost <= maxPathCost;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> x)
	{
		int a, b;
		vector<pair<int, ll>> adj[n];
		ll c;
		ll l, h, mid;
		l = 1LL; h = 0LL;
		FOR(i, 0, m)
		{
			cin >> a >> b >> c;
			a--, b--;
			adj[a].emplace_back(mp(b, c));
			adj[b].emplace_back(mp(a, c));
			h = max(h, c);
		}
		ll sp = Dijkstra(INFLL, adj, false);
		maxPathCost = sp + (long double)sp/100.0*(long double) x;
		while(h - l > 1)
		{
			mid = (h+l)/2LL;
			if(can(mid, adj))
				h = mid;
			else
				l = mid+1;
		}
		printf("%lld\n", can(l, adj) ? l : h);
	}
	return 0;
}