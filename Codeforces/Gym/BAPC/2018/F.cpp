#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL

int n;
ll m;

bool can(ll x, vector<pair<ll, ll>>& v)
{
	ll money = m;
	FOR(i, 0, n)
	{
		money -= max(0LL, v[i].fst*x-v[i].snd);
		if(money <= 0) return true;
	}
	return money <= 0;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n >> m)
	{
		vector<pair<ll, ll>> v(n);
		FOR(i, 0, n)
		{
			cin >> v[i].fst >> v[i].snd;
		}
		ll l, r, mid;
		l = 0;
		r = 10000000000LL;
		while(r - l > 1)
		{
			mid = l + (r-l)/2LL;
			if(can(mid, v))	r = mid;
			else l = mid+1;
		}
		printf("%lld\n", can(l, v) ? l : r);
	}
	return 0;
}