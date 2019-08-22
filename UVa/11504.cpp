/*
If you start knocking the dominos that causes the most number of dominos to fall with it then this will lead to
the minimum number of needed dominos knocked. So you can do a DFS and add the domino in a stack when it's done exploring
its neighbors. Therefore, you have the good order to start knocking the dominos which is the stack order.
*/

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

vi adj[MAXN];

void DFS(int cur, vi* adj, vb& seen, stack<int>& s)
{
	seen[cur] = true;
	for(int u : adj[cur])
	{
		if(!seen[u])
			DFS(u, adj, seen, s);
	}
	s.push(cur);
}

void DFS2(int cur, vi* adj, vb& seen)
{
	seen[cur] = true;
	for(int u : adj[cur])
	{
		if(!seen[u])
			DFS2(u, adj, seen);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		FOR(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
		}
		vb seen(n, false);
		stack<int> s;
		FOR(i, 0, n)
		{
			if(!seen[i]) DFS(i, adj, seen, s);
		}
		seen.assign(n, false);
		int ans = 0;
		while(s.size())
		{
			if(!seen[s.top()]) ans++;
			DFS2(s.top(), adj, seen);
			s.pop();
		}
		printf("%d\n", ans);
		FOR(i, 0, n) adj[i].clear();
	}
    return 0;
}
