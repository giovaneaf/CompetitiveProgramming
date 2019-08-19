/*
https://www.spoj.com/problems/TAP2013I/
One way to do this is to binary search the answer and do a BFS with time waiting 
time x and check if it's possible to leave.
*/

#include <bits/stdc++.h>
 
#define MAXN 510
#define INF 1e9
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
int r, c;
 
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
 
int H[MAXN][MAXN];
int dist[MAXN][MAXN];
 
bool BFS(int t)
{	
	queue<pair<ii, int>> q;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			dist[i][j] = -1;
	dist[0][0] = 0;
	q.push({{0, 0}, 0});
	while(q.size())
	{
		int ar = q.front().first.first;
		int ac = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if(ar == r-1 and ac == c-1)
			return true;
		for(int i = 0; i < 4; ++i)
		{
			int nr = ar + dr[i];
			int nc = ac + dc[i];
			if(nr < 0 || nr >= r || nc < 0 || nc >= c || dist[nr][nc] != -1 || H[nr][nc] - t - d - 1 <= 0) continue;
			dist[nr][nc] = d+1;
			q.push({{nr, nc}, dist[nr][nc]});
		}
	}
  return false;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			cin >> H[i][j];
	if(!BFS(0))
	{
		cout << "-1\n";
	}
	else
	{
		int l = 0;
		int h = H[0][0]-1;
		while(h - l > 1)
		{
			int mid = (l+h)/2;
			if(BFS(mid))
				l = mid;
			else
				h = mid-1;
		}
		cout << (BFS(h) ? h : l) << "\n";
	}
	return 0;
}
