#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n, m, k;

struct query
{
	int l, r;
	ll u;
	query(int l = 0, int r = 0, ll u = 1LL) : l(l), r(r), u(u) {}
};

void BeaverAlgorithm(vector<ll>& v, vector<query>& q)
{
	int n = v.size();
	for(int i = 0; i < q.size(); ++i)
	{
		v[q[i].l] += q[i].u;
		if(q[i].r < n-1) v[q[i].r+1] -= q[i].u;
	}
	ll cnt = v[0];
	FOR(i, 1, n)
	{
		cnt += v[i];
		v[i] = cnt;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> k)
	{
		vector<ll> ans(n);
		FOR(i, 0, n) cin >> ans[i];
		vector<query> q1(m);
		FOR(i, 0, m)
		{
			cin >> q1[i].l >> q1[i].r >> q1[i].u;
			q1[i].l--; q1[i].r--;
		}
		vector<query> q2(k);
		FOR(i, 0, k) 
		{
			cin >> q2[i].l >> q2[i].r;
			q2[i].l--; q2[i].r--;
		}
		vector<ll> v(m, 0);
		BeaverAlgorithm(v, q2);
		FOR(i, 0, m) q1[i].u *= v[i];
		v.assign(n, 0);
		BeaverAlgorithm(v, q1);
		cout << ans[0] + v[0];
		FOR(i, 1, n) cout << " " << ans[i] + v[i];
		cout << '\n';
	}
	return 0;
}