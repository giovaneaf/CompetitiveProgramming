#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;


int DFS(int a, vector<vector<int> >& v, vector<int>& age, bool* visited, bool same)
{
	visited[a] = true;
	int minAge;
	if(same)
		minAge = 101;
	else
		minAge = age[a];
	for(int i = 0; i < v[a].size(); i++)
	{
		if(!visited[v[a][i]])
		{
			minAge = min(minAge, DFS(v[a][i], v, age, visited, false));
		}
	}
	return minAge;
}

int main()
{
	int N, M, I;
	while(scanf("%d %d %d", &N, &M, &I) != EOF)
	{
		vector<int> age(N);
		vector<int> index(N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &age[i]);
			index[i] = i;
		}
		vector<vector<int> > g(N);
		for(int i = 0; i < M; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			a--, b--;
			g[b].push_back(a);
		}
		for(int i = 0; i < I; i++)
		{
			char ch;
			scanf(" %c", &ch);
			if(ch == 'T')
			{
				int a, b;
				scanf("%d %d", &a, &b);
				a--, b--;
				swap(age[index[a]], age[index[b]]);
				swap(index[a], index[b]);
			}
			else
			{
				int a;
				scanf("%d", &a);
				a--;
				if(g[index[a]].size() == 0)
					printf("*\n");
				else
				{
					bool visited[N];
					memset(visited, false, sizeof(visited));
					printf("%d\n", DFS(index[a], g, age, visited, true));
				}
			}
		}
	}
}