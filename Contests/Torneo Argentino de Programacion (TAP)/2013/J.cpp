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
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n;
ll memo[MAXN][MAXN][2][2];
int even;

ll solve(int st, int sub, int par)
{
	if(st == 0) return even == par ? 0LL : 1LL;
	if(sub > st) return 0LL;
	if(memo[st][sub][par][even] == -1)
	{
		ll ans = (solve(st-sub, sub, par^1) + solve(st, sub+1, par))%mod;
		memo[st][sub][par][even] = ans;
	}	
	return memo[st][sub][par][even];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	memset(memo, -1, sizeof(memo));
	while(T--)
	{
		cin >> n;
		even = (((n&1) == 1) ? 0 : 1);
		printf("%lld\n", solve(n, 1, 1));
	}
	return 0;
}
