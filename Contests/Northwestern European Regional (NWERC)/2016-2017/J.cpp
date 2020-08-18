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

const ll mod = 1000000007LL;
int n, q, s;
int sq[110];
int c[40];
int acc[40];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> q >> s)
	{
		int ss, t;
		ss = 2*q*n+n;
		t = ss+1;
		Dinic d(t+1, ss, t);
		FOR(i, 0, s)
		{
			cin >> sq[i];
			sq[i]--;
		}
		FOR(i, 0, q)
		{
			cin >> c[i];
		}
		int di, a;
		int bottleneck = 2*q*n;
		int base = 0;
		ll data = 0LL;
		FOR(i, 0, n)
		{
			cin >> di;
			memset(acc, 0, sizeof(acc));
			FOR(j, 0, s)
			{
				cin >> a;
				data += (ll) a;
				acc[sq[j]] += a;
			}
			FOR(j, 0, q)
			{
				d.add_edge(ss, base+j, (ll) acc[j]);
				d.add_edge(base+j, base+q+j, (ll) c[j]);
				d.add_edge(base+q+j, bottleneck, INFLL);
				if(i < n-1)
				{
					d.add_edge(base+q+j, base+q+q+j, INFLL);
				}
			}
			d.add_edge(bottleneck, t, di);
			bottleneck++;
			base += 2*q;
		}
		printf("%s\n", d.flow() == data ? "possible" : "impossible");
	}
	return 0;
}