#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, k;
int cnt;

void DFS(int cur, vi* adj, vb& seen)
{
	seen[cur] = true;
	cnt++;
	for(int u : adj[cur])
	{
		if(!seen[u]) DFS(u, adj, seen);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		vi adj[n];
		FOR(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		if(n != m)
		{
			printf("NO\n");
			continue;
		}
		cnt = 0;
		vb seen(n, false);
		DFS(0, adj, seen);
		printf("%s\n", cnt == n ? "FHTAGN!" : "NO");
	}
    return 0;
}
