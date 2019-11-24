/*
For non repeated e-mails find every leaf in DAG and sum 1, for repeated e-mails use a memoization table to store
how many e-mails that node sended then you just sum all children of a node to find the sum of all e-mails sended.
*/

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
#define MAXN 5010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int n, l;
int cnt;
ll dp[MAXN];

ll solve(int cur, vi* adj, vb& seen)
{
	if(cur >= l) 
	{
		if(!seen[cur])
		{
			seen[cur] = true;
			cnt++;
		}
		return 1;
	}
	if(dp[cur] == -1LL)
	{
		ll ans = 0LL;
		for(int& u : adj[cur])
		{
			ans = (ans + solve(u, adj, seen))%MOD;
		}
		dp[cur] = ans;
	}
	return dp[cur];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> l)
	{
		vi adj[l];
		FOR(i, 0, l)
		{
			int sz;
			cin >> sz;
			while(sz--)
			{
				int x;
				cin >> x;
				adj[i].emplace_back(x-1);
			}
		}
		fill(dp, dp+n, -1LL);
		cnt = 0;
		vb seen(MAXN, false);
		ll ans = solve(0, adj, seen);
		printf("%lld %d\n", ans, cnt);
	}
	return 0;
}

