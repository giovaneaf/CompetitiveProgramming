#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 100010
#define MAXK 310
#define MOD 1000000007
#define INF 1e9
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
int n, t;
 
struct graph
{
	struct Edge
	{
		int from, to;
		int cap, flow;
		Edge(int from, int to, int cap, int flow) : from(from), to(to), cap(cap), flow(flow) {}
	};
	vector<vector<int>> g;
	vector<Edge> edge;
	vector<int> pred;
	vector<int> dist;
	int N, s, t;
	graph(int N, int s, int t) : N(N), s(s), t(t) {g.resize(N+10);}
	void addEdge(int u, int v, int cap)
	{
		g[u].push_back(edge.size());
		edge.push_back(Edge(u, v, cap, 0));
		g[v].push_back(edge.size());
		edge.push_back(Edge(v, u, 0, 0));
	}
	bool BFS()
	{
		dist.assign(N, numeric_limits<int>::max());
		pred.assign(N, -1);
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		while(q.size())
		{
			int v = q.front();
			q.pop();
			for(int i = 0; i < g[v].size(); ++i)
			{
				int e = g[v][i];
				if(edge[e].cap - edge[e].flow <= 0)
					continue;
				int u = edge[e].to;
				int d = dist[v]+1;
				if(dist[u] > d)
				{
					dist[u] = d;
					pred[u] = e;
					q.push(u);
				}
			}
		}
		return dist[t] != numeric_limits<int>::max();
	}
	int sendFlow(int u, int flow, int t)
	{
		if(u == t) return flow;
		for(int i = 0; i < g[u].size(); ++i)
		{
			int e = g[u][i];
			if(dist[edge[e].to] == dist[u]+1 && edge[e].flow < edge[e].cap)
			{
				int cur_flow = min(flow, edge[e].cap-edge[e].flow);
				int temp_flow = sendFlow(edge[e].to, cur_flow, t);
				if(temp_flow > 0)
				{
					edge[e].flow += temp_flow;
					edge[e^1].flow -= temp_flow;
					return temp_flow;
				}
			}
		}
		return 0;
	}
	int Dinic()
	{
		int max_f = 0;
		while(BFS())
		{
			while(int f = sendFlow(s, numeric_limits<int>::max(), t))
			{
				max_f += f;
			}
		}
		return max_f;
	}
};
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		graph g(242, 240, 241);
		int s = 240;
		int t = 241;
		for(int i = 0; i < 120; ++i)
		{
			g.addEdge(s, i, 1);
			g.addEdge(i+120, t, 1);
		}
		for(int i = 0; i < n; ++i)
		{
			int r, c;
			cin >> c >> r;
			g.addEdge(r, 120+c, 1);
		}
		cout << g.Dinic() << '\n';
	}
    return 0;
}