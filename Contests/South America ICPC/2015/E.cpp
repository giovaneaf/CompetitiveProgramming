#include <bits/stdc++.h>

using namespace std;

int d, p, r, b;

int nd, np, cst;

vector<vector<int>> adj(210);
vector<int> cost;
vector<bool> visited;

void DFS(int cur)
{
	visited[cur] = true;
	cst += cost[cur];
	if(cur >= 100) np++;
	else nd++;
	for(int i = 0; i < adj[cur].size(); ++i)
	{
		int u = adj[cur][i];
		if(!visited[u])
		{
			DFS(u);
		}
	}
}

int knapsack(vector<pair<int, int>>& cc)
{
	int ant[10010];
	int memo[10010];
	for(int j = 0; j <= b; ++j) memo[j] = ant[j] = 0;
	
	for(int i = 1; i <= cc.size(); ++i)
	{
		for(int j = 1; j <= b; ++j)
		{
			int cost = cc[i-1].first;
			memo[j] = ant[j];
			if(j >= cost)
			{
			    int val = cc[i-1].second;
				memo[j] = max(memo[j], val + ant[j-cost]);
			}
		}
		for(int j = 0; j <= b; ++j)
		{
			ant[j] = memo[j];
		}
	}
	return memo[b];
}

int main()
{
	cin >> d >> p >> r >> b;
	cost.assign(210, 0);
    for(int i = 0; i < d; ++i)
	{
		cin >> cost[i];
	}
	for(int i = 0; i < p; ++i)
	{
		cin >> cost[100+i];
	}
	for(int i = 0; i < r; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		v += 100;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	visited.assign(210, false);
	vector<pair<int, int>> ccD;
	vector<pair<int, int>> ccP;
	for(int i = 0; i <= 200; ++i)
	{
		if(visited[i]) continue;
		nd = np = cst = 0;
		DFS(i);
		if(nd == np or cst > b or cst <= 0) continue;
		if(nd > np)
		{
			ccP.push_back(make_pair(cst, nd-np));
		}
		else
		{
			ccD.push_back(make_pair(cst, np-nd));
		}
	}
	
	printf("%d %d\n", d+knapsack(ccD), p+knapsack(ccP));

    return 0;
}