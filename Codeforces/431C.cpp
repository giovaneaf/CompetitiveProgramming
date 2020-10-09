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
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007;

int n, k, d;
ll memo[MAXN][2];

ll solve(int x, bool good)
{
	if(x == 0) return (good ? 1 : 0);
	if(memo[x][good] == -1LL)
	{
		ll ans = 0LL;
		for(int i = 1; i <= min(x, k); ++i)
		{
			ans += solve(x-i, good || i >= d);
			ans %= mod;
		}
		memo[x][good] = ans;
	}
	return memo[x][good];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k >> d)
	{
		memset(memo, -1LL, sizeof(memo));
		printf("%lld\n", solve(n, false));
	}
	return 0;
}
