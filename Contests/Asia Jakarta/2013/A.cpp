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
#define MAXN 110
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n, m;
ll v[MAXN];
ll memo[MAXN][MAXN];

ll solve(int pos, int groups)
{
	if(groups >= n-pos || pos == n) return 0LL;
	if(memo[pos][groups] == -1)
	{
		ll ans = v[n-1]-v[pos];
		if(groups > 1)
		{
			FOR(i, pos, n-1)
			{
				ans = min(ans, v[i]-v[pos] + solve(i+1, groups-1));
			}
		}
		memo[pos][groups] = ans;
	}
	return memo[pos][groups];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		cin >> n >> m;
		FOR(i, 0, n)
		{
			cin >> v[i];
		}
		ll ans = 0LL;
		if(n > m)
		{
			memset(memo, -1LL, sizeof(memo));
			sort(v, v+n);
			ans = solve(0, m);
		}
		printf("Case #%d: %lld\n", t+1, ans);
	}
	return 0;
}
