#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef struct Edge
{
	int x, y;
} Edge;

bool notCycle(int orig, int bridge, vector< vector<int> >& v, int C)
{
	bool visited[C];
	memset(visited, false, sizeof(visited));
	visited[orig] = true;
	queue< pair<int, int> > q;
	q.push(make_pair(bridge, orig));
	while(q.size())
	{
		int u = q.front().first;
		int introd = q.front().second;
		q.pop();
		if(!visited[u])
		{
			visited[u] = true;
			vector<int>::iterator it;
			for(it = v[u].begin(); it != v[u].end(); it++)
			{
				if(*it == introd)
					continue;
				if(*it == orig)
					return false;
				q.push(make_pair(*it,u));
			}
		}
	}
	return true;
}

int main()
{
	int C, P;
	while(cin >> C >> P)
	{
		int i;
		vector< vector<int> > v(C);
		Edge e[P];
		for(i = 0; i < P; i++)
		{
			int a, b;
			cin >> a >> b;
			e[i].x = a-1;
			e[i].y = b-1;
			v[a-1].push_back(b-1);
			v[b-1].push_back(a-1);
		}
		int bwnc = 0;
		for(i = 0; i < P; i++)
		{
			if(notCycle(e[i].x, e[i].y, v, C))
				bwnc++;
		}
		cout << bwnc << endl;
	}
	return 0;
}