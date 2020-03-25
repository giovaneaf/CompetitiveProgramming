#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
int ans;

void DFS(int cur, vi* adj, vector<bool>& seen)
{
	ans++;
	seen[cur] = true;
	for(int i = 0; i < adj[cur].size(); ++i)
	{
		int u = adj[cur][i];
		if(!seen[u]) DFS(u, adj, seen);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	int t = 0;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		t++;
		printf("Teste %d\n", t);
		vi adj[n];
		for(int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<bool> seen(n, false);
		ans = 0;
		DFS(0, adj, seen);
		if(ans == n)
		{
			printf("normal\n\n");
		}
		else
		{
			printf("falha\n\n");
		}
	}
	return 0;
}