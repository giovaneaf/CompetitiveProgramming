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
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n, m;
int deg[MAXN];
int node[MAXN];
int cand[MAXN];
int sz;

void DFS(int cur, vi* adj, vb& seen, int& size)
{
	seen[cur] = true;
	node[size++] = cur;
	for(int& v : adj[cur])
	{
		if(!seen[v]) DFS(v, adj, seen, size);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		int ans = 0;
		cin >> n >> m;
		int a, b;
		vi adj[n];
		memset(deg, 0, sizeof(deg));
		FOR(i, 0, m)
		{
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
			deg[a]++; deg[b]++;
		}
		vb seen(n, false);
		vb visited(n);
		int half, cnt;
		bool valid;
		FOR(i, 0, n)
		{
			if(seen[i]) continue;
			sz = 0;
			DFS(i, adj, seen, sz);
			if(sz&1) continue;	// if odd size
			half = sz/2;
			cnt = 0;
			valid = true;
			FOR(j, 0, sz)
			{
				if(deg[node[j]] == half)
				{
					cand[cnt++] = node[j];
				}
				else if(deg[node[j]] != half-1)
				{
					valid = false; break;
				}
			}
			if(!valid || cnt != 2) continue;
			cnt = 0;
			fill(visited.begin(), visited.end(), false);
			visited[cand[1]] = true;
			DFS(cand[0], adj, visited, cnt);
			if(cnt == half) ans++;
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
