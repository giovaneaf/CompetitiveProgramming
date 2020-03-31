/*
Compute area union of rectangles in O(n*log(n))
Tested in problem NKMARS on SPOJ
*/

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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000009
 
int n;

struct line
{
	int x, y0, y1, val;	
	bool operator< (const line& l) { return x < l.x; }
};

struct seg
{
	ll val, len;
	int cnt;
};

int y[MAXN];
int sy[MAXN];
seg st[4*MAXN];
ii v[MAXN];
int a, b, c, d;
int sz;
line vl[MAXN];

void initST(int cur, int l, int r)
{
	if(l == r)
	{
		st[cur].val = st[cur].cnt = 0;
		st[cur].len = y[r+1]-y[r];
		return ;
	}
	int lc, rc, mid;
	mid = (l+r)>>1;
	lc = 2*cur+1;
	rc = lc+1;
	initST(lc, l, mid); initST(rc, mid+1, r);
	st[cur].val = st[cur].cnt = 0;
	st[cur].len = st[lc].len + st[rc].len;
}

inline ll ask(int node)
{
	if(st[node].cnt) return st[node].len;
	return st[node].val;
}

void updateST(int cur, int l, int r, int ql, int qr, int val)
{
	int lc, rc, mid;
	mid = (l+r)>>1;
	lc = 2*cur+1;
	rc = lc+1;
	if(ql > r || qr < l) return ;
	if(ql <= l && r <= qr)
	{
		st[cur].cnt += val;
		return ;
	}
	updateST(lc, l, mid, ql, qr, val); updateST(rc, mid+1, r, ql, qr, val);
	st[cur].val = ask(lc) + ask(rc);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n)
	{
		for(int i = 0; i < 2*n; i += 2)
		{
			cin >> a >> b >> c >> d;
			v[i].fst = min(a, c); v[i].snd = min(b, d);
			v[i+1].fst = max(a, c); v[i+1].snd = max(b, d);
			sy[i] = b; sy[i+1] = d;
		}
		sort(sy, sy+2*n);
		map<int, int> mm;
		sz = 0;
		FOR(i, 0, 2*n)
		{
			if(mm.find(sy[i]) == mm.end()) 
			{
				y[sz] = sy[i];
				mm[sy[i]] = sz++;
			}
		}
		int y0, y1;
		for(int i = 0; i < 2*n; i += 2)
		{
			y0 = mm[v[i].snd]; y1 = mm[v[i+1].snd];
			vl[i].x = v[i].fst; vl[i].y0 = y0; vl[i].y1 = y1-1; vl[i].val = 1;
			vl[i+1].x = v[i+1].fst; vl[i+1].y0 = y0; vl[i+1].y1 = y1-1; vl[i+1].val = -1;
		}
		sort(vl, vl+2*n);
		initST(0, 0, sz-2);
		ll lastX = vl[0].x;
		ll area = 0LL;
		ll curX;
		FOR(i, 0, 2*n)
		{
			curX = vl[i].x;
			if(curX > lastX)
			{
				area += (curX-lastX)*ask(0);
			}
			updateST(0, 0, sz-2, vl[i].y0, vl[i].y1, vl[i].val);
			lastX = curX;
		}
		printf("%lld\n", area);
	}
	return 0;
}