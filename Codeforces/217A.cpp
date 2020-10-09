#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define ITER 10000000

#define DEBUG 0

void DFS(int cur, vb& seen, vi* adj)
{
	seen[cur] = true;
	for(int& u : adj[cur])
	{
		if(!seen[u])
		{
			DFS(u, seen, adj);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		vector<ii> v(n);
		vi adj[n];
		FOR(i, 0, n) cin >> v[i].fst >> v[i].snd;
		FOR(i, 0, n)
		{
			FOR(j, i+1, n)
			{
				if(v[i].fst == v[j].fst || v[i].snd == v[j].snd)
				{
					adj[i].emplace_back(j);
					adj[j].emplace_back(i);
				}
			}
		}
		int cc = 0;
		vb seen(n, false);
		FOR(i, 0, n)
		{
			if(!seen[i])
			{
				DFS(i, seen, adj);
				cc++;
			}
		}
		printf("%d\n", cc-1);
	}
	return 0;
}
