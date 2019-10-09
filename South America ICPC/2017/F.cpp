#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 100010
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

int n;
ll st[4*MAXN];

ll query(int cur, int l, int r, int ql, int qr)
{
	if(ql > r || qr < l) return 0LL;
	if(ql <= l && r <= qr) 
	{
		return st[cur];
	}
	int mid = (l+r) >> 1;
	int left = (cur << 1) + 1;
	int right = left + 1;
	return max(query(left, l, mid, ql, qr), query(right, mid+1, r, ql, qr));
}

void update(int cur, int l, int r, int x, ll val)
{
	if(l == r)
	{
		st[cur] = max(st[cur], val);
		return ;
	}
	int mid = (l+r) >> 1;
	int left = (cur << 1) + 1;
	int right = left + 1;
	if(x <= mid)
		update(left, l, mid, x, val);
	else
		update(right, mid+1, r, x, val);
	st[cur] = max(st[left], st[right]);
}

struct state
{
	int b, f;
	ll d;
	state(int b = 0, int f = 0, ll d = 0LL) : b(b), f(f), d(d) {}
	bool operator< (const state& s) const
	{
		if(b == s.b) return f > s.f;
		return b < s.b;
	}
};
int f[MAXN];
state v[MAXN];

int main()
{
	while(cin >> n)
	{
		ll mx = 0LL;
		for(int i = 0; i < n; ++i)
		{
			state s;
			cin >> s.b >> s.f >> s.d;
			v[i] = s;
			f[i] = s.f;
			mx = max(mx, s.d);
		}
		sort(f, f+n);
		map<int, int> m;
		int size = 0;
		for(int i = 0; i < n; ++i)
			if(m.find(f[i]) == m.end()) m[f[i]] = size++;
		for(int i = 0; i < 4*n; ++i)
			st[i] = 0;
		sort(v, v+n);
		update(0, 0, size-1, m[v[0].f], v[0].d);
		ll tmp = 0LL;
		for(int i = 1; i < n; ++i)
		{
			if(v[i].b == v[i-1].b && v[i].f == v[i-1].f)
				tmp += v[i-1].d;
			else
				tmp = 0LL;
			ll ans = 0LL;
			int idx = m[v[i].f]-1;
			if(idx >= 0)
			{
				ans = query(0, 0, size-1, 0, idx);
			}
			ll newmx = tmp + ans + v[i].d;
			update(0, 0, size-1, m[v[i].f], newmx);
			mx = max(mx, newmx);
		}
		cout << mx << '\n';
	}
	return 0;
}