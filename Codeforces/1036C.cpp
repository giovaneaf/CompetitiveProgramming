#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 1010
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

int n;
string s;
ll dp[24][7][8];

ll solve(int pos, bool tight, int nzero)
{
	if(nzero > 3) return 0LL;
	if(pos == s.size()) return 1LL;
	if(dp[pos][tight][nzero] != -1) return dp[pos][tight][nzero];
	ll ans = 0LL;
	for(int i = 0; i < 10; ++i)
	{
		if(!tight || (tight && i <= (s[pos] - '0')))
		{
			ans += solve(pos+1, tight && (s[pos] - '0' == i), nzero + (i > 0));
		}
	}
	return dp[pos][tight][nzero] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		for(int i = 0; i < n; ++i)
		{
			ll a, b;
			cin >> a >> b;
			memset(dp, -1LL, sizeof(dp));
			s = to_string(b);
			ll ans = solve(0, true, 0);
			memset(dp, -1LL, sizeof(dp));
			s = to_string(a-1LL);
			ans -= solve(0, true, 0);
			cout << ans << '\n';
		}
	}
	return 0;
}