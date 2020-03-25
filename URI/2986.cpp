#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 44100
#define LOGMAXN 20
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

ll n;
ll memo[MAXN];

ll solve(ll n)
{
	if(n < 0) return 0;
	if(n <= 1) return 1;
	if(n == 2) return 2;
	if(memo[n] == -1)
	{
		ll ans = ((solve(n-1) + solve(n-2))%MOD + solve(n-3))%MOD;
		memo[n] = ans;
	}
	return memo[n];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(memo, -1LL, sizeof(memo));
	while(cin >> n)
	{
		printf("%lld\n", solve(n));
	}
	return 0;
}
