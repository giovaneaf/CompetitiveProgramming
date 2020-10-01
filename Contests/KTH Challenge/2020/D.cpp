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
#define MAXN 500010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

struct UnionFind
{
    vi pset;
    vi szset;   // size of the set
    UnionFind(int n) 
    {
        pset.assign(n, 0);
        szset.assign(n, 1);
        for(int i = 0; i < n; ++i) pset[i] = i;
    }
    int findSet(int i)
    {
        return (pset[i] == i ? i : (pset[i] = findSet(pset[i])));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)     // make set i point to j
    {
        if(isSameSet(i, j)) return;
        szset[findSet(j)] += szset[findSet(i)];
        pset[findSet(i)] = findSet(j);
    }
};

int n;
int v[MAXN];
int ans[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		UnionFind uf(n+5);
		set<int> s;
		FOR(i, 0, n) s.insert(i);
		FOR(i, 0, n)
		{			
			cin >> v[i];
			v[i]--;
			if(i == n-1)
			{
				ans[i] = *s.begin();
				break;
			}
			if(s.find(v[i]) != s.end() && !uf.isSameSet(i, v[i]))
			{
				uf.unionSet(i, v[i]);
				ans[i] = v[i];
				s.erase(v[i]);
			}
			else
			{
				for(auto it = s.begin(); it != s.end(); ++it)
				{
					if(!uf.isSameSet(i, *it))
					{
						uf.unionSet(i, *it);
						ans[i] = *it;
						s.erase(*it);
						break;
					}
				}
			}
		}
		printf("%d", ans[0]+1);
		FOR(i, 1, n) printf(" %d", ans[i]+1);
		putchar('\n');
	}
	return 0;
}