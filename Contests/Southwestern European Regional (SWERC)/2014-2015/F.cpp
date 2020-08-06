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
#define MAXN 50010
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

struct vline
{
	int x, ymin, ymax, val, id;
	bool operator< (const vline& l) const
	{
		if(x == l.x) return val < l.val;
		return x < l.x;
	}
};

int n;
map<int, int> mm;
UnionFind uf(MAXN);
int yv[2*MAXN];
vline v[2*MAXN];
set<int> st[8*MAXN];
set<int> lazy[8*MAXN];
int area[MAXN];
vb active;
int toErase[MAXN];
int sz;

void update(int cur, int l, int r, int ql, int qr, int x)
{
	if(l > qr || ql > r) return ;
	if((int) lazy[cur].size() > 0)
	{
		auto it = lazy[cur].begin();
		sz = 0;
		while(it != lazy[cur].end())
		{
			if(active[*it])
			{
				uf.unionSet(x, *it);
			}
			else
			{
				toErase[sz++] = *it;
			}
			it++;
		}
		FOR(i, 0, sz) 
		{
			lazy[cur].erase(toErase[i]);
		}
	}
	if(ql <= l && r <= qr) // fully on range
	{
		auto it = st[cur].begin();
		sz = 0;
		while(it != st[cur].end())
		{
			if(active[*it])
			{
				uf.unionSet(x, *it);
			}
			else
			{
				toErase[sz++] = *it;
			}
			it++;
		}
		FOR(i, 0, sz) 
		{
			st[cur].erase(toErase[i]);
		}
		st[cur].insert(x);
		lazy[cur].insert(x);
		return ;
	}
	int mid;
	mid = (l+r)/2;
	update(2*cur+1, l, mid, ql, qr, x);
	update(2*cur+2, mid+1, r, ql, qr, x);
	st[cur].insert(x);
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, 8*n)
		{			
			st[i].clear();
			lazy[i].clear();
		}
		mm.clear();
		active.assign(n, false);
		int x, y, w, h, pos, aux;
		aux = 0;
		FOR(i, 0, n)
		{
			cin >> x >> y >> w >> h;
			yv[aux] = y;
			v[aux++] = {x, y, y+h, 0, i};
			yv[aux] = y+h;
			v[aux++] = {x+w, y, y+h, 1, i};
			area[i] = w*h;
		}
		sort(v, v+2*n);
		sort(yv, yv+2*n);
		pos = 0;
		FOR(i, 0, 2*n)
		{
			if(mm.find(yv[i]) == mm.end())
				mm[yv[i]] = pos++;
		}
		FOR(i, 0, 2*n)
		{
			v[i].ymin = mm[v[i].ymin];
			v[i].ymax = mm[v[i].ymax];
			if(v[i].val == 0)
			{
				update(0, 0, pos-1, v[i].ymin, v[i].ymax, v[i].id);
			}
			active[v[i].id] = (v[i].val == 0 ? true : false);
		}
		map<int, int> mmm;
		int ans = 0;
		FOR(i, 0, n)
		{
			mmm[uf.findSet(i)] += area[i];
			ans = max(ans, mmm[uf.findSet(i)]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
