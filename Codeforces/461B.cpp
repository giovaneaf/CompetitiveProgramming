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
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int x[MAXN];
ll memo[MAXN][2];

ll solve(int cur, int st, vi* adj, int dad)
{
	if(memo[cur][st] == -1LL)
	{
		ll W, B, ansW, ansB;
		W = (x[cur] == 0);
		B = (x[cur] == 1);
		for(int& u : adj[cur])
		{
			if(u == dad) continue;
			ansW = ansB = 0;
			ansW += W*solve(u, 0, adj, cur);
			ansB += (B*solve(u, 0, adj, cur) + W*solve(u, 1, adj, cur))%mod;
			ansW %= mod; ansB %= mod;
			
			ansW += W*solve(u, 1, adj, cur);
			ansB += B*solve(u, 1, adj, cur);
			ansW %= mod; ansB %= mod;
			
			W = ansW;
			B = ansB;
		}
		memo[cur][0] = W;
		memo[cur][1] = B;
	}
	return memo[cur][st];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		memset(memo, -1LL, sizeof(memo));
		vi adj[n];
		int a;
		FOR(i, 0, n-1)
		{
			cin >> a;
			adj[a].emplace_back(i+1);
			adj[i+1].emplace_back(a);
		}
		FOR(i, 0, n) cin >> x[i];
		printf("%lld\n", solve(0, 1, adj, -1));
	}
	return 0;
}
