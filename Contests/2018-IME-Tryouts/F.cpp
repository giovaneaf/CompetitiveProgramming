// Thinking reverse in this problem would help because in the end
// the graph will be totally disconnected, so you can try adding
// edges from last to start and checking if this edge will create
// a cycle, if it does then this edge doesn't create another connected
// component. A good data structure for finding cycles is union find.
// This data structure is related with Kruskal's Minimum Spanning Tree(MST)
// algorithm, so will let the link for this algorithm too.
// Time Complexity: O(m*log*(n)) // for each edge check if it create a cycle

// Union-Find data structure: https://www.geeksforgeeks.org/union-find/
// Kruskal's algorithm: https://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/ 

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<int> pset;

int n, m;

void initSet() 
{
	pset.assign(n, 0);
	for(int i = 0; i < n; ++i) pset[i] = i;
}

int findSet(int i) 
{
	return pset[i] == i ? i : (pset[i] = findSet(pset[i]));
}

bool isSameSet(int i, int j) 
{
	return findSet(i) == findSet(j);
}

void unionSet(int i, int j) 
{
	if(isSameSet(i, j)) return;
	pset[findSet(i)] = findSet(j);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vector<ii> e(m);
		for(int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			e[i] = {a, b};
		}
		vector<int> order(m);
		for(int i = 0; i < m; ++i)
		{
			cin >> order[i];
			order[i]--;
		}
		vector<int> ans(m);
		ans[m-1] = n;
		initSet();
		for(int i = m-1; i > 0; --i)
		{
			ans[i-1] = ans[i];
			int u = e[order[i]].first;
			int v = e[order[i]].second;
			if(!isSameSet(u, v))
			{
				ans[i-1]--;
				unionSet(u, v);
			}
		}
		for(int i = 0; i < m; ++i)
		{
			cout << ans[i] << "\n";
		}
	}
	return 0;
}