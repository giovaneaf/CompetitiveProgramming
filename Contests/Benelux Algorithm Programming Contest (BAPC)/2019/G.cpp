#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 410
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

struct VerticalSweep {
	int x, y1, y2, cmp; // cmp to remove lines before add when x is the same (-1 is end and 1 is start)
	VerticalSweep(int x = 0, int y1 = 0, int y2 = 0, int cmp = 1) : x(x), y1(y1), y2(y2), cmp(cmp) {}
	bool operator< (const VerticalSweep& p) const 
	{
		if(x != p.x)
			return x < p.x;
		return cmp < p.cmp;
	}
};

struct Interval {
	int ymin, ymax, cnt, val;
	Interval(int ymin = 0, int ymax = 0, int cnt = 0, int val = 0) : ymin(ymin), ymax(ymax), cnt(cnt), val(val) {}
};

int n, m, k;
// points of rectangle pt[i][0] means bottom left corner and pt[i][1] means top right corner
Point pt[MAXN][2];
Interval st[8*MAXN];
VerticalSweep v[2*MAXN];
int ysorted[2*MAXN];
Interval myInt[2*MAXN];

void init(int cur, int l, int r)
{
    int left = 2*cur+1;
    int right = 2*cur+2;
    if(l == r)
    {
        st[cur] = myInt[l];
		return ;
    }
    int mid = (l + r) >> 1;
    init(left, l, mid);
    init(right, mid+1, r);
    st[cur] = {st[left].ymin, st[right].ymax, 0, 0};
}

int ask(int cur)
{
	if(st[cur].cnt)
		return st[cur].ymax-st[cur].ymin;
	return st[cur].val;
}

inline int query()
{
	return ask(0);
}

void update(int cur, int l, int r, int ql, int qr, int val)
{
    int left = 2*cur+1;
    int right = 2*cur+2;
    if(ql > st[cur].ymax || qr < st[cur].ymin) return ;
    if(st[cur].ymin >= ql && st[cur].ymax <= qr)
    {
        st[cur].cnt += val;
		return ;
    }
    int mid = (l + r) >> 1;
    update(left, l, mid, ql, qr, val);
    update(right, mid+1, r, ql, qr, val);
    st[cur].val = ask(left) + ask(right);
}

// find union area of n rectangles that area stored from pt[0] to pt[n-1]
ll unionAreaRect(int n)
{
	if(n == 0) return 0LL;
	memset(st, 0, sizeof(st));
	FOR(i, 0, n)
	{
		int ymin = pt[i][0].y;
		int ymax = pt[i][1].y;
		
		v[2*i] = {pt[i][0].x, ymin, ymax, 1};
		v[2*i+1] = {pt[i][1].x, ymin, ymax, -1};
		
		ysorted[2*i] = ymin;
		ysorted[2*i+1] = ymax;
	}
	sort(v, v + 2*n);
	sort(ysorted, ysorted+2*n);
	map<int, int> mm;
	int cur = 0;
	FOR(i, 0, 2*n)
	{
		if(mm.find(ysorted[i]) == mm.end())
		{
			mm[ysorted[i]] = cur++;
		}
	}
	auto prev = mm.begin();
	auto it = mm.begin();
	cur = 0;
	for(it++; it != mm.end(); ++it)
	{
		myInt[cur].ymin = prev->fst;
		myInt[cur].ymax = it->fst;
		cur++;
		prev++;
	}
	int last = v[0].x;
	ll area = 0LL;
	init(0, 0, cur-1);
	FOR(i, 0, 2*n)
	{
		int curX = v[i].x;
		area += ((ll) (curX-last))*((ll) query());
		update(0, 0, cur-1, v[i].y1, v[i].y2, v[i].cmp);
		last = curX;
	}
	return area;
}

string M[30];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> k)
	{
		int cnt = 0;
		int ni, j;
		FOR(i, 0, n)
		{
			cin >> M[i];
			ni = n-1-i;
			FOR(j, 0, m)
			{
				if(M[i][j] == '#')
				{
					pt[cnt][0] = {j-k, ni-k};
					pt[cnt][1] = {j+k+1, ni+k+1};
					cnt++;
				}
			}
		}
		printf("%lld\n", unionAreaRect(cnt));
	}
	return 0;
}