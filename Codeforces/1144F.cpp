#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 200010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n, m;
map<ii, int> mm;
bool can;

void DFS(int cur, int c, vi* adj, vi& color, string& ans)
{
	color[cur] = c;
	for(int v : adj[cur])
	{
		if(color[v] == color[cur])
		{
			can = false;
			break;
		}
		if(color[v] == -1) DFS(v, c^1, adj, color, ans);
		auto it = mm.find(mp(cur, v));
		if(it != mm.end())
		{
			ans[it->second] = (c == 0 ? '0' : '1');
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	vi adj[n];
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		mm[mp(a, b)] = i;
	}
	can = true;
	vi color(n, -1);
	string ans(m, '0');
	DFS(0, 0, adj, color, ans);
	printf("%s\n", can ? "YES" : "NO");
	if(can)
	{
		printf("%s\n", ans.c_str());
	}
	return 0;
}