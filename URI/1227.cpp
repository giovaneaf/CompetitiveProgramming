#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N, A, B, C;

int dist(int idx, int dest, vector<vector<int> >& v, bool* visited)
{
	if(idx == dest)
		return 0;
	visited[idx] = true;
	int ans = 1000000000;
	for(int i = 0; i < v[idx].size(); i++)
	{
		if(!visited[v[idx][i]])
		{
			ans = min(ans, 1 + dist(v[idx][i], dest, v, visited));
		}
	}
	return ans;
}

int distBC(int idx, vector<vector<int> >& v, int* parent)
{
	if(idx == C)
		return 0;
	int ans = 1000000000;
	for(int i = 0; i < v[idx].size(); i++)
	{
		if(parent[v[idx][i]] == -1 && v[idx][i] != B)
		{
			parent[v[idx][i]] = idx;
			ans = min(ans, 1 + distBC(v[idx][i], v, parent));
		}
	}
	return ans;
}

int getw(int idx, bool* inPath, int N, vector<vector<int> >& v)
{
	queue<int> q;
	bool visited[N];
	for(int i = 0; i < N; i++)
		visited[i] = false;
	q.push(idx);
	while(q.size())
	{
		int u = q.front();
		visited[u] = true;
		q.pop();
		for(int i = 0; i < v[u].size(); i++)
		{
			if(!visited[v[u][i]])
			{
				if(inPath[v[u][i]])
					return v[u][i];
				q.push(v[u][i]);
			}
		}
	}
}

int main()
{
	while(scanf("%d %d %d %d", &N, &A, &B, &C) != EOF)
	{
		A--, B--, C--;
		vector<vector<int> > v(N);
		for(int i = 0; i < N-1; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			a--, b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int parent[N];
		for(int i = 0; i < N; i++)
			parent[i] = -1;
		int lBC = distBC(B, v, parent);
		bool inPath[N];
		for(int i = 0; i < N; i++)
			inPath[i] = false;
		int node = C;
		while(node != -1)
		{
			inPath[node] = true;
			node = parent[node];
		}
		int w = A;
		if(inPath[A])
			w = A;
		else
			w = getw(A, inPath, N, v);
		for(int i = 0; i < N; i++)
			inPath[i] = false;
		int lw = dist(w, C, v, inPath);
		printf("%.6lf\n", ((double) lw)/lBC);
	}
	return 0;
}