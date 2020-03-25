#include <bits/stdc++.h>

using namespace std;

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
	graph(int N, int s, int t) : N(N), s(s), t(t) { g.resize(N+10); }
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
			for(int i = 0; i < g[v].size(); i++)
			{
				int e = g[v][i];
				if(edge[e].cap - edge[e].flow <= 0)
					continue;
				int u = edge[e].to;
				int d = dist[v] + 1;
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
		if(u == t)
			return flow;
		for(int i = 0; i < g[u].size(); i++)
		{
			int e = g[u][i];
			if(dist[edge[e].to] == dist[u] + 1 && edge[e].flow < edge[e].cap)
			{
				int cur_flow = min(flow, edge[e].cap - edge[e].flow);
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
	int Edmond_Karp()
	{
		int max_f = 0;
		while(BFS())
		{
			int f = numeric_limits<int>::max();
			for(int e = pred[t]; e != -1; e = pred[edge[e].from])
			{
				f = min(f, edge[e].cap - edge[e].flow);
			}
			if(f == 0) continue;
			for(int e = pred[t]; e != -1; e = pred[edge[e].from])
			{
				edge[e].flow += f;
				edge[e^1].flow -= f;
			}
			max_f += f;
		}
		return max_f;
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

char M[105][105];
int R[105][105];
int C[105][105];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
	  for(int i = 0; i < n; ++i) {
	    for(int j = 0; j < n; ++j) {
	      cin >> M[i][j];
	    }
	  }
	  int nrow = 0;
	  int ncol = 0;
	  for(int i = 0; i < n; ++i) {
	    for(int j = 0; j < n; ++j) {
	      if(M[i][j] == '.' and (j == 0 or M[i][j-1] == 'X')) nrow++;
	      if(M[i][j] == '.') R[i][j] = nrow;
	    }
	  }
	  for(int j = 0; j < n; ++j) {
	    for(int i = 0; i < n; ++i) {
	      if(M[i][j] == '.' and (i == 0 or M[i-1][j] == 'X')) ncol++;
	      if(M[i][j] == '.') C[i][j] = ncol;
	    }
	  }
	  struct graph g(nrow+ncol+2, nrow+ncol, nrow+ncol+1);
	  for(int i = 0; i < n; ++i) {
	    for(int j = 0; j < n; ++j) {
	      if(M[i][j] == '.')
	        g.addEdge(R[i][j]-1, nrow+C[i][j]-1, 1);
	    }
	  }
	  for(int i = 0; i < nrow; ++i) {
	    g.addEdge(nrow+ncol, i, 1); //source
	  }
	  for(int i = 0; i < ncol; ++i) {
	    g.addEdge(nrow+i, nrow+ncol+1, 1); //sink
	  }
		int maxflow = g.Dinic();
		printf("%d\n", maxflow);
	}
	return 0;
}