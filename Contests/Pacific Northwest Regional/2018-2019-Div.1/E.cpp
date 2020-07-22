/*
Min-cut problem solved with a maximum flow algorithm (Dinic)
*/

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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000009
 
int n, m, c;
string M[MAXN];
int cost[MAXN];

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

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

ll getCost(char c)
{
	if(c >= 'a' && c <= 'z') return (ll) cost[c-'a'];
	return INFLL;
}

bool safe(int r, int c, vector<vector<bool>>& seen)
{
	if(r == 0 || r == n-1 || c == 0 || c == m-1) return true;
	seen[r][c] = true;
	int nr, nc;
	bool isSafe = false;
	FOR(i, 0, 4)
	{
		nr = r + dr[i];
		nc = c + dc[i];
		if(M[nr][nc] == '.' && !seen[nr][nc])
		{
			isSafe = isSafe || safe(nr, nc, seen);
		}
	}
	return isSafe;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> m >> n >> c)
	{
		FOR(i, 0, n)
		{
			cin >> M[i];
		}
		FOR(i, 0, c) cin >> cost[i];
		int s, t;
		t = 1800;
		vector<vector<bool>> seen(n, vector<bool>(m, false));
		bool isSafe = false;
		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				if(M[i][j] == 'B')
				{
					if(safe(i, j, seen))
					{
						printf("-1\n");
						isSafe = true;
						break;
					}
					s = 2*(i*m+j);
				}
			}
		}
		if(!isSafe)
		{
			Dinic d(t+1, s, t);
			int id, id2, ni, nj;
			FOR(i, 1, n-1)
			{
				FOR(j, 1, m-1)
				{
					id = 2*(i*m+j);
					d.add_edge(id, id+1, getCost(M[i][j]));
					FOR(k, 0, 4)
					{
						ni = i+dr[k];
						nj = j+dc[k];
						d.add_edge(id+1, 2*(ni*m+nj), INF);
					}
				}
			}
			FOR(i, 0, n)
			{
				id = 2*(i*m);
				id2 = 2*(i*m+m-1);
				d.add_edge(id, id+1, getCost(M[i][0]));
				d.add_edge(id2, id2+1, getCost(M[i][m-1]));
				d.add_edge(id+1, t, INFLL);
				d.add_edge(id2+1, t, INFLL);
			}
			FOR(j, 1, m-1)
			{
				id = 2*(j);
				id2 = 2*((n-1)*m+j);
				d.add_edge(id, id+1, getCost(M[0][j]));
				d.add_edge(id2, id2+1, getCost(M[n-1][j]));
				d.add_edge(id+1, t, INFLL);
				d.add_edge(id2+1, t, INFLL);
			}
			printf("%lld\n", d.flow());
		}
	}
	return 0;
}