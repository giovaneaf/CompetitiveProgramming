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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
 
int n, m, S;
ll p[MAXN];
pair<int, ll> shelter[15];
ll people;
vector<pair<int, ll>> adj[MAXN];
vector<vector<ll>> dist;

void Dijkstra(int cur, vector<pair<int, ll>>* adj, vector<vector<ll>>& dist, int i)
{
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[cur][i] = 0LL;
	pq.push(mp(dist[cur][i], cur));
	int cost, v, w;
	while(pq.size())
	{
		cost = pq.top().fst;
		cur = pq.top().snd;
		pq.pop();
		if(cost > dist[cur][i]) continue;
		for(pair<int, ll>& p : adj[cur])
		{
			v = p.fst; w = p.snd;
			if(dist[v][i] > dist[cur][i] + w)
			{
				dist[v][i] = dist[cur][i] + w;
				pq.push(mp(dist[v][i], v));
			}
		}
	}
}

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

bool can(ll x, vector<pair<int, ll>>* adj, vector<vector<ll>>& dist)
{
	int s, t;
	s = 1034; t = 1035;
	vector<ll> bucket((1 << S), 0);
	int mask;
	FOR(i, 0, n)
	{
		mask = 0;
		FOR(j, 0, S)
		{
			if(dist[i][j] > x) continue;
			mask |= (1 << j);
		}
		bucket[mask] += p[i];
	}
	Dinic d(t+1, s, t);
	FOR(j, 0, (1 << S))
	{
		d.add_edge(s, j, bucket[j]);
		FOR(i, 0, S)
		{
			if(j & (1 << i))
			{
				d.add_edge(j, 1024+i, INFLL);
			}
		}
	}
	FOR(i, 0, S)
	{
		d.add_edge(1024+i, t, shelter[i].snd);
	}
	return d.flow() == people;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n >> m >> S)
	{
		int a, b;
		ll c;
		dist.assign(MAXN, vector<ll>(10, INFLL));
		people = 0LL;
		FOR(i, 0, n) 
		{
			cin >> p[i];
			people += p[i];
		}
		FOR(i, 0, m)
		{
			cin >> a >> b >> c; a--, b--;
			adj[a].emplace_back(mp(b, c));
			adj[b].emplace_back(mp(a, c));
		}
		FOR(i, 0, S) 
		{
			cin >> shelter[i].fst >> shelter[i].snd;
			shelter[i].fst--;
		}
		FOR(i, 0, S)
		{
			Dijkstra(shelter[i].fst, adj, dist, i);
		}
		ll l = 0LL;
		ll h = 1000000000000000LL;
		ll mid;
		while(h - l > 1)
		{
			mid = l + ((h-l) >> 1);
			if(can(mid, adj, dist))
				h = mid;
			else
				l = mid+1;
		}
		printf("%lld\n", can(l, adj, dist) ? l : h);
		FOR(i, 0, n)
		{
			adj[i].clear();
		}
	}
	return 0;
}