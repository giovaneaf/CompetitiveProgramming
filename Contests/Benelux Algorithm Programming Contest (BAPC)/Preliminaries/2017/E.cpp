#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 300010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

ll n, m, k;
ll memo[62][62][2];

ll solve(int cur, int rk, bool tight)
{
	if(cur == -1)
		return (rk == 0) ? 0 : INFLL;
	if(memo[cur][rk][tight] == -1LL)
	{
		ll ans = INFLL;
		ll tmp;
		// checking 0
		if((!tight) || ((n & (1LL << cur)) == 0))
		{
			tmp = solve(cur-1, rk, tight);
			if(tmp != INFLL) ans = min(ans, tmp);
		}
		// checking 1
		if(rk > 0)
		{
			tmp = solve(cur-1, rk-1, tight && ((n & (1LL << cur)) == 0 ? false : true));
			if(tmp != INFLL) ans = min(ans, (1LL << cur) + tmp);
		}
		memo[cur][rk][tight] = ans;
	}
	return memo[cur][rk][tight];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		if((1LL << k) - 1 > n) printf("%lld\n", (1LL << k) - 1);
		else
		{
			memset(memo, -1LL, sizeof(memo));
			n++;
			printf("%lld\n", solve(61, k, true));
		}
	}
	return 0;
}