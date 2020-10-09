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
#define MAXN 100010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n, k;
int v[MAXN];
ll memo[103][103][103];

ll solve(int cur, int k, int mx)
{
	if(k == 0) return 1LL;
	if(cur == n+1) return 0LL;
	if(memo[cur][k][mx] == -1LL)
	{
		ll ans = solve(cur+1, k, mx);
		if(v[mx] < v[cur])
			ans += solve(cur+1, k-1, cur);
		memo[cur][k][mx] = ans;
	}
	return memo[cur][k][mx];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		if(n == 0 && k == 0) break;
		v[0] = -INF;
		FOR(i, 1, n+1)
		{
			cin >> v[i];
		}
		memset(memo, -1, sizeof(memo));
		printf("%lld\n", solve(1, k, 0));
	}
	return 0;
}