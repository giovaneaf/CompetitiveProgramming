#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 10010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m;
int dad[MAXN];
int c[MAXN];
int L[MAXN];
int P[MAXN][LOGMAXN];
int cost[MAXN][LOGMAXN];
 
void DFS(int cur, vii* adj, vb& seen)
{
	seen[cur] = true;
	for(ii p : adj[cur])
	{
		int u = p.fst;
		int w = p.snd;
		if(!seen[u])
		{
			dad[u] = cur;
			c[u] = w;
			L[u] = 1 + L[cur];
			DFS(u, adj, seen);
		}
	}
}
 
void init()
{
	FOR(i, 0, n)
	{
		P[i][0] = dad[i];
		cost[i][0] = c[i];
	}
	FOR(j, 1, LOGMAXN)
	{
		FOR(i, 0, n)
		{
			if(P[i][j-1] != -1)
			{
				P[i][j] = P[P[i][j-1]][j-1];
				cost[i][j] = cost[i][j-1] + cost[P[i][j-1]][j-1];
			}
			else 
			{
				P[i][j] = -1;
				cost[i][j] = cost[i][j-1];
			}
		}
	}
}
 
int LCA(int a, int b)
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
 
int getCost(int a, int b)
{
	int ans = 0;
	if(L[a] < L[b]) swap(a, b);
	RFOR(i, LOGMAXN-1, 0)
	{
		if(L[a] - (1 << i) >= L[b]) 
		{
			ans += cost[a][i];
			a = P[a][i];
		}
	}
	if(a == b) return ans;
	RFOR(i, LOGMAXN-1, 0)
	{
		if(P[a][i] != P[b][i]) 
		{
			ans += cost[a][i];
			ans += cost[b][i];
			a = P[a][i];
			b = P[b][i];
		}
	}
	return ans + c[a] + c[b];
}
 
inline int bl(int a, int h)
{
	RFOR(i, LOGMAXN-1, 0)
	{
		if((1 << i) <= h)
		{
			h -= (1 << i);
			a = P[a][i];
		}
	}
	return a+1;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		vii adj[n];
		FOR(i, 0, n-1)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			adj[a].push_back(mp(b, c));
			adj[b].push_back(mp(a, c));
		}
		c[0] = 0;
		dad[0] = -1;
		vb seen(n, false);
		DFS(0, adj, seen);
		init();
		string s;
		while(cin >> s)
		{
			if(s == "DONE") break;
			int a, b;
			cin >> a >> b;
			a--, b--;
			if(s[0] == 'D')
			{
				printf("%d\n", getCost(a, b));
			}
			else
			{
				int k;
				cin >> k;
				k--;
				int lca = LCA(a, b);
				if(lca == b)
				{
					printf("%d\n", bl(a, k));
				}
				else if(lca == a)
				{
					int h = (L[b]-L[a])-k;
					printf("%d\n", bl(b, h));
				}
				else
				{
					int h = L[a] - L[lca];
					if(k <= h)
					{
						printf("%d\n", bl(a, k));
					}
					else
					{
						k -= h;
						int h = (L[b]-L[lca])-k;
						printf("%d\n", bl(b, h));
					}
				}
			}
		}
	}
	return 0;
}  