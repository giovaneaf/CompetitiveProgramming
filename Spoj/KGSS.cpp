#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, q;
 
ii st[4*MAXN];
 
void update(int cur, int l, int r, int x, int val)
{
	if(l == r)
	{
		st[cur] = mp(val, -1);
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
	vi v{st[left].fst, st[left].snd, st[right].fst, st[right].snd};
	sort(v.begin(), v.end());
	st[cur] = mp(v[3], v[2]);
}
 
ii query(int cur, int l, int r, int ql, int qr)
{
	if(ql > r || qr < l) return mp(-1, -1);
	if(ql <= l && r <= qr)
	{
		return st[cur];
	}
	int mid = (l+r)>>1;
	int left = (cur<<1) + 1;
	int right = left + 1;
	ii qla = query(left, l, mid, ql, qr);
	ii qra = query(right, mid+1, r, ql, qr);
	vi v{qla.fst, qla.snd, qra.fst, qra.snd};
	sort(v.begin(), v.end());
	return mp(v[3], v[2]);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	FOR(i, 0, n)
	{
		int val;
		cin >> val;
		update(0, 0, n-1, i, val);
	}
	cin >> q;
	FOR(i, 0, q)
	{
		char c;
		int x, y;
		cin >> c >> x >> y;
		x--;
		if(c == 'Q')
		{
			y--;
			ii p = query(0, 0, n-1, x, y);
			printf("%d\n", p.fst+p.snd);
		}
		else
		{
			update(0, 0, n-1, x, y);
		}
	}
	return 0;
}  