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
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

struct vline
{
	int x, ymin, ymax, open, id;
	bool operator< (const vline& v)
	{
		if(x == v.x) return open < v.open;
		return x < v.x;
	}
};

ll mod = 1000000007LL;
int T, n;
vline v[2*MAXN];
int x, y, xx, yy;
int ans[MAXN];
int yyy[2*MAXN];
stack<ii> st[8*MAXN];
bool dead[MAXN];
int t;
ii val;

void update(int cur, int l, int r, int ql, int qr, int x)
{
	if(l > qr || ql > r) return ;
	if(st[cur].size())
	{
		while(st[cur].size() && dead[st[cur].top().fst]) st[cur].pop();
		if(st[cur].size() && st[cur].top().snd > val.snd) val = st[cur].top();
	}
	if(ql <= l && r <= qr) // fully on range
	{
		st[cur].push(mp(x, t++));
		return ;
	}
	int mid;
	mid = (l+r)/2;
	update(2*cur+1, l, mid, ql, qr, x);
	update(2*cur+2, mid+1, r, ql, qr, x);
}

inline bool inside(int a, int b, int c)
{
	if(a <= b && b <= c) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, 8*n)
		{
			while(st[i].size()) st[i].pop();
		}
		memset(dead, false, sizeof(dead));
		map<int, int> mm;
		int sz = 0;
		FOR(i, 0, n)
		{
			cin >> x >> y >> xx >> yy;
			yyy[sz] = y;
			v[sz++] = {x, y, yy, 1, i};
			yyy[sz] = yy;
			v[sz++] = {xx, y, yy, 0, i};
		}
		sort(yyy, yyy+sz);
		sort(v, v+sz);
		sz = 0;
		FOR(i, 0, 2*n)
		{
			if(mm.find(yyy[i]) == mm.end())
				mm[yyy[i]] = sz++;
		}
		t = 0;
		FOR(i, 0, 2*n)
		{
			v[i].ymin = mm[v[i].ymin];
			v[i].ymax = mm[v[i].ymax];
			if(v[i].open == 1)
			{
				val = mp(-1, -1);
				update(0, 0, sz-1, v[i].ymin, v[i].ymax, v[i].id);
				ans[v[i].id] = val.fst;
			}
			else
			{
				dead[v[i].id] = true;
			}
		}
		FOR(i, 0, n)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
