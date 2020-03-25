#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

int main()
{
	int N;
	while(cin >> N)
	{
		vector<pair<int, int>> vote(N);
		for(int i = 0; i < N; i++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			vote[i] = make_pair(u, v);
		}
		int cont = 0;
		for(int i = 0; i < N; i++)
		{
			int werewolf = i;
			vector<int> index;
			int votes = 0;
			for(int j = 0; j < N; j++)
			{
				if (j == werewolf)	continue;
				if(vote[j].first == werewolf || vote[j].second == werewolf)
					votes++;
				else
					index.push_back(j);
			}
			int size = index.size() + N + 2;
			struct graph g(size, size-2, size-1);
			for(int j = 0; j < index.size(); j++)
			{
				g.addEdge(size-2, j, 1);
				g.addEdge(j, vote[index[j]].first+index.size(), 1);
				g.addEdge(j, vote[index[j]].second+index.size(), 1);
			}
			for(int j = 0; j < N; j++)
				if(vote[werewolf].first == j || vote[werewolf].second == j)
					g.addEdge(j+index.size(), size-1, votes-2);
				else
					g.addEdge(j+index.size(), size-1, votes-1);
			int maxflow = g.Dinic();
			if(maxflow < index.size())
				cont++;
		}
		cout << cont << endl;
	}
	return 0;
}




