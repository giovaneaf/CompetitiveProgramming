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
#define MAXN 100010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int n, m;
pair<ll, ll> memo[MAXN];

pair<ll, ll> solve(int cur, vi* adj)
{
	if(memo[cur].fst == -1)
	{
		ll ans = 0LL;
		ll bestPath = 0LL;
		pair<ll, ll> tmp;
		for(int& v : adj[cur])
		{
			tmp = solve(v, adj);
			ans += tmp.fst;
			bestPath = max(bestPath, tmp.snd);
		}
		memo[cur] = mp(ans, ans+bestPath);
	}
	return memo[cur];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vi adj[n];
		FOR(i, 0, n) memo[i] = mp(-1LL, 0LL);
		memo[n-1] = mp(1LL, 1LL);
		int a, b;
		FOR(i, 0, m)
		{
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
		}
		printf("%lld\n", solve(0, adj).snd);
	}
	return 0;
}
