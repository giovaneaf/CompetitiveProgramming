#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct point
{
	int r, c, index;
	bool operator< (point& p) const
	{
		return index < p.index;
	}
};

int n, m;
int rows, cols;
char M[110][110];
int bfstable[15][110][110];

point start;
point finish;

void BFS(int index, point p)
{
	bfstable[index][p.r][p.c] = 0;
	queue<pair<int, point>> q;
	q.push(mp(0, p));
	while(q.size())
	{
		int dist = q.front().first;
		p = q.front().second;
		q.pop();
		for(int i = 0; i < 4; ++i)
		{
			int nr = p.r + dr[i];
			int nc = p.c + dc[i];
			if(nr < 0 or nr >= rows or nc < 0 or nc >= cols) continue;
			if(bfstable[index][nr][nc] == -1 and M[nr][nc] != '#')
			{
				bfstable[index][nr][nc] = dist+1;
				point u = {nr, nc, -1};
				q.push(mp(bfstable[index][nr][nc], u));
			}
		}
	}
}

int main()
{
	while(cin >> n >> m)
	{
		cin >> cols >> rows;
		for(int i = 0; i < rows; ++i)
		{
			cin >> M[i];
		}
		vector<point> p;
		int index = 1;
		for(int i = 0; i < rows; ++i)
		{
			for(int j = 0; j < cols; ++j)
			{
				if(M[i][j] == 'S')
				{
					finish = {i, j, n+1};
				}
				else if(M[i][j] == 'R')
				{
					start = {i, j, 0};
				}
				else if(M[i][j] == '*')
				{
					p.push_back({i, j, index++});
				}
			}
		}
		for(int i = 0; i < rows; ++i)
		{
			for(int j = 0; j < cols; ++j)
			{
				for(int k = 0; k < 10; ++k)
				{
					bfstable[k][i][j] = -1;
				}
			}
		}
		BFS(0, start);
		if(bfstable[0][finish.r][finish.c] == -1 or bfstable[0][finish.r][finish.c] > m)
		{
			printf("-1\n");
			continue;
		}
		for(int i = 0; i < p.size(); ++i)
		{
			BFS(i+1, p[i]);
		}
		int ans = 0;
		do
		{
			int times = 0;
			int energy = 0;
			point cur = start;
			while(times < p.size() and bfstable[cur.index][p[times].r][p[times].c] > -1 and energy + bfstable[cur.index][p[times].r][p[times].c] < m)
			{
				energy += bfstable[cur.index][p[times].r][p[times].c];
				cur = p[times];
				int newEnergy = energy + bfstable[cur.index][finish.r][finish.c];
				if(newEnergy > m or bfstable[cur.index][finish.r][finish.c] == -1) break;
				times++;
			}
			ans = max(ans, times);
			if(ans == n) break;
		} while(next_permutation(p.begin(), p.end()));
		printf("%d\n", ans);
	}
}