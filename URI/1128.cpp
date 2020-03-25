#include <vector>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

bool Connected(int ind, vector<vector<int> >& v, int N)
{
	bool visited[N];
	memset(visited, false, sizeof(visited));
	stack<int> s;
	visited[ind] = true;
	s.push(ind);
	while(s.size())
	{
		int u = s.top();
		s.pop();
		for(int i = 0; i < v[u].size(); i++)
		{
			int w = v[u][i]; 
			if(!visited[w])
			{
				visited[w] = true;
				s.push(w);
			}
		}
	}
	for(int i = 0; i < N; i++)
	{
		if(!visited[i])
			return false;
	}
	return true;
}

int main()
{
	int N, M;
	while(cin >> N >> M && N != 0)
	{
		vector<vector<int> > v(N);
		for(int i = 0; i < M; i++)
		{
			int u, w, d;
			cin >> u >> w >> d;
			if(d == 2)
				v[w-1].push_back(u-1);
			v[u-1].push_back(w-1);
		}
		bool conn = true;
		for(int i = 0; i < N; i++)
		{
			if(!Connected(i, v, N))
			{
				conn = false;
				break;
			}
		}
		if(conn)
			cout << "1";
		else
			cout << "0";
		cout << endl;
	}
	return 0;
}