#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int N, M;

int color[10];

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

bool visited[5][6];

int ncolors(vvc& g)
{
	for(int i = 0; i < 10; i++)
		color[i] = 0;
	int colors = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(color[g[i][j] - '0'] == 0)
			{
				colors++;
				color[g[i][j] - '0']++;
			}
		}
	}
	return colors;
}

void fill(vvc& aux, int row, int col, int alpha, int beta)
{
	aux[row][col] = alpha;
	visited[row][col] = true;
	for(int i = 0; i < 4; i++)
	{
		int nr = row + di[i];
		int nc = col + dj[i];
		if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || (aux[nr][nc] != alpha && aux[nr][nc] != beta)) continue;
		fill(aux, nr, nc, alpha, beta);
	}
}

void print(vvc& g)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			printf("%c ", g[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}

int Astar(vvc& g)
{
	set<vvc> s;
	map<vvc, int> dist;
	dist[g] = 0;
	priority_queue<pair<int, vvc>, vector<pair<int, vvc> >, greater<pair<int, vvc> > > pq;
	pq.push(make_pair(0, g));
	while(pq.size())
	{
		g = pq.top().second;
		//print(g);
		pq.pop();
		int colors = ncolors(g);
		if(colors == 1)
			return dist[g];
		s.insert(g);
		bool colorused[10];
		for(int i = 0; i < 10; i++)
			colorused[i] = false;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(g[i][j] != g[0][0])
				{
					vvc aux = g;
					if(colorused[g[i][j] - '0']) continue;
					colorused[g[i][j] - '0'] = true;
					for(int row = 0; row < N; row++)
						for(int col = 0; col < M; col++)
							visited[row][col] = false;
					fill(aux, 0, 0, g[i][j], g[0][0]);
					if(s.find(aux) == s.end())
					{
						int dg = dist[g];
						if(dist.find(aux) == dist.end() || dist[aux] > dg + 1)
						{
							dist[aux] = dg + 1;
							pq.push(make_pair(dist[aux], aux));
						}
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d", &N, &M);
	vvc g(N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			char ch;
			cin >> ch;
			g[i].push_back(ch);
		}
	}
	printf("%d\n", Astar(g));
}