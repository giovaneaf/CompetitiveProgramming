/*
http://codeforces.com/group/kZPk3ZTzR5/contest/101858/problem/F
For this problem it's easy to think in reverse order, think that Frieza is inserting edges in the graph in reverse order.
Then the initial graph has no edge and Frieza is adding edges inside the graph, initially the number of connected components
is equal n and each time we add an edge that do not form a cycle in the graph then the number of connected components is
reduced by one unit. One way to implement it efficiently is to use the Disjoint Set Union (DSU) data structure, a.k.a. as
Union Find DS to check if an edge adds cycle in the graph.
*/

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