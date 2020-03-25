#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

typedef unsigned long long int ull;

vector<int> pset;

void initSet(int N)
{
    pset.assign(N,0);
    for (int i = 0; i < N; i++)
        pset[i] = i;
}
int findSet(int i)
{
    return (pset[i] == i)? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
    if (!isSameSet(i, j))
    {
        pset[findSet(i)] = findSet(j);
    }
}

int main()
{
	int M, N;
	while(cin >> M >> N && M != 0 && N != 0)
	{
		vector<tuple<double, int, int>> g;
		ull minimumCost = 0;
		for(int i = 0; i < N; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			g.emplace_back(make_tuple(w, u, v));
		}
		sort(g.begin(), g.end());
		initSet(M);
		int nSets = M;
		for(int i = 0; i < N; i++)
		{
			int w = get<0>(g[i]); int u = get<1>(g[i]); int v = get<2>(g[i]);
			if(!isSameSet(u, v))
			{
				unionSet(u, v);
				minimumCost += w;
				nSets--;
				if(nSets == 1)
					break;
			}
		}
		cout << minimumCost << endl;
	}
	return 0;
}