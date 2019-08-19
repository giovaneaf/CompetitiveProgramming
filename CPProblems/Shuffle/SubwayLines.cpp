/*
http://codeforces.com/gym/101908/problem/L
Needed the binary lifting LCA, you can check if ab = LCA(a, b) be under of cd = LCA(c, d) and then if they share a
path then LCA(ab, c) or LCA(ab, d) is equal to ab. You can compute the intersection length computing the number of
vertices between the lower between (LCA(a, c), LCA(a, d)) and the lower between (LCA(b, c), LCA(b, d)).
Necessário da query do LCA em O(log(n)), chatinho de implementar, mas pode-se analisar que se o ab = LCA(a, b) 
estiver abaixo do cd = LCA(c, d) então é necessário que LCA(ab, c) ou LCA(ab, d) seja igual à ab para que eles 
compartilhem um caminho em comum. Caso haja intersecção, pode-se calcular o número de vértices fazendo a distância 
entre o mais abaixo entre (LCA(a, c), LCA(a, d)) e o mais abaixo entre (LCA(b, c), LCA(b, d)).
*/

#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 100010
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
int n, q;
int P[MAXN][LOGMAXN];
int dad[MAXN];
int L[MAXN];
 
void dfs(int cur, int depth, vi* adj)
{
	L[cur] = depth;
	for(int i = 0; i < adj[cur].size(); ++i)
	{
		int u = adj[cur][i];
		if(L[u] == -1)
		{
			dad[u] = cur;
			dfs(u, depth+1, adj);
		}
	}
}
 
void buildLCA()
{
	for(int j = 1; j < LOGMAXN; ++j)
		for(int i = 0; i < n; ++i)
			P[i][j] = -1;
	for(int i = 0; i < n; ++i)
		P[i][0] = dad[i];
	for(int j = 1; j < LOGMAXN; ++j)
		for(int i = 0; i < n; ++i)
			P[i][j] = P[P[i][j-1]][j-1];
}
 
int LCA(int a, int b)
{
	if(L[a] < L[b]) swap(a, b);
	for(int i = LOGMAXN-1; i >= 0; --i)
	{
		if(L[a] - (1 << i) >= L[b])
		{
			a = P[a][i];
		}
	}
	if(a == b) return a;
	for (int i = LOGMAXN-1; i >= 0; --i)
	{
		if (P[a][i] != P[b][i])
		{
			a = P[a][i];
			b = P[b][i];
		}
	}
	return dad[a];
}
 
int dist(int a, int b)
{
	if(a == b) return 1;
	if(L[a] < L[b]) swap(a, b);
	int lca = LCA(a, b);
	if(lca == b) return L[a]-L[b]+1;
	return L[a] + L[b] - 2*L[lca]+1;	
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> q)
	{
		vi adj[n];
		for(int i = 0; i < n-1; ++i)
		{
			L[i+1] = -1;
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dad[0] = -1;
		dfs(0, 0, adj);
		buildLCA();
		for(int i = 0; i < q; ++i)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--, b--, c--, d--;
			int ab = LCA(a, b);
			int cd = LCA(c, d);
			if(L[ab] < L[cd])
			{
			    swap(ab, cd);
			    swap(a, c);
			    swap(b, d);
			}
			if(LCA(ab, c) == ab || LCA(ab, d) == ab)
			{
				int na, nb, tmp;
				na = LCA(a, c);
				tmp = LCA(a, d);
				if(L[tmp] > L[na]) na = tmp;
				nb = LCA(b, c);
				tmp = LCA(b, d);
				if(L[tmp] > L[nb]) nb = tmp;
				cout << dist(na, nb);
			}
			else
			{
				cout << "0";
			}
			cout << '\n';
		}
	}
	return 0;
}