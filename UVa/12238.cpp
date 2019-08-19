/*
You can use Lowest Common Ancestor (LCA) using the O(n.log(n)) binary lifting with this you can compute 
the distance between the path a and b for each query in O(log(n)) each.
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>

#define MAX_NODES 100001

using namespace std;

typedef unsigned long long int ull;

int parent[MAX_NODES], level[MAX_NODES], P[MAX_NODES];

ull dist[MAX_NODES];

void traverse(int node, int head, int prev_section, vector<vector<pair<int, int> > >& v){
    /*head stores the node that is in the same level as the current node
    And is its ancestor*/
    int current_section =  sqrt(level[node]) + 1; 
    if(current_section == 1){
        P[node] = 1 ; 
    }
    else{
        if(current_section == prev_section + 1){
            P[node] = parent[node] ; 
            head = node ; 
        }
        else{
            P[node] = parent[head] ; 
        }
    }
    for(int i = 0 ; i < v[node].size() ; ++i){
        if(v[node][i].first != parent[node]){
            traverse(v[node][i].first, head, current_section, v) ; 
        }
    }
}

int LCA(int u , int v){
    while(P[u] != P[v]){
        if(level[u] > level[v]){
            u = P[u];
        }
        else{
            v = P[v]; 
        }
    }
    while(u != v){
        if(level[u] > level[v]){
            u = parent[u] ; 
        }
        else{
            v = parent[v] ;
        }
    }
    return u ; //Either u or v store the lca. 
}

void getParent(vector<vector<pair<int, int> > >& v, int N)
{
	parent[0] = 0;
	level[0] = 0;
	for(int i = 1; i < N; i++)
	{
		dist[i] = -1;
	}
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(int i = 0; i < v[u].size(); i++)
		{
			if(dist[v[u][i].first] == -1)
			{
				dist[v[u][i].first] = dist[u] + v[u][i].second;
				parent[v[u][i].first] = u;
				level[v[u][i].first] = level[u] + 1;
				q.push(v[u][i].first);
			}
		}
	}
}

int main()
{
	int N;
	while(scanf("%d", &N) != EOF && N)
	{
		vector<vector<pair<int, int> > > v(N);
		for(int i = 0; i < N-1; i++)
		{
			int u, w;
			scanf("%d %d", &u, &w);
			v[i+1].push_back(make_pair(u,w));
			v[u].push_back(make_pair(i+1,w));
		}
		getParent(v, N);
		traverse(0, 0, 0, v);
		int Q;
		scanf("%d", &Q);
		for(int i = 0; i < Q; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%lld", dist[a] + dist[b] - dist[LCA(a, b)]*2);
			if(i < Q-1)
				printf(" ");
		}
		putchar('\n');
	}
	return 0;
}
