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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

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

int T, n, k;
int a[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		cin >> n >> k;
		set<int> s;
		UnionFind uf(n);
		FOR(i, 0, n)
		{
			cin >> a[i];
		}
		FOR(i, 0, n)
		{
			FOR(j, i+1, n)
			{
				if(abs(a[i] - a[j]) <= k) uf.unionSet(i, j);
			}
		}
		FOR(i, 0, n)
		{
			s.insert(uf.findSet(i));
		}
		int ans = s.size();
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
