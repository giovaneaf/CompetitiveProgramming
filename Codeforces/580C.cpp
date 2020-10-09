#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 100010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n, m;

int cat[MAXN];

int solve(int cur, vi* adj, int cats, vb& seen)
{
	int ans = 0;
	bool leaf = true;
	seen[cur] = true;
	FOR(i, 0, adj[cur].size())
	{
		int u = adj[cur][i];
		if(seen[u]) continue;
		leaf = false;
		if(cat[u] == 0)
		{
			ans += solve(u, adj, 0, seen);
		}
		else if(cats+1 < m)
		{
			ans += solve(u, adj, cats+1, seen);
		}
	}
	if(leaf && cur != 0) return 1;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		m++;
		vi adj[n];
		FOR(i, 0, n) cin >> cat[i];
		vb seen(n, false);
		FOR(i, 0, n-1)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ans = solve(0, adj, cat[0] == 1, seen);
		printf("%d\n", ans);
	}
	return 0;
}