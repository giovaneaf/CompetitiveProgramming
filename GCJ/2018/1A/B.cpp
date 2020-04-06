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
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

struct cashier
{
	ll m, s, p;
};

int T, R, B, C;
cashier v[MAXN];
ll cap[MAXN];

bool can(ll t)
{
	ll bits;
	bits = 0LL;
	FOR(i, 0, C)
	{
		cap[i] = max(0LL, min(v[i].m, (t-v[i].p)/v[i].s));
	}
	sort(cap, cap + C, greater<ll>());
	FOR(i, 0, min(R, C))
	{
		bits += cap[i];
		if(bits >= B) return true;
	}
	return bits >= B;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 1, T+1)
	{
		cin >> R >> B >> C;
		FOR(i, 0, C)
		{
			cin >> v[i].m >> v[i].s >> v[i].p;
		}
		ll l, h, mid;
		l = 0LL; h = 3000000000000000000LL;
		while(h - l > 1)
		{
			mid = l + ((h-l)>>1);
			if(can(mid)) h = mid;
			else l = mid+1;
		}
		printf("Case #%d: %lld\n", t, can(l) ? l : h);
	}
	return 0;
}

