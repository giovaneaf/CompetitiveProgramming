#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define rREP(i, a, n) for(int i = a; i >= n; --i)

bool cycle;

void dfs(int init, int cur, int parent, vector<bool>& visited, vector<vi>& adj)
{
	visited[cur] = true;
	if((int) adj[cur].size() > 2)
	{
		cycle = false;
		return ;
	}
	if((int) adj[cur].size() == 2 and (adj[cur][0] == init || adj[cur][1] == init) and parent != init)
	{
		cycle = true;
		return ;
	}
	for(int i = 0; i < adj[cur].size(); ++i)
	{
		int u = adj[cur][i];
		if(u == parent)
			continue;
		else if(!visited[u])
			dfs(init, u, cur, visited, adj);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vi> adj(n+5);
	REP(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> visited;
	visited.assign(n, false);
	int cnt = 0;
	REP(i, 0, n)
	{
		cycle = false;
		if(!visited[i])
		{
			dfs(i, i, -1, visited, adj);
			if(cycle)
			{
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}
