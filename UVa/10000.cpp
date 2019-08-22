/*
You can use dynamic programming to solve this problem.
dp(i) store a pair that represents the pair (maximum distance from i to any leaf, index of the leaf)
this second component of pair is used in case of ties of the maximum distance.
You can update the value of dp(i) just by checking all neighbors of vertex i and get the child that has
the higher distance or the lower index in case of ties.
This works because this is a Directed Acyclic Graph (DAG) so you don't need to worry about cycles.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, k;
ii memo[110];

ii DFS(int cur, vi* adj)
{
	if(memo[cur].fst == -1)
	{
		if((int) adj[cur].size() == 0)
		{
			memo[cur] = mp(0, cur);
		}
		else
		{
			ii p = mp(-1, INF);
			for(int u : adj[cur])
			{
				ii rc = DFS(u, adj);
				rc.fst++;
				if(rc.fst > p.fst || (rc.fst == p.fst && rc.snd < p.snd))
				{
					p = rc;
				}
			}
			memo[cur] = p;
		}
	}
	return memo[cur];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while(cin >> n && n)
	{
		FOR(i, 0, n) memo[i] = mp(-1, INF);
		vi adj[n];
		int src;
		cin >> src;
		src--;
		int a, b;
		while(cin >> a >> b)
		{
			if(a == 0 && b == 0) break;
			a--, b--;
			adj[a].emplace_back(b);
		}
		ii ans = DFS(src, adj);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", t++, src+1, ans.fst, ans.snd+1);
	}
    return 0;
}
