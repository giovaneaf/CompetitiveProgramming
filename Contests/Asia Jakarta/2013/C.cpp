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
#define MAXN 20010
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n;
int busy[MAXN];
int sz[MAXN];
bool seen[MAXN];

int DFS(int cur, vi* adj)
{
	seen[cur] = true;
	sz[cur] = 1;
	int len = n-1;
	for(int& v : adj[cur])
	{
		if(!seen[v])
		{
			sz[cur] += DFS(v, adj);
			busy[cur] += (sz[v]*max(0, len-sz[v]));
			len -= sz[v];
		}
	}
	return sz[cur];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		memset(busy, 0, sizeof(busy));
		memset(sz, 0, sizeof(sz));
		memset(seen, false, sizeof(seen));
		cin >> n;
		vi adj[n];
		int a, b;
		FOR(i, 0, n-1)
		{
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		DFS(0, adj);
		int ans = 0;
		FOR(i, 1, n)
		{
			if(ans < busy[i]) ans = busy[i];
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
