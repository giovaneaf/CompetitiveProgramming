#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<int> indexes;

int DFS(int cur, vi* adj, vector<bool>& visited, int* rank)
{
	visited[cur] = true;
	indexes.push_back(cur);
	int ans = rank[cur];
	for(int i = 0; i < adj[cur].size(); ++i)
	{
		int u = adj[cur][i];
		if(!visited[u])
			ans = max(ans, DFS(u, adj, visited, rank));
	}
	return ans;
}

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	map<string, int> mp;
	int rank[n];
	for(int i = 0; i < n; ++i)
	{
		string s;
		int rk;
		cin >> s >> rk;
		rank[i] = rk;
		mp[s] = i;
	}
	vi adj[n];
	for(int i = 0; i < m; ++i)
	{
		string a, b;
		cin >> a >> b;
		int i1, i2;
		i1 = mp[a];
		i2 = mp[b];
		adj[i1].push_back(i2);
		adj[i2].push_back(i1);
	}
	vector<bool> visited;
	visited.assign(n, false);
	vector<bool> impossible;
	impossible.assign(n, false);
	for(int i = 0; i < n; ++i)
	{
		if(!visited[i] && adj[i].size() > 0)
		{
			int val = DFS(i, adj, visited, rank);
			if(val > 5)
			{
				for(int i = 0; i < indexes.size(); ++i)
				{
					impossible[indexes[i]] = true;
				}
			}
			indexes.clear();
		}
	}
	while(q--)
	{
		string s;
		cin >> s;
		if(mp.find(s) == mp.end())
		{
			cout << "S\n";
		}
		else
		{
			int idx = mp[s];
			if(rank[idx] < 5 && impossible[idx])
			{
				cout << "N\n";
			}
			else
				cout << "S\n";
		}
	}
	return 0;
}