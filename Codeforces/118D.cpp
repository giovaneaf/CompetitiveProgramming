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
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 10000000
 
#define DEBUG 0

int n1, n2, k1, k2;
const ll mod = 1e8;
ll memo[110][110][11][2];

ll solve(int s1, int s2, int k, bool footman)
{
	if(s1 == 0 && s2 == 0) return 1;
	if(memo[s1][s2][k][footman] == -1LL)
	{
		ll ans = 0LL;
		if(s1 > 0 && (!(footman && k >= k1)))
		{
			ans = (ans + solve(s1-1, s2, footman ? (k+1) : 1, true))%mod;
		}
		if(s2 > 0 && (!(!footman && k >= k2)))
		{
			ans = (ans + solve(s1, s2-1, footman ? 1 : k+1, false))%mod;
		}
		memo[s1][s2][k][footman] = ans;
	}
	return memo[s1][s2][k][footman];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n1 >> n2 >> k1 >> k2)
	{
		memset(memo, -1LL, sizeof(memo));
		printf("%lld\n", (solve(n1, n2, 0, true))%mod);
	}
	return 0;
}