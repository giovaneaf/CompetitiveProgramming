/*
Created dp(i, j) where i is the current node and j is the current level of the stickman (head = 0, chest = 1, "pelvis" = 2)
and this store the maximum number of stickman you can build in the subtree i with current level j.
When you're in level 0 there are only two possibilities, the child use the current head or not, you get the maximum of
this two choices for each children.
When you're in level 1 you need to check all split possibilites with 3 nodes (1 for "pelvis" and the other two
for the arms) for the arms you call for lvl = 0 (head) and for each other node that isn't in this three parts you
call the best of head or chest.
When you're in level 2 if the number of children is greater than one then you add one to the answer and
check all split possibilites with 2 nodes (two for the legs) for the legs you call for lvl = 0 (head) and for each other node that isn't in this two parts you call the best of head or chest.
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000000000001LL

typedef pair<int, int> ii;

int n;

int dp[100001][4];

int solve(int cur, int lvl, vector<int>* adj)
{
	if(dp[cur][lvl] != -1) return dp[cur][lvl];
	int ans = 0;
	if(lvl == 0)
	{
		for(int i = 0; i < adj[cur].size(); ++i)
		{
			ans += max(solve(adj[cur][i], 1, adj), solve(adj[cur][i], 0, adj));
		}
	}
	else if(lvl == 2)
	{
		ans += (adj[cur].size() > 1);
		int best = 0;
		for(int i = 0; i < adj[cur].size(); ++i)
		{
			for(int j = 0; j < adj[cur].size(); ++j)
			{
				if(i == j) continue;
				int tmp = 0;
				for(int l = 0; l < adj[cur].size(); ++l)
				{
					if(l == i || l == j)
						tmp += solve(adj[cur][l], 0, adj);
					else
						tmp += max(solve(adj[cur][l], 0, adj), solve(adj[cur][l], 1, adj));
				}
				best = max(best, tmp);
			}
		}
		ans += best;
	}
	else
	{
		int best = 0;
		for(int i = 0; i < adj[cur].size(); ++i)
		{
			for(int j = 0; j < adj[cur].size(); ++j)
			{
				for(int k = 0; k < adj[cur].size(); ++k)
				{
					if(i == j || j == k || i == k) continue;
					int tmp = 0;
					for(int l = 0; l < adj[cur].size(); ++l)
					{
						if(l == i)
							tmp += solve(adj[cur][l], 2, adj);
						else if(l == j || l == k)
							tmp += solve(adj[cur][l], 0, adj);
						else
							tmp += max(solve(adj[cur][l], 0, adj), solve(adj[cur][l], 1, adj));
					}
					best = max(best, tmp);
				}
			}
		}
		ans = best;
	}
	return dp[cur][lvl] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vector<int> adj[n];
		for(int i = 0; i < n-1; ++i)
		{
			int a;
			cin >> a;
			a--;
			adj[a].push_back(i+1);
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < 4; ++j)
			{
				dp[i][j] = -1;
			}
		}
		cout << solve(0, 0, adj) << '\n';
	}
	return 0;
}