/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/2910
Dijkstra's algorithm with an easy modification on the relaxing part in case of ties.
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000000000001LL

typedef long long ll;
typedef tuple<int, ll, ll> tiii;
typedef vector<tiii> vtiii;

int n, m;

ll Dijkstra(vtiii* adj)
{
	vector<bool> seen(n, false);
	vector<pair<ll, ll>> dist(n, {INF, INF});
	dist[0] = {0LL, 0LL};
	priority_queue<tuple<ll, int>, vector<tuple<ll, int>>, greater<tuple<ll, int>>> pq;
	pq.push(make_tuple(0LL, 0));
	ll ans = 0LL;
	while(pq.size())
	{
		int cur = get<1>(pq.top());
		pq.pop();
		if(seen[cur]) continue;
		seen[cur] = true;
		ans += dist[cur].second;
		for(int i = 0; i < adj[cur].size(); ++i)
		{
			int u = get<0>(adj[cur][i]);
			if(seen[u]) continue;
			ll d = get<1>(adj[cur][i]);
			ll c = get<2>(adj[cur][i]);
			if((dist[u].first > dist[cur].first + d) || ((dist[u].first == dist[cur].first + d) && dist[u].second > c))
			{
				dist[u] = {dist[cur].first + d, c};
				pq.push(make_tuple(dist[u].first, u));
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vtiii adj[n];
		for(int i = 0; i < m; ++i)
		{
			int a, b;
			ll l, c;
			cin >> a >> b >> l >> c;
			a--, b--;
			adj[a].push_back(make_tuple(b, l, c));
			adj[b].push_back(make_tuple(a, l, c));
		}
		cout << Dijkstra(adj) << '\n';
	}
	return 0;
}