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
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

ll memo[MAXN][MAXN];
int K;

int solve(int cur, int k, vii* adj, int dad)
{
	if(memo[cur][k] == -1)
	{
		int ans = 0;
		int u, c, tmp = 0;
		vector<int> v;
		for(ii& p : adj[cur])
		{
			u = p.fst, c = p.snd;
			if(dad == u) continue;
			tmp += c;
			v.push_back(u);
			if(k > 0) ans = max(ans, c + solve(u, k-1, adj, cur));
		}
		if((int) v.size() == 2 && k >= 2)
		{
			int a = v[0], b = v[1];
			int newK = k-2;
			FOR(i, 0, newK+1)
			{
				ans = max(ans, tmp + solve(a, i, adj, cur) + solve(b, newK-i, adj, cur));
			}
		}
		memo[cur][k] = ans;
	}
	return memo[cur][k];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(memo, -1, sizeof(memo));
	int n;
	cin >> n >> K;
	vii adj[n];
	int a, b, c;
	FOR(i, 0, n-1)
	{
		cin >> a >> b >> c;
		a--, b--;
		adj[a].emplace_back(mp(b, c));
		adj[b].emplace_back(mp(a, c));
	}
	printf("%d\n", solve(0, K, adj, -1));
	return 0;
}

