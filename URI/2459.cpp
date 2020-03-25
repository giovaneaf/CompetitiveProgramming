#include <vector>
#include <tuple>
#include <algorithm>
#include <stdio.h>

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
	int N, F, R;
	scanf("%d %d %d", &N, &F, &R);
	vector<tuple<int, int, int> > e;
	for(int i = 0; i < F; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		e.push_back(make_tuple(w, a-1, b-1));
	}
	sort(e.begin(), e.end());
	for(int i = 0; i < R; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		e.push_back(make_tuple(w, a-1, b-1));
	}
	sort(e.begin()+F, e.end());
	int cost = 0;
	init_set(N);
	int size = N;
	for(int i = 0; i < e.size(); i++)
	{
		if(size == 1)
			break;
		int w = get<0>(e[i]), a = get<1>(e[i]), b = get<2>(e[i]);
		if(not is_same_set(a, b))
		{
			union_set(a, b);
			size--;
			cost += w;
		}
	}
	printf("%d\n", cost);
	return 0;
}