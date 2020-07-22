#include <bits/stdc++.h>
#define MAXN 5010
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
int n, m;
 
int solve(int cur, vi* adj, bitset<MAXN>& seen)
{
	seen.set(cur);
	int ans = 0;
	for(int i = 0; i < adj[cur].size(); ++i)
	{
		int u = adj[cur][i];
		if(!seen[u])
			ans += solve(u, adj, seen);
	}
	return ans + 1;
}
 
int main()
{
	int a, b;
    while(cin >> a >> b >> n >> m)
	{
		vi adj[n];
		vi radj[n];
		while(m--)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			radj[y].push_back(x);
		}
		int succ[n] = {};
		int pred[n] = {};
		int A = 0;
		int B = 0;
		int C = 0;
		bitset<MAXN> seen;
		for(int i = 0; i < n; ++i)
		{
			seen.reset();
			succ[i] = solve(i, adj, seen) - 1;
			if(succ[i] >= n-a)
				A++;
			if(succ[i] >= n-b)
				B++;
			seen.reset();
			pred[i] = solve(i, radj, seen) - 1;
			if(pred[i] >= b)
				C++;
		}
		cout << A << "\n" << B << "\n" << C << "\n";
	}
    return 0;
}