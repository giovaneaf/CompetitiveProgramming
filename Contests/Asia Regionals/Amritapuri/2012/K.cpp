/*
	Code passes on Codechef but verdict is presentation error on Live Archive 
	(yellow sign on archive)
*/

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

int T, n, m;
bool dead[MAXN];
double ans;

void dfs(int cur, int p, int ndead, vi* adj)
{
	ans -= 1.0/(1.0+ndead);
	if(dead[cur]) ndead++;
	for(int& v : adj[cur])
	{
		if(v == p) continue;
		dfs(v, cur, ndead, adj);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	int a, b;
	while(T--)
	{
		cin >> n;
		memset(dead, false, sizeof(dead));
		vi adj[n];
		FOR(i, 0, n-1)
		{
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		cin >> m;
		FOR(i, 0, m) 
		{
			cin >> a;
			a--;
			dead[a] = true;
		}
		ans = (double) n;
		dfs(0, -1, 0, adj);
		printf("%.10f\n", ans);
	}
	return 0;
}
