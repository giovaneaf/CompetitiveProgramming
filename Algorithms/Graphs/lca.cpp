/*

Find LCA in O(V*log(V)) where:
V is the number of vertices in the graph
Tested in problem LCA from SPOJ

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define vi vector<int>
#define vvi vector<vi>
#define MAXN 100010
#define LOGMAXN 20

struct LCA
{
	int n;
	vvi P;
	vi dad, L;
	
	LCA(int n, vi* adj) : n(n)
	{
		P.assign(n, vi(LOGMAXN, -1));
		dad.assign(n, -1); L.assign(n, -1);
		L[0] = 0;
		DFS(0, -1, adj);
		prep();
	}
	
	void DFS(int cur, int parent, vi* adj) 
	{
		dad[cur] = parent;
		for(int& u : adj[cur])
		{
			if(L[u] == -1) 
			{
				L[u] = 1 + L[cur];
				DFS(u, cur, adj);
			}
		}			
	}
	
	void prep() 
	{
		for(int i = 0; i < n; ++i) 
			P[i][0] = dad[i];
		for(int j = 1; j < LOGMAXN; ++j)
			for(int i = 0; i < n; ++i)
				if(P[i][j-1] != -1)
					P[i][j] = P[P[i][j-1]][j-1];
	}
	
	int query(int a, int b)
	{
		if(L[a] < L[b]) swap(a, b);
		for(int i = LOGMAXN-1; i >= 0; --i)
			if(L[a] - (1 << i) >= L[b])
				a = P[a][i];
		if(a == b) return a;
		for (int i = LOGMAXN-1; i >= 0; i--)
		{
			if (P[a][i] != P[b][i])
			{
				a = P[a][i];
				b = P[b][i];
			}
		}
		return dad[a];
	}
};

int T, n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		cin >> n;
		vi adj[n];
		int a, b, q;
		for(int i = 0; i < n; ++i)
		{
			cin >> m;
			while(m--)
			{
				cin >> a;
				a--;
				adj[a].emplace_back(i);
				adj[i].emplace_back(a);
			}
		}
		LCA lca(n, adj);
		cin >> q;
		printf("Case %d:\n", t);
		while(q--)
		{
			cin >> a >> b;
			printf("%d\n", lca.query(a-1, b-1)+1);
		}
	}
}
