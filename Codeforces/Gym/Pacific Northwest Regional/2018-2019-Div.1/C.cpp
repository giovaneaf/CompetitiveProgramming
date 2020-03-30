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
#define MOD 998244353
 
int n, k, sz;
ll memo[MAXN][MAXN];

ll solve(int pos, int k, vi& freq)
{
	if(k == 0) return 1LL;
	if(pos >= sz) return 0LL;
	if(memo[pos][k] == -1LL)
	{
		ll ans = 0LL;
		ans = (freq[pos]*solve(pos+1, k-1, freq) + solve(pos+1, k, freq))%MOD;
		memo[pos][k] = ans;
	}
	return memo[pos][k];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n >> k)
	{
		vi v(n);
		map<int, int> mm;
		sz = 0;
		FOR(i, 0, n)
		{
			cin >> v[i];
			if(mm.find(v[i]) == mm.end())
				mm[v[i]] = sz++;
		}
		vi freq(sz, 0);
		FOR(i, 0, n)
		{
			freq[mm[v[i]]]++;
		}
		memset(memo, -1LL, sizeof(memo));
		printf("%lld\n", solve(0, k, freq));
	}
	return 0;
}