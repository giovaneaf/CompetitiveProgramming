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
#define MAXN 310
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int h, w;
ll memo[MAXN][MAXN];

ll solve(int h, int w)
{
	if(h < 0) return 0LL;
	if(h == 0) return w == 0 ? 1LL : 0LL;
	if(w == 0) return 1LL;
	if(memo[h][w] == -1LL)
	{
		ll ans = solve(h-1, w-1);
		FOR(i, 1, w)
		{
			ans = (ans%mod + (solve(h-1, i-1)*solve(h, w-i))%mod)%mod;
		}
		memo[h][w] = ans;
	}
	return memo[h][w];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(memo, -1, sizeof(memo));
	while(cin >> h >> w)
	{
		assert(h <= 300 && w <= 300);
		h--, w--;
		printf("%lld\n", ((solve(h, w) - solve(h-1, w) + mod)%mod));
	}
	return 0;
}