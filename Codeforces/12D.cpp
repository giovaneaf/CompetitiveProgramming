#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 500010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q;

struct lady
{
	int b, i, r;
	bool operator< (const lady& l) const
	{
		if(b != l.b) return b > l.b;
		else if(i != l.i) return i < l.i;
		else return r < l.r;
	}
};

set<ii> st[4*MAXN];
lady v[MAXN];
int vvi[MAXN];

void update(int cur, int l, int r, int x, ii p)
{
	if(l == r)
	{
		st[cur].insert(p);
		return ;
	}
	int mid = (l+r)>>1;
	int left = (cur<<1) + 1;
	int right = left + 1;
	if(x <= mid)
	{
		update(left, l, mid, x, p);
	}
	else
	{
		update(right, mid+1, r, x, p);
	}
	st[cur].insert(p);
}

bool query(int cur, int l, int r, int ql, int qr, int v)
{
	if(ql > r || qr < l) return false;
	if(ql <= l && r <= qr)
	{
		if(st[cur].size())
		{
			auto it = st[cur].end();
			it--;
			return it->first > v;
		}
		else
		{
			return false;
		}
	}
	int mid = (l+r)>>1;
	int left = (cur<<1) + 1;
	int right = left + 1;
	return query(left, l, mid, ql, qr, v) || query(right, mid+1, r, ql, qr, v);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int ans = 0;
	cin >> n;
	map<int, int> mi;
	FOR(i, 0, n)
	{
		cin >> v[i].b;
	}
	FOR(i, 0, n)
	{
		cin >> v[i].i;
		vvi[i] = v[i].i;
	}
	FOR(i, 0, n)
	{
		cin >> v[i].r;
	}
	sort(vvi, vvi+n);
	int cnti = 0;
	FOR(i, 0, n)
	{
		if(mi.find(vvi[i]) == mi.end())
			mi[vvi[i]] = cnti++;
	}
	sort(v, v+n);
	FOR(i, 0, n)
	{
		int pos = mi[v[i].i];
		bool dead = false;
		if(pos+1 <= n-1)
			dead = query(0, 0, n-1, pos+1, n-1, v[i].r);
		if(dead) ans++;
		else update(0, 0, n-1, pos, mp(v[i].r, i));
	}
	printf("%d\n", ans);
	return 0;
}