// Did Dijkstra with addition of a new "state" which is the string's current position, 
// 4 adjacent edges with cost 1 (add a letter to command string) and the command string edge
// with cost 0 which depends on string's current position and noticed that because it costs 0
// you can let it don't move (if it will move to a blocked cell or out of bounds) and 
// advance string's current position
// Time Complexity: O(n*m*|string|*log(n*m*|string|)) - Dijkstra's Algorithm (the number of edges is 5*number of nodes)

// Dijkstra's Algorithm here: https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define LOGMAXN 20
#define INF 1000000010

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

int n, m;
char M[55][55];
string seq;
ii start, fin;
map<char, ii> mp;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int Dijkstra()
{
	int dist[n][m][55];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			for(int k = 0; k <= seq.size(); ++k)
				dist[i][j][k] = INF;
	priority_queue<pair<ii, ii>> pq;
	dist[start.first][start.second][0] = 0;
	pq.push({{0, 0}, {start.first, start.second}});
	while(pq.size())
	{
		ii cur = pq.top().second;
		ii info = pq.top().first;
		pq.pop();
		if(cur.first == fin.first && cur.second == fin.second) return -info.first;
		int pos = info.second;
		int w = -info.first;
		for(int i = 0; i < 4; ++i)
		{
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			if(nr < 0 || nc < 0 || nr >= n || nc >= m || M[nr][nc] == '#' || dist[nr][nc][pos] <= 1+w) continue;
			dist[nr][nc][pos] = 1+w;
			pq.push({{-(1+w), pos}, {nr, nc}});
		}
		if(pos < seq.size())
		{
			ii dir = mp[seq[pos]];
			int nr = cur.first + dir.first;
			int nc = cur.second + dir.second;
			if(nr < 0 || nc < 0 || nr >= n || nc >= m || M[nr][nc] == '#')
			{
				nr -= dir.first;
				nc -= dir.second;
			}
			if(dist[nr][nc][pos+1] <= w) continue;
			dist[nr][nc][pos+1] = w;
			pq.push({{-w, pos+1}, {nr, nc}});
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				cin >> M[i][j];
				if(M[i][j] == 'R')
					start = {i, j};
				else if(M[i][j] == 'E')
					fin = {i, j};
			}
		}
		cin >> seq;
		mp['L'] = {0, -1};
        mp['R'] = {0, 1};
        mp['U'] = {-1, 0};
        mp['D'] = {1, 0};
		cout << Dijkstra() << "\n";
	}
	return 0;
}