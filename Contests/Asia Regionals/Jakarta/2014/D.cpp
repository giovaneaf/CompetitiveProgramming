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
#define MAXN 510
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n, k, p;
ll ncr[MAXN][MAXN];
ll fact[MAXN];

ll comb(ll n, ll r)
{
	if(r == 0 || r == n || n <= 1) return 1LL;
	if(ncr[n][r] == -1)
	{
		ll ans = (comb(n-1, r) + comb(n-1, r-1))%mod;
		ncr[n][r] = ans;
	}
	return ncr[n][r];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = 1;
	FOR(i, 1, MAXN) fact[i] = (fact[i-1]*i)%mod;
	memset(ncr, -1, sizeof(ncr));
	cin >> T;
	int len, tmp;
	FOR(t, 0, T)
	{
		cin >> n >> k >> p;
		ll ans = 0LL;
		len = 0;
		FOR(i, k, n-1) // each position of p
		{
			FOR(j, p+1, n+1) // each number greater than p
			{
				tmp = max(0, j-2);
				if(tmp >= len)
				{
					ans += (comb(tmp, len)*fact[n-2-len])%mod;
					ans %= mod;
				}
			}
			len++;
		}
		len++;
		ans += (comb(n-1, len)*fact[n-1-len])%mod;
		ans %= mod;
		printf("Case #%d: %lld\n", t+1, ans);
	}
	return 0;
}
