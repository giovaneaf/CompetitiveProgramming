#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector<int> pset;

void init_set(int n)
{
	pset.assign(n, 0);
	for(int i = 0; i < n; i++) pset[i] = i;
}

int find_set(int i)
{
	return pset[i] == i ? i : (pset[i] = find_set(pset[i]));
}

bool is_same_set(int i, int j)
{
	return find_set(i) == find_set(j);
}

void union_set(int i, int j)
{
	if(is_same_set(i, j)) return;
	pset[find_set(i)] = find_set(j);
		
}

int main()
{
	int N, M;
	while(scanf("%d %d", &N, &M) != EOF && N)
	{
		vector<tuple<int, int, int> > e;
		for(int i = 0; i < M; i++)
		{
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			e.push_back(make_tuple(w, a-1, b-1));
		}
		sort(e.begin(), e.end());
		int lowest = 0;
		init_set(N);
		int size = N;
		for(int i = 0; i < e.size(); i++)
		{
			if(size == 1)
				break;
			int a = get<1>(e[i]), b = get<2>(e[i]);
			if(not is_same_set(a, b))
			{
				int w = get<0>(e[i]);
				union_set(a, b);
				size--;
				lowest += w;
			}
		}
		int greater = 0;
		init_set(N);
		size = N;
		for(int i = e.size()-1; i > -1; i--)
		{
			if(size == 1)
				break;
			int a = get<1>(e[i]), b = get<2>(e[i]);
			if(not is_same_set(a, b))
			{
				int w = get<0>(e[i]);
				union_set(a, b);
				size--;
				greater += w;
			}
		}
		printf("%d\n", greater-lowest);
	}
	return 0;
}