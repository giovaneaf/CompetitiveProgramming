#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 200010
#define LOGMAXN 20
#define INF 1000000010
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
 
int n, m, nOfCs;
 
string M[45];
bool visited[45][45];
 
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
 
bool bpm(vi* adj, int cur, vector<bool>& seen, vi& match)
{
	for(int j = 0; j < adj[cur].size(); ++j)
	{
		int u = adj[cur][j];
		if(!seen[u])
		{
			seen[u] = true;
			if(match[u] == -1 || bpm(adj, match[u], seen, match))
			{
				match[u] = cur;
				return true;
			}
		}
	}
	return false;
}
 
int maxMatching(vi& first, vi& second, vi* adj)
{
	vi match;
	match.assign(nOfCs, -1);
	int mx = 0;
	for(int i = 0; i < first.size(); ++i)
	{
		vector<bool> seen;
		seen.assign(nOfCs, false);
		
		if(bpm(adj, first[i], seen, match))
			mx++;
	}
	return mx;
}
 
void ff(int r, int c)
{
	visited[r][c] = true;
	for(int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nc < 0 || nr >= n || nc >= m || M[nr][nc] != 'L' || visited[nr][nc]) continue; // out of bounds or not land!
		ff(nr, nc);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		for(int i = 0; i < n; ++i)
			cin >> M[i];
		nOfCs = 0;
		map<ii, int> mp;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				visited[i][j] = false;
				if(M[i][j] == 'L')
				{
					for(int k = 0; k < 4; ++k)
					{
						int nr = i + dr[k];
						int nc = j + dc[k];
						if(nr < 0 || nc < 0 || nr >= n || nc >= m || M[nr][nc] != 'C') continue; // out of bounds or filled cell!
						M[nr][nc] = 'W';
					}
				}
			}
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(M[i][j] == 'C')
				{
					mp[{i, j}] = nOfCs++;
				}
			}
		}
		vi adj[nOfCs];
		vi first; 	// first bipartite set
		vi second; // second bipartite set
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(M[i][j] == 'C')
				{
					if((i+j) & 1)
					{
						int idx1 = mp[{i, j}];
						first.push_back(idx1);
						for(int k = 0; k < 4; ++k)
						{
							int nr = i + dr[k];
							int nc = j + dc[k];
							if(nr < 0 || nc < 0 || nr >= n || nc >= m || M[nr][nc] != 'C') continue; // out of bounds or filled cell!
							int idx2 = mp[{nr, nc}];
							adj[idx1].push_back(idx2);
							adj[idx2].push_back(idx1);
						}
					}
					else
					{
						second.push_back(mp[{i, j}]);
					}
				}
			}
		}
		int ansff = 0;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(visited[i][j] || M[i][j] != 'L') continue;
				ansff++;
				ff(i, j);
			}
		}
		cout << ansff + nOfCs - maxMatching(first, second, adj) << '\n';
	}
	return 0;
}