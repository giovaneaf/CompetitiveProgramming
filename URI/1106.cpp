#include <bits/stdc++.h>

#define INF 1000000000
#define MAXN 310
#define EPS 1e-9

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

int n;
double P[MAXN][MAXN];
double dp[MAXN][MAXN];
int C[MAXN];
int parent[MAXN][MAXN];
set<int> candidates[2][MAXN];
ii race[MAXN];
int unknows[MAXN];

int DFS(int p, int cur, int par, int* adj)
{
	parent[p][cur] = par;
	int u = adj[cur];
	if(u == -1)
		return cur;
	return DFS(p, u, cur, adj);
}

double solve(queue<int>& q, int* adj)
{
	while(q.size())
	{
		int crace = q.front();
		q.pop();
		set<int> a = candidates[0][crace];
		set<int> b = candidates[1][crace];
		int v = adj[crace];
		double prob = 0.0;
		for(auto it = a.begin(); it != a.end(); ++it)
		{
			int u = *it;
			double prob = 0.0;
			for(auto it2 = b.begin(); it2 != b.end(); ++it2)
			{
				int i = *it2;
				prob += P[u][i]*dp[i][crace];
			}
			dp[u][v] = prob*dp[u][crace];
		}
		for(auto it = b.begin(); it != b.end(); ++it)
		{
			int u = *it;
			double prob = 0.0;
			for(auto it2 = a.begin(); it2 != a.end(); ++it2)
			{
				int i = *it2;
				prob += P[u][i]*dp[i][crace];
			}
			dp[u][v] = prob*dp[u][crace];
		}
		unknows[v]--;
		if(unknows[v] == 0)
			q.push(v);
	}
	return dp[0][n-1];
}

set<int> computeCandidates(int cur)
{
	ii p = race[cur];
	int i1 = p.first;
	int i2 = p.second;
	candidates[0][cur].clear();
	candidates[1][cur].clear();
	if(i1 < n)
	{
		candidates[0][cur].insert(i1);
	}
	else
	{
		candidates[0][cur] = computeCandidates(i1-n);
	}
	if(i2 < n)
	{
		candidates[1][cur].insert(i2);
	}
	else
	{
		candidates[1][cur] = computeCandidates(i2-n);
	}
	set<int> ans;
	set_union(candidates[0][cur].begin(), candidates[0][cur].end(), 
	candidates[1][cur].begin(), candidates[1][cur].end(), inserter(ans, ans.begin()));
	return ans;
}

int main()
{
	while(1)
	{
		cin >> n;
		if(n == 0) break;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				cin >> P[i][j];
		int adj[n];
		for(int i = 0; i < n; ++i)
		{
			adj[i] = -1;
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				dp[i][j] = -1.0;
			}
		}
		queue<int> q;
		for(int i = 0; i < n-1; ++i)
		{
			unknows[i] = 0;
			int a, b;
			cin >> a >> b;
			a--, b--;
			if(a < n)
				dp[a][i] = 1.0;
			else
				adj[a-n] = i, unknows[i]++;
			if(b < n)
				dp[b][i] = 1.0;
			else
				adj[b-n] = i, unknows[i]++;
			if(unknows[i] == 0)
				q.push(i);
			race[i] = {a, b};
		}
		unknows[n-1] = 3;
		vb inPath;
		int last = DFS(0, C[0], -1, adj);
		computeCandidates(last);
		adj[last] = n-1;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				parent[i][j] = -1;
			}
		}
		for(int i = 0; i < n; ++i)
			DFS(i, C[i], -1, adj);
		int idx = (candidates[0][last].find(0) == candidates[0][last].end() ? 0 : 1);
		for(auto it = candidates[idx][last].begin(); it != candidates[idx][last].end(); it++)
		{
			candidates[0][n-1].insert(*it);
		}
		printf("%.6f\n", solve(q, adj));
	}
	return 0;
}