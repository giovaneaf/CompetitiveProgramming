#include <bits/stdc++.h>
using namespace std;
 
// Kosaraju's Algorithm for SCC in O(n+m)
// Implementation of Kosaraju's Algorithm for SCC
 
typedef long long ll; 
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
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
 
void DFS(int cur, vi* adj, stack<int>& s, vb& seen)
{
	seen[cur] = true;
	for(int u : adj[cur])
	{
		if(!seen[u])
			DFS(u, adj, s, seen);
	}
	s.push(cur);
}
 
void newDFS(int cur, vi* adj, vb& seen, vi& cc)
{
	seen[cur] = true;
	cc.emplace_back(cur);
	for(int u : adj[cur])
	{
		if(!seen[u])
			newDFS(u, adj, seen, cc);
	}
}
 
vvi scc(int n, vi* adj)
{
	vvi ans;
	vi radj[n];
	FOR(i, 0, n)
	{
		for(int u: adj[i])
		{
			radj[u].emplace_back(i);
		}
	}
	stack<int> s;
	vb seen(n, false);
	FOR(i, 0, n)
	{
		if(!seen[i])
			DFS(i, adj, s, seen);
	}
	seen.assign(n, false);
	while(s.size())
	{
		int cur = s.top();
		s.pop();
		if(!seen[cur])
		{
			vi cc;
			newDFS(cur, radj, seen, cc);
			ans.emplace_back(cc);
		}
	}
	return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n && n)
	{
		cin >> m;
		vi adj[n];
		vb seen(n, false);
		FOR(i, 0, m)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			adj[a].emplace_back(b);
			if(c == 2)
				adj[b].emplace_back(a);
		}
		vvi ans = scc(n, adj);
		printf("%d\n", (int) ans.size() == 1 ? 1 : 0);
	}
    return 0;
} 