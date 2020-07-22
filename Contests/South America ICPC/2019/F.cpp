/*
You can use dynamic programming building from bottom to top.
This is a dp(s, n) where s is the number of available blocks and n is
the number of contiguous blocks (note that it should be contiguous to be a valid solution) below the current floor
and dp(s, n) stores the answer.
The transition is dp(s, n) = dp(s, n-1) + sum from x=1 to min(s, n) of dp(s-x, x)
The first term (dp(s, n-1)) is if we don't start building at the first block and the second term (sum)
all possible ways to build starting from the first block.
The problem with this is that this will lead to an O(S*B*min(S, B)) solution which will give us TLE.
But let's expand this second term (sum) ... dp(s-1, 1) + dp(s-2, 2) + dp(s-3, 3) + ... + dp(s-min(s, n), min(s, n))
So there is a pattern and we can precompute this with another dynamic programming table called g(s, n).
g(s, n) stores the following sum: dp(s, n) + dp(s+1, n-1) + dp(s+2, n-2) + ... + dp(s+n-1, 1)
So we can define this mutual recursion:
dp(s, n) = 1, if s = 0	// no more blocks to put
dp(s, n) = 0, if n = 0  // last floor with 0 tiles (problem)
otherwise dp(s, n) = dp(s, n-1) + g(s - min(s, n), min(s, n)) 
and
g(s, n) = dp(s, n), if n = 1 // end of prefix sum
otherwise g(s, n) = dp(s, n) + g(s+1, n-1)
This will lead to an O(S*B) solution!
The answer will be dp(S-B, B) because we need to put tiles in all blocks in the first floor.
*/

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
#define MAXN 5010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define DEBUG 0

ll memo[MAXN][MAXN];
ll pre[MAXN][MAXN];

ll solve(int s, int n);

ll g(int s, int n)
{
	if(pre[s][n] == -1LL)
	{
		ll ans = solve(s, n);
		if(n > 1)
		{
			ans = (ans + g(s+1, n-1))%MOD;
		}
		pre[s][n] = ans;
	}
	return pre[s][n];
}

ll solve(int s, int n)
{
	if(s == 0) return 1LL;
	if(n == 0) return 0LL;
	if(memo[s][n] == -1LL)
	{
		ll ans = (solve(s, n-1) + g(s - min(s, n), min(s, n)))%MOD;
		memo[s][n] = ans;
	}
	return memo[s][n];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int S, B;
	while(cin >> S >> B)
	{
		memset(memo, -1LL, sizeof(memo));
		memset(pre, -1LL, sizeof(pre));
		printf("%lld\n", solve(B-S, S));
	}
	return 0;
}

