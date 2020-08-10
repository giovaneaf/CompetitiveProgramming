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
#define MAXN 1000010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int pal[(1 << 11)+1][12];

bool isPal(int mask, int n)
{
	if(pal[mask][n] == -1)
	{
		int lp, rp, a, b;
		lp = 0; rp = n-1;
		bool isPalindrome = true;
		while(rp > lp)
		{
			a = (mask & (1 << rp)) == 0 ? 0 : 1;
			b = (mask & (1 << lp)) == 0 ? 0 : 1;
			if(a != b)
			{
				isPalindrome = false;
				break;
			}
			lp++; rp--;
		}
		pal[mask][n] = (isPalindrome ? 1 : 0);
	}
	return pal[mask][n] == 0 ? false : true;
}

int T, n, k;
ll memo[410][(1 << 11)+1][12][12];

ll solve(int pos, int mask, int len)
{
	if(len >= k)
	{
		if(isPal(mask, k)) return 0LL;
		if(len > k && isPal(mask, k+1)) return 0LL;
	}
	if(pos == 0) 
		return 1LL;
	if(memo[pos][mask][k][len] == -1)
	{
		ll newMask = (mask << 1) & (~(1 << 11));
		ll ans = (solve(pos-1, newMask, min(len+1, k+1)) + solve(pos-1, newMask | 1, min(len+1, k+1)))%mod;
		memo[pos][mask][k][len] = ans;
	}
	return memo[pos][mask][k][len];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	memset(pal, -1, sizeof(pal));
	memset(memo, -1, sizeof(memo));
	FOR(t, 0, T)
	{
		cin >> n >> k;
		printf("%lld\n", solve(n, 0, 0));
	}
	return 0;
}
