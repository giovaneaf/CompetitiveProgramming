#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 200010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q;

ii st[4*MAXN];
pair<int, ll> cnt[4*MAXN];
int v[MAXN];

void update(int cur, int l, int r, int x, int val)
{
	if(cur > 4*MAXN) return ;
	if(l == r)
	{
		st[cur] = mp(val, val);
		return ;
	}
	int mid = (l+r)>>1;
	int left = (cur<<1) + 1;
	int right = left + 1;
	if(x <= mid)
	{
		update(left, l, mid, x, val);
	}
	else
	{
		update(right, mid+1, r, x, val);
	}
	st[cur] = mp(min(st[left].fst, st[right].fst), max(st[left].snd, st[right].snd));
}

ii query(int cur, int l, int r, int ql, int qr)
{
	if(ql > qr) return mp(INF, 0);
	if(ql > r || qr < l) return mp(INF, 0);
	if(ql <= l && r <= qr)
	{
		return st[cur];
	}
	int mid = (l+r)>>1;
	int left = (cur<<1) + 1;
	int right = left + 1;
	ii lft = query(left, l, mid, ql, qr);
	ii rgt = query(right, mid+1, r, ql, qr);
	return mp(min(lft.fst, rgt.fst), max(lft.snd, rgt.snd));
}

void updates(int cur, int l, int r, int x, int val)
{
	if(cur > 4*MAXN) return;
	if(l == r)
	{
		cnt[cur] = mp(cnt[cur].fst + (val < 0 ? -1 : 1), cnt[cur].snd + val);
		return ;
	}
	int mid = (l+r)>>1;
	int left = (cur<<1) + 1;
	int right = left + 1;
	if(x <= mid)
	{
		updates(left, l, mid, x, val);
	}
	else
	{
		updates(right, mid+1, r, x, val);
	}
	cnt[cur] = mp(cnt[left].fst + cnt[right].fst, cnt[left].snd + cnt[right].snd);
}

pair<int, ll> querys(int cur, int l, int r, int ql, int qr)
{
	if(ql > qr) return mp(0, 0);
	if(ql > r || qr < l) return mp(0, 0);
	if(ql <= l && r <= qr)
	{
		return cnt[cur];
	}
	int mid = (l+r)>>1;
	int left = (cur<<1) + 1;
	int right = left + 1;
	pair<int, ll> lft = querys(left, l, mid, ql, qr);
	pair<int, ll> rgt = querys(right, mid+1, r, ql, qr);
	return mp(lft.fst+rgt.fst, lft.snd+rgt.snd);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> q;
		FOR(i, 0, 4*MAXN) cnt[i] = mp(0, 0);
		FOR(i, 0, n)
		{
			update(0, 0, n-1, i, i+1);
			updates(0, 0, n, i+1, i+1);
			v[i] = i+1;
		}
		FOR(i, 0, q)
		{
			int qt;
			cin >> qt;
			if(qt == 2)
			{
				ii p = query(0, 0, n-1, 0, n-1);
				if(p.fst == p.snd)
				{
					printf("0\n");
				}
				else
				{
					int mid = (p.fst+p.snd)>>1;
					pair<int, ll> sL = querys(0, 0, n, 0, mid);
					pair<int, ll> sR = querys(0, 0, n, mid+1, n);
					sR = mp(sR.fst-1, sR.snd-p.snd);
					ll ans = (ll) sL.first*p.snd;
					ans -= sL.snd;
					ans += sR.snd;
					ans -= (ll) sR.fst*p.fst;
					printf("%lld\n", ans);
				}
			}
			else
			{
				int u, x;
				cin >> u >> x;
				u--;
				update(0, 0, n-1, u, x);
				updates(0, 0, n, v[u], -v[u]);
				updates(0, 0, n, x, x);
				v[u] = x;
			}
		}
	}
	return 0;
} 