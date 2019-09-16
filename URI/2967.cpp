#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXN 10010
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

struct Point {
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};


// Struct to sweep from left to right
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

// Struct to store intervals inside "seg tree"
struct Interval {
	int ymin, ymax, cnt, val;
	Interval(int ymin = 0, int ymax = 0, int cnt = 0, int val = 0) : ymin(ymin), ymax(ymax), cnt(cnt), val(val) {}
};

int n, P;
Point pt[MAXN][2];
Point rect[2];
Interval st[8*MAXN];
ll totArea;
VerticalSweep v[2*MAXN];
int ysorted[2*MAXN];
Interval myInt[2*MAXN];

// Start interval/seg tree
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
	if(st[cur].cnt) // interval is active (return all)
		return st[cur].ymax-st[cur].ymin;
	return st[cur].val; // interval is inactive, return child values
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
    if(st[cur].ymin >= ql && st[cur].ymax <= qr) // fully in range
    {
        st[cur].cnt += val;	// update current interval (set active or inactive)
		return ;
    }
    int mid = (l + r) >> 1;
    update(left, l, mid, ql, qr, val);
    update(right, mid+1, r, ql, qr, val);
    st[cur].val = ask(left) + ask(right); // update child range to father
}

bool can(int mid) // check if it's possible to add mid value
{
	memset(st, 0, sizeof(st)); // reset seg tree
	FOR(i, 0, n) // compute rectangle range
	{
		int ymin = max(pt[i][0].y-mid, rect[0].y);
		int ymax = min(pt[i][1].y+mid, rect[1].y);
		
		v[2*i] = {max(pt[i][0].x-mid, rect[0].x), ymin, ymax, 1};
		v[2*i+1] = {min(pt[i][1].x+mid, rect[1].x), ymin, ymax, -1};
		
		// store possible y values
		ysorted[2*i] = ymin;
		ysorted[2*i+1] = ymax;
	}
	sort(v, v + 2*n); //sorted by x
	sort(ysorted, ysorted+2*n); //sort y
	map<int, int> mm;
	int cur = 0;
	FOR(i, 0, 2*n)
	{
		if(mm.find(ysorted[i]) == mm.end()) // keep track of possible y values
		{
			mm[ysorted[i]] = cur++;
		}
	}
	auto prev = mm.begin();
	auto it = mm.begin();
	cur = 0;
	for(it++; it != mm.end(); ++it)
	{
		// add this possible intervals in interval tree
		myInt[cur].ymin = prev->fst;
		myInt[cur].ymax = it->fst;
		cur++;
		prev++;
	}
	// sweep from left to right (by x coordinate)
	int last = v[0].x;
	ll area = 0LL;
	init(0, 0, cur-1); // init seg tree values (ymin and ymax)
	FOR(i, 0, 2*n)
	{
		int curX = v[i].x;
		area += ((ll) (curX-last))*((ll) query()); // compute area covered
		update(0, 0, cur-1, v[i].y1, v[i].y2, v[i].cmp); // update interval tree in range [y1, y2]
		last = curX;
	}
	return (area*100.0/totArea) >= P; // check if it's possible
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n)
		{
			cin >> pt[i][0].x >> pt[i][0].y;
			cin >> pt[i][1].x >> pt[i][1].y;
			if(pt[i][0].x > pt[i][1].x || (pt[i][0].x == pt[i][1].x && pt[i][0].y > pt[i][1].y))
			{
				swap(pt[i][0], pt[i][1]);
			}
		}
		cin >> P;
		cin >> rect[0].x >> rect[0].y >> rect[1].x >> rect[1].y;
		totArea = ((ll) (rect[1].x-rect[0].x))*((ll) (rect[1].y-rect[0].y));
		int l = 1;
		int h = 100010;
		while(h - l > 1)
		{
			int mid = (h+l)/2;
			if(can(mid))
				h = mid;
			else
				l = mid+1;
		}
		printf("%d\n", can(l) ? l : h);
	}
	return 0;
}