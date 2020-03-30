#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MOD 1000000009
 
int k, b;
ll memo[130][130][1010];

ll solve(int pos, int bits, int r)
{
	if(pos >= b) return (r == 0 ? bits : 0);
	if(memo[pos][bits][r] == -1LL)
	{
		ll ans = (solve(pos+1, bits+1, (2*r+1)%k) + solve(pos+1, bits, (2*r)%k))%MOD;
		memo[pos][bits][r] = ans;
	}
	return memo[pos][bits][r];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> k >> b)
	{
		memset(memo, -1LL, sizeof(memo));
		printf("%lld\n", solve(0, 0, 0));
	}
	return 0;
}