#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
    Graph(int);
    ~Graph();
    void addEdge(int, int, int);
    void DFS(int, int, int*, int*);
private:
    int V;
    list < pair <int,int> >* adj;
};

bool visited[10000];
bool get;

Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair <int, int> > [V];
}

Graph::~Graph()
{
    delete [] adj;
}

void Graph::addEdge(int v1, int v2, int v3)
{
    adj[v1-1].push_back(make_pair(v2-1,v3-1));
}

void Graph::DFS(int root, int depth, int* higher, int* maxi)
{
    if (!visited[root])
    {
        visited[root] = true;
        list< pair <int, int> >::iterator it;
        it = adj[root].begin();
        int c = it->first;
        int l = it->second;
        if (c != 0)
        {
            DFS(c, depth+1, higher,maxi);
        }
        else
        {
            if (get == false)
            {
                get = true;
                *maxi = depth;
            }
            if (depth > *higher)
                *higher = depth;
        }
        if (l != 0)
        {
            DFS(l, 1, higher,maxi);
        }
    }
}

int main()
{
    int N,M;
    int i, j;
    int A,B,C;
    cin >> N;
    Graph E(N);
    for (i = 0; i < N; i++)
    {
        cin >> A >> B >> C;
        if (B == 0)
            B++;
        if (C == 0)
            C++;
        E.addEdge(A,C,B);

    }
    for (i = 0; i < N; i++)
        visited[i] = false;
    get = false;
    int maxe;
    int highere = 1;
    E.DFS(0,1,&highere,&maxe);
    cin >> M;
    Graph D(M);
    for (i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        if (B == 0)
            B++;
        if (C == 0)
            C++;
        D.addEdge(A,B,C);
    }
    for (i = 0; i < M; i++)
        visited[i] = false;
    get = false;
    int maxd;
    int higherd=1;
    D.DFS(0,1,&higherd,&maxd);
    int mixed = max(min(maxd,highere),min(maxe,higherd));
    cout << (N+M-mixed) << endl;
    return 0;
}