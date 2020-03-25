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
	//cout << cur << ' ' << lvl << '\n';
	//cout << ans << '\n';
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