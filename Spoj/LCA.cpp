#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m;
int dad[MAXN];
int L[MAXN];
int P[MAXN][LOGMAXN];
 
void DFS(int cur, vi* adj, vb& seen)
{
	seen[cur] = true;
	for(int u : adj[cur])
	{
		if(!seen[u])
		{
			dad[u] = cur;
			L[u] = 1 + L[cur];
			DFS(u, adj, seen);
		}
	}
}
 
void init()
{
	FOR(i, 0, n) P[i][0] = dad[i];
	FOR(j, 1, LOGMAXN)
		FOR(i, 0, n)
			if(P[i][j-1] != -1) P[i][j] = P[P[i][j-1]][j-1];
			else P[i][j] = -1;
}
 
int lca(int a, int b)
{
	if(L[a] < L[b]) swap(a, b);
	RFOR(i, LOGMAXN-1, 0)
	{
		if(L[a] - (1 << i) >= L[b]) a = P[a][i];
	}
	if(a == b) return a;
	RFOR(i, LOGMAXN-1, 0)
	{
		if(P[a][i] != P[b][i]) 
		{
			a = P[a][i];
			b = P[b][i];
		}
	}
	return dad[a];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	FOR(t, 0, T)
	{
		printf("Case %d:\n", t+1);
		cin >> n;
		vi deg(n, 0);
		vi adj[n];
		FOR(i, 0, n)
		{
			int sz;
			cin >> sz;
			while(sz--)
			{
				int u;
				cin >> u;
				u--;
				adj[i].emplace_back(u);
				deg[u]++;
			}
		}
		vb seen(n, false);
		FOR(i, 0, n)
		{
			if(deg[i] == 0)
			{
				dad[i] = -1;
				L[i] = 0;
				DFS(i, adj, seen);
				break;
			}
		}
		init();
		int q;
		cin >> q;
		while(q--)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			printf("%d\n", lca(a, b)+1);
		}
	}		
	return 0;
}  