#include <iostream>
#include <stdio.h>
#include <queue>
#include <ctype.h>
#include <tuple>
#include <map>

#define INF 1000000000

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char M[100][100];

using namespace std;

typedef struct st st;

struct st
{
	bool visited;
	char ch;
	bool operator<(const st& s) const
	{
		return ch < s.ch;
	}
};

int BFS(int N)
{
	queue<tuple<int, int, vector<st> > > q;
	map<tuple<int, int, vector<st> >, int> dist;
	vector<st> vc(10);
	for(int i = 0; i < 10; i++)
		vc[i].visited = false;
	int up = (toupper(M[0][0])) - 'A';
	vc[up].visited = true;
	vc[up].ch = M[0][0];
	dist[make_tuple(0, 0, vc)] = 0;
	q.push(make_tuple(0, 0, vc));
	while(q.size())
	{
		int row = get<0>(q.front());
		int col = get<1>(q.front());
		if(row == N-1 && col == N-1)
			return dist[q.front()];
		vector<st> v = get<2>(q.front());
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nr = row + dx[i];
			int nc = col + dy[i];
			if(nr >= 0 && nr < N && nc >= 0 && nc < N && dist.find(make_tuple(nr, nc, v)) == dist.end())
			{
				up = (toupper(M[nr][nc])) - 'A';
				if(!v[up].visited)
				{
					vector<st> aux;
					aux = v;
					aux[up].visited = true;
					aux[up].ch = M[nr][nc];
					dist[make_tuple(nr, nc, aux)] = dist[make_tuple(row, col, v)] + 1;
					q.push(make_tuple(nr, nc, aux));
				}
				else if(v[up].ch == M[nr][nc])
				{
					dist[make_tuple(nr, nc, v)] = dist[make_tuple(row, col, v)] + 1;
					q.push(make_tuple(nr, nc, v));
				}
			}
		}
	}
	return INF;
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf(" %c", &M[i][j]);
		}
	}
	int ans = BFS(N);
	if(ans == INF)
		printf("-1\n");
	else
		printf("%d\n", ans+1);
}