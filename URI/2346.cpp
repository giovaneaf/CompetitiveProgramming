#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

int main()
{
	int N, M, A, B;
	cin >> N >> M >> A >> B;
	set<int> adj[100001];
	for(int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	set<pair<int, int>> s;
	for(int i = 1; i <= N; i++)
	{
		s.insert(make_pair(adj[i].size(), i));
	}
	while(s.size())
	{
		set<pair<int,int>>::iterator it = s.end();
		--it;
		int max = it->first;
		int id = it->second;
		bool end = true;
		if(max > N-1-B)
		{
			end = false;
			int u = it->second;
			s.erase(it);
			for(set<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it)
			{
				int index = *it;
				s.erase(make_pair(adj[index].size(), index));
				adj[index].erase(u);
				s.insert(make_pair(adj[index].size(), index));
			}
			N--;
		}
		if(s.size() == 0) break;
		int min = s.begin()->first;
		id = s.begin()->second;
		if(min < A)
		{
			end = false;
			int u = s.begin()->second;
			s.erase(s.begin());
			for(set<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it)
			{
				int index = *it;
				s.erase(make_pair(adj[index].size(), index));
				adj[index].erase(u);
				s.insert(make_pair(adj[index].size(), index));
			}
			N--;
		}
		if(end)
			break;
	}
	cout << s.size() << endl;
	return 0;
}