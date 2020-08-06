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
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

struct order
{
	ll s, u, t;
	order(ll s = 0LL, ll u = 0LL, ll t = 0LL) : s(s), u(u), t(t) {}
};

int n, m, k;
ll dist[MAXN][MAXN];
// first pair stores min dist between going from 0 and deliverying all pizzas [i, j]
// second pair stores the bottleneck of the path and if you add this value with
// the time you leave the pizzeria then it'll give the max delay between all deliveries [i, j]
pair<ll, ll> table[MAXN][MAXN];
order p[MAXN];

bool can(ll d)
{
	FOR(i, 0, k)
		// if you can't deliver in time even leaving when pizza is done
		if(d < p[i].t + table[i][i].fst - p[i].s)
			return false;
	vector<ll> l(k, -1LL);
	ll tm, aux;
	l[k-1] = d + p[k-1].s - table[k-1][k-1].fst;
	RFOR(i, k-2, 0)
	{
		FOR(j, i, k)
		{
			// waiting j to be done
			tm = p[j].t + table[i][j].fst + dist[p[j].u][0];
			if(d < table[i][j].snd + p[j].t || (j < k-1 && tm > l[j+1])) continue;
			aux = d-table[i][j].snd;
			if(j < k-1)
			{				
				aux = min(aux, l[j+1]-(table[i][j].fst + dist[p[j].u][0]));
			}
			l[i] = max(l[i], aux);
		}
	}
	return l[0] >= p[0].t;
}

void Dijkstra(int src, vector<pair<int, ll>>* adj)
{
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	int cur, v;
	ll curW, w;
	cur = src;
	dist[src][cur] = 0LL;
	pq.push(mp(dist[src][cur], cur));
	vb seen(n, false);
	while(pq.size())
	{
		cur = pq.top().snd;
		curW = pq.top().fst;
		pq.pop();
		if(seen[cur]) continue;
		seen[cur] = true;
		for(pair<int, ll>& p : adj[cur])
		{
			v = p.fst;
			w = p.snd;
			if(dist[src][v] > dist[src][cur] + w)
			{
				dist[src][v] = dist[src][cur] + w;
				pq.push(mp(dist[src][v], v));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		int a, b;
		ll c;
		FOR(i, 0, n)
			FOR(j, 0, n)
				dist[i][j] = INFLL;
		vector<pair<int, ll>> adj[n];
		FOR(i, 0, m)
		{
			cin >> a >> b >> c;
			a--, b--;
			adj[a].emplace_back(mp(b, c));
			adj[b].emplace_back(mp(a, c));
		}
		FOR(i, 0, n)
		{
			Dijkstra(i, adj);
		}
		cin >> k;
		FOR(i, 0, k)
		{
			cin >> p[i].s >> p[i].u >> p[i].t;
			p[i].u--;
		}
		FOR(i, 0, k)
		{
			table[i][i] = mp(dist[0][p[i].u], dist[0][p[i].u] - p[i].s);
			FOR(j, i+1, k)
			{
				table[i][j].fst = table[i][j-1].fst + dist[p[j-1].u][p[j].u];
				table[i][j].snd = max(table[i][j-1].snd, table[i][j].fst - p[j].s);
			}
		}
		ll l = 0LL;
		ll h = 1000000000000000000LL;
		ll mid;
		while(h - l > 1LL)
		{
			mid = (h+l)/2LL;
			if(can(mid))
				h = mid;
			else
				l = mid+1;
		}
		printf("%lld\n", can(l) ? l : h);
	}
	return 0;
}
