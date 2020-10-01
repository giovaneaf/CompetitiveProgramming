#include <iostream>
#include <list>
#include <queue>
#define INFINITO 1000000000

using namespace std;

class Graph
{
public:
    int V;
    list<pair<int, int> >* adj;
    Graph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int> > [V];
    }
    void addEdge(int v1, int v2, int cost)
    {
        adj[v1].push_back(make_pair(v2,cost));
    }

    int Dijkstra(int orig, int dest)
    {
        bool visitado[V];
        int dist[V];
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        for (int i = 0; i < V; i++)
        {
            visitado[i] = false;
            dist[i] = INFINITO;
        }
        dist[orig] = 0;
        pq.push(make_pair(dist[orig],orig));
        while(!pq.empty())
        {
            pair<int, int> p = pq.top();
            int u = p.second;
            pq.pop();
            if (!visitado[u])
            {
                visitado[u] = true;
                list<pair<int, int> >::iterator it;
                for (it = adj[u].begin(); it != adj[u].end(); it++)
                {
                    int v = it->first;
                    int custo = it->second;

                    if (dist[v] > dist[u] + custo)
                    {
                        dist[v] = dist[u] + custo;
                        pq.push(make_pair(dist[v],v));
                    }
                }
            }
        }
        return dist[dest];
    }
};

int main()
{
    int C, V;
    cin >> C >> V;
    Graph g(C), gaux(C);
    int orig, dest, custo;
    for (int i = 0; i < V; i++)
    {
        cin >> orig >> dest >> custo;
        g.addEdge(orig-1,dest-1,custo);
        g.addEdge(dest-1,orig-1,custo);
    }
    for (int i = 0; i < C; i++)
    {
        list<pair<int, int> >::iterator it;
        for (it = g.adj[i].begin(); it != g.adj[i].end(); it++)
        {
            int v = it->first;
            int custo = it->second;
            int tam = g.adj[v].size();
            if (tam > 0)
            {
                list<pair<int, int> >::iterator it2;
                for (it2 = g.adj[v].begin(); it2 != g.adj[v].end(); it2++)
                {
                    int v2 = it2->first;
                    int custo2 = it2->second;
                    gaux.addEdge(i,v2,custo+custo2);
                }
            }
        }
    }
    int preco = gaux.Dijkstra(0,C-1);
    if (preco == INFINITO)
        cout << -1 << endl;
    else
        cout << preco << endl;
    return 0;
}