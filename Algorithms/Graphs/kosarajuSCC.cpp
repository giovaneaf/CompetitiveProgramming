/*

	Kosaraju's Algorithm for Strongly Connected Components (SCC) in O(n+m)
	Implementation of Kosaraju's Algorithm for SCC

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>

int n, m, k;

void DFS(int cur, vi* adj, stack<int>& s, vb& seen)		// first dfs
{
	seen[cur] = true;
	for(int u : adj[cur])
	{
		if(!seen[u])
			DFS(u, adj, s, seen);
	}
	s.push(cur);
}

void newDFS(int cur, vi* adj, vb& seen, vi& cc)			// dfs in reverse graph
{
	seen[cur] = true;
	cc.emplace_back(cur);
	for(int u : adj[cur])
	{
		if(!seen[u])
			newDFS(u, adj, seen, cc);
	}
}

vvi scc(int n, vi* adj, int* mcc)						// return all strongly connected components
{
	vvi ans;
	vi radj[n];
	for(int i = 0; i < n; ++i)
	{
		for(int u: adj[i])
		{
			radj[u].emplace_back(i);
		}
	}
	stack<int> s;
	vb seen(n, false);
	for(int i = 0; i < n; ++i)
	{
		if(!seen[i])
			DFS(i, adj, s, seen);
	}
	seen.assign(n, false);
	int cnt = 0;
	while(s.size())
	{
		int cur = s.top();
		s.pop();
		if(!seen[cur])
		{
			vi cc;
			newDFS(cur, radj, seen, cc);
			ans.emplace_back(cc);
			for(int u : cc)
			{
				mcc[u] = cnt;							// mark vertices in the current connected component
			}
			cnt++;
		}
	}
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vi adj[n];
	int mcc[n];							// store the connected component number of i-th vertex
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].emplace_back(b);
	}
	vvi ans = scc(n, adj, mcc);			// store in ans a vector of all strongly connected components
	for(vector<int>& cc : ans)
	{
		for(int v : cc)					// all vertices in this SCC
		{
			printf("%d ", v);
		}
		putchar('\n');
	}
    return 0;
}
