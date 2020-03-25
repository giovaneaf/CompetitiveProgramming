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
 
int n, m, k;
int ans;
 
void DFS(int cur, vi* adj, vb& seen)
{
	seen[cur] = true;
	ans++;
	for(int u : adj[cur])
	{
		if(!seen[u])
		{
			DFS(u, adj, seen);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
    while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		vi adj[n];
		vb seen(n, false);
		FOR(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		ans = 0;
		DFS(0, adj, seen);
		if(t > 1) putchar('\n');
		printf("Teste %d\n", t++);
		printf("%s\n", ans == n ? "normal" : "falha");
	}
    return 0;
} 