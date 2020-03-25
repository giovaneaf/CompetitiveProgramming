#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define MAXN 100010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
int n;

struct Pair
{
	int a, b;
	Pair(int a = INF, int b = -INF) : a(a), b(b) {}
};

Pair st[4*MAXN];
int value[MAXN];

void init(int cur, int l, int r)
{
	if(l == r)
	{
		st[cur] = Pair(value[l], value[l]);
		return ;
	}
	int mid = (l+r) >> 1;
	int left = (cur << 1) + 1;
	int right = left + 1;
	init(left, l, mid); init(right, mid+1, r);
	st[cur] = Pair(min(st[left].a, st[right].a), max(st[left].b, st[right].b));
}

void update(int cur, int l, int r, int x, int v)
{
	if(l == r)
	{
		st[cur] = Pair(v, v);
		return ;
	}
	int mid = (l+r) >> 1;
	int left = (cur << 1) + 1;
	int right = left + 1;
	if(x <= mid)
		update(left, l, mid, x, v);
	else
		update(right, mid+1, r, x, v);
	st[cur] = Pair(min(st[left].a, st[right].a), max(st[left].b, st[right].b));
}

Pair query(int cur, int l, int r, int ql, int qr)
{
	if(ql > r || qr < l) return Pair(INF, -INF);
	if(l >= ql && r <= qr) 
	{
		return st[cur];
	}
	int mid = (l+r) >> 1;
	int left = (cur << 1) + 1;
	int right = left + 1;
	Pair lf = query(left, l, mid, ql, qr);
	Pair rt = query(right, mid+1, r, ql, qr);
	return Pair(min(lf.a, rt.a), max(lf.b, rt.b));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n)
		{
			cin >> value[i];
		}
		init(0, 0, n-1);
		int q; cin >> q;
		FOR(i, 0, q)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if(a == 1)
			{
				update(0, 0, n-1, b-1, c);
			}
			else
			{
				Pair p = query(0, 0, n-1, b-1, c-1);
				printf("%d\n", p.b - p.a);
			}
		}
	}
	return 0;
}