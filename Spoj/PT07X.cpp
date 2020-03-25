#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
int n, q;
vector<bool> visited;
 
int dp[100010][2];
 
void buildDag(int cur, vi* adj, vi* dag)
{
	visited[cur] = true;
	for(int i = 0; i < adj[cur].size(); ++i)
	{
		int u = adj[cur][i];
		if(!visited[u])
		{
			dag[cur].push_back(u);
			buildDag(u, adj, dag);
		}
	}
}
 
int solve(int cur, bool use, vi* dag)
{
	if(dp[cur][use] == -1)
	{
		int ans = 0;
		for(int i = 0; i < dag[cur].size(); ++i)
		{
			int u = dag[cur][i];
			if(use)
				ans += min(solve(u, use, dag), solve(u, !use, dag));
			else
				ans += solve(u, !use, dag);
		}
		dp[cur][use] = ans + use;
	}
	return dp[cur][use];
}
 
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		visited.assign(n, false);
		vi adj[n];
		for(int i = 0; i < n-1; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vi dag[n];
		buildDag(0, adj, dag);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 2; ++j)
				dp[i][j] = -1;
		printf("%d\n", min(solve(0, true, dag), solve(0, false, dag)));
	}
	return 0;
} 