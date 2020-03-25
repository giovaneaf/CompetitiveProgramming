#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
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

int n, m;
ll v[MAXN];

bool can(ll k)
{
	ll last = 0;
	FOR(i, 0, n)
	{
		if(v[i] - last > k) return false;
		if(v[i] - last == k) k--;
		last = v[i];
	}
	return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	FOR(t, 0, T)
	{
		cin >> n;
		FOR(i, 0, n)
		{
			cin >> v[i];
		}
		if(n == 1)
		{
			printf("Case %d: %lld\n", t+1, v[0]);
		}
		else
		{
			ll l = 1;
			ll h = 1000000000000000000LL;
			while(h - l > 1)
			{
				ll mid = (h+l) >> 1;
				if(can(mid)) h = mid;
				else l = mid+1;
			}
			printf("Case %d: %lld\n", t+1, can(l) ? l : h);
		}
	}
    return 0;
}