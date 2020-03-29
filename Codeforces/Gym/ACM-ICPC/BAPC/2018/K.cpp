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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
 
int n, h, sz;
vi adj[MAXN];
int leaf[MAXN];
vb seen;

void DFS(int u)
{
	seen[u] = true;
	if((int) adj[u].size() == 1) leaf[sz++] = u;
	for(int& v : adj[u])
		if(!seen[v]) DFS(v);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n >> h)
	{
		int a, b;
		FOR(i, 0, n-1)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		sz = 0;
		seen.assign(n, false);
		DFS(h);
		printf("%d\n", (sz+1)/2);
		int half = sz/2;
		int i = 0;
		for(; i < half; ++i)
		{
			printf("%d %d\n", leaf[i], leaf[i+half]);
		}
		if(sz&1) printf("%d %d\n", leaf[0], leaf[sz-1]);
		FOR(i, 0, n) adj[i].clear();
	}
	return 0;
}