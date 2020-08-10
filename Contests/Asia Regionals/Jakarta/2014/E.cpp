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

int T, n, q;
int p[MAXN];
int in[MAXN];
pair<char, ii> query[MAXN];
string ans[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		printf("Case #%d:\n", t+1);
		cin >> n >> q;
		FOR(i, 0, n)
		{			
			cin >> p[i];
			p[i]--;
			in[i] = (p[i] == -1 ? 0 : 1);
		}
		FOR(i, 0, q)
		{
			cin >> query[i].fst;
			if(query[i].fst == 'C')
			{
				cin >> query[i].snd.fst;
				query[i].snd.fst--;
				in[query[i].snd.fst]--;
			}
			else
			{
				cin >> query[i].snd.fst >> query[i].snd.snd;
				query[i].snd.fst--; query[i].snd.snd--;
			}
		}
		UnionFind uf(n);
		FOR(i, 0, n)
		{
			if(in[i] == 1) uf.unionSet(i, p[i]);
		}
		int len = 0;
		RFOR(i, q-1, 0)
		{
			if(query[i].fst == 'C')
			{
				in[query[i].snd.fst]++;
				if(in[query[i].snd.fst] == 1) uf.unionSet(query[i].snd.fst, p[query[i].snd.fst]);
			}
			else
			{
				ans[len++] =  uf.isSameSet(query[i].snd.fst, query[i].snd.snd) ? "YES" : "NO";
			}
		}
		RFOR(i, len-1, 0)
		{
			printf("%s\n", ans[i].c_str());
		}
	}
	return 0;
}
