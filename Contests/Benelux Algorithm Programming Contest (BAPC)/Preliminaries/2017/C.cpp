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
#define MAXN 300010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n, m;
int dad[1010];

void DFS(int cur, int minCap, vii* adj, vb& seen)
{
	seen[cur] = true;
	int u, c;
	for(ii& p : adj[cur])
	{
		u = p.fst; c = p.snd;
		if(c < minCap) continue;
		if(!seen[u])
		{
			dad[u] = cur;
			DFS(u, minCap, adj, seen);
		}
	}
}

bool can(int mid, vii* adj)
{
	vb seen(n, false);
	memset(dad, -1, sizeof(dad));
	DFS(0, mid, adj, seen);
	return dad[n-1] > -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vii adj[n];
		map<ii, int> mm;
		int a, b, c;
		int mx = 0;
		FOR(i, 0, m)
		{
			cin >> a >> b >> c;
			adj[a].emplace_back(mp(b, c));
			adj[b].emplace_back(mp(a, c));
			mm[mp(min(a, b), max(a, b))] = i;
			mx = max(mx, c);
		}
		int l = 0, h = mx, mid;
		while(h - l > 1)
		{
			mid = (h+l)/2;
			if(can(mid, adj)) l = mid;
			else h = mid-1;
		}
		if(can(h, adj)) l = h;
		can(l, adj);
		set<int> s;
		int cur = n-1, u, lcur;
		lcur = cur;
		while(cur > -1)
		{
			for(ii& p : adj[cur])
			{
				u = p.fst;
				if(u == dad[cur] || u == lcur) continue;
				s.insert(mm[mp(min(cur, u), max(cur, u))]);
			}
			lcur = cur;
			cur = dad[cur];
		}
		if(s.size() == 0) printf("none\n");
		else 
		{
			for(auto it = s.begin(); it != s.end(); ++it)
			{
				if(it != s.begin()) putchar(' ');
				printf("%d", *it);
			}
			putchar('\n');
		}
	}
	return 0;
}