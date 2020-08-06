#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0

int n, m, x;

struct UnionFind
{
	vi pset;
	vi szset; // size of the set
	UnionFind(int n) 
	{
		pset.assign(n, 0);
		szset.assign(n, 1);
		FOR(i, 0, n) pset[i] = i;
	}
	int findSet(int i)
	{
		return (pset[i] == i ? i : (pset[i] = findSet(pset[i])));
	}
	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j)
	{
		if(isSameSet(i, j)) return;
		szset[findSet(j)] += szset[findSet(i)];
		pset[findSet(i)] = findSet(j);
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		UnionFind uf(n);
		map<int, vi> mm;
		FOR(i, 0, n)
		{
			cin >> m;
			FOR(j, 0, m)
			{
				cin >> x;
				mm[x].emplace_back(i);
			}
		}
		vector<pair<ii, int>> ans(n-1);
		int sz = 0;
		for(auto it = mm.begin(); it != mm.end(); ++it)
		{
			int u = it->snd[0], v;
			FOR(i, 1, it->snd.size())
			{
				v = it->snd[i];
				if(!uf.isSameSet(u, v))
				{
					uf.unionSet(u, v);
					ans[sz++] = mp(mp(u, v), it->fst);
					if(sz == n-1) break;
				}
			}
			if(sz == n-1) break;
		}
		if(sz == n-1)
		{
			FOR(i, 0, sz)
			{
				printf("%d %d %d\n", ans[i].fst.fst+1, ans[i].fst.snd+1, ans[i].snd);
			}
		}
		else
		{
			printf("impossible\n");
		}
	}
	return 0;
}