#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <string.h>
#include <map>

using namespace std;

int Dijkstra(int src, int dest, vector<vector<tuple<int, int, char> > >& v, int N)
{
	int dist[N][26];
	bool visited[N][26];
	memset(dist, -1, sizeof(dist));
	memset(visited, false, sizeof(visited));
	priority_queue<tuple<int, int, char>, vector<tuple<int, int, char> >, greater<tuple<int, int, char> > > pq;
	for(int i = 0; i < 26; i++)
		dist[src][i] = 0;
	pq.push(make_tuple(0, src, 'a'));
	while(pq.size())
	{
		int u = get<1>(pq.top());
		char c = get<2>(pq.top());
		pq.pop();
		if(!visited[u][c-'a'])
		{
			if(u == dest)
				return dist[dest][c-'a'];
			if(u == src)
				for(int i = 0; i < 26; i++)
					visited[u][i] = true;
			else
				visited[u][c-'a'] = true;
			for(int i = 0; i < v[u].size(); i++)
			{
				int s = get<0>(v[u][i]);
				int w = get<1>(v[u][i]);
				int ch = get<2>(v[u][i]);
				if(u != src && ch == c)
					continue;
				if(dist[s][ch-'a'] == -1 || dist[s][ch-'a'] > dist[u][c-'a'] + w)
				{
					dist[s][ch-'a'] = dist[u][c-'a'] + w;
					pq.push(make_tuple(dist[s][ch-'a'], s, ch));
				}
			}
		}
	}
	return -1;
}

int main()
{
	int N;
	while(cin >> N && N)
	{
		int index = 0;
		string src, dest;
		cin >> src >> dest;
		map<string, int> m;
		vector<vector<tuple<int, int, char> > > v(2*N);
		for(int i = 0; i < N; i++)
		{
			int ia, ib;
			string a, b, c;
			cin >> a >> b >> c;
			if(m.find(a) == m.end())
			{
				ia = m[a] = index;
				index++;
			}
			else
				ia = m[a];
			if(m.find(b) == m.end())
			{
				ib = m[b] = index;
				index++;
			}
			else
				ib = m[b];
			v[ia].push_back(make_tuple(ib, c.size(), c[0]));
			v[ib].push_back(make_tuple(ia, c.size(), c[0]));
		}
		int is, id;
		if(m.find(src) != m.end() && m.find(dest) != m.end())
		{
			is = m[src];
			id = m[dest];
			int ans = Dijkstra(is, id, v, 2*N);
			if(ans == -1)
			{
				printf("impossivel\n");
			}
			else
			{
				printf("%d\n", ans);
			}
		}
		else
			printf("impossivel\n");
	}
	return 0;
}