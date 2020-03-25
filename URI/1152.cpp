#include <iostream>
#include <list>
#include <queue>

#define INFINITY 1000000;

using namespace std;

class Graph
{
public:
	Graph (int);
	void addEdge (int, int, int);
	int Prim (int);
private:
	int V;
	list <pair <int, int> >* adj;
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<pair <int, int> > [V];
}

void Graph::addEdge(int v1, int v2, int v3)
{
	adj[v1].push_back(make_pair(v3,v2));
}

int Graph::Prim(int u)
{
	int i;
	bool visited[V];
	int dist[V];
	priority_queue < pair<int, int>, vector < pair < int, int > >, greater < pair <int,int> > > pq;
	for (i = 0; i < V; i++)
	{
		visited[i] = false;
		dist[i] = INFINITY;
	}
	dist[u] = 0;
	
	pq.push(make_pair(dist[u], u));
	
	while(!pq.empty())
	{
		pair <int, int> p = pq.top();
		pq.pop();
		u = p.second;
		if (!visited[u])
		{
			visited[u] = true;
			list <pair <int, int> >::iterator it;
			for (it = adj[u].begin(); it != adj[u].end(); it++)
			{
				int u2 = it->second;
				if (!visited[u2])
				{
					int w2 = it->first;
					if (dist[u2] > w2)
					{
						dist[u2] = w2;
						pq.push(make_pair(w2,u2));
					}
				}
			}
		}
	}
	
	int total = 0;
	
	for (i = 0; i < V; i++)
	{
		total += dist[i];
	}
	
	return total;
}

int main()
{
	int m, n;
	while(cin >> m >> n)
	{
		if (m == 0 && n == 0)
			break;
		Graph g(m);
		int v1,v2,v3;
		int w = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v1 >> v2 >> v3;
			g.addEdge(v1,v2,v3);
			g.addEdge(v2,v1,v3);
			w += v3;
		}
		cout << (w-g.Prim(0)) << endl;
	}
	return 0;
}