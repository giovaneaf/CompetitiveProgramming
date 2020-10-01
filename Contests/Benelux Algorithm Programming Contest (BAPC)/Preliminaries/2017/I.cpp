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
#define MAXN 50010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n, e, m;

void DFS(int cur, vi* adj, stack<int>& s, vb& seen)		// first dfs
{
	seen[cur] = true;
	for(int u : adj[cur])
	{
		if(!seen[u])
			DFS(u, adj, s, seen);
	}
	s.push(cur);
}

void newDFS(int cur, vi* adj, vb& seen, vi& cc)			// dfs in reverse graph
{
	seen[cur] = true;
	cc.emplace_back(cur);
	for(int u : adj[cur])
	{
		if(!seen[u])
			newDFS(u, adj, seen, cc);
	}
}

vvi scc(int n, vi* adj, int* mcc)						// return all strongly connected components
{
	vvi ans;
	vi radj[n];
	for(int i = 0; i < n; ++i)
	{
		for(int u: adj[i])
		{
			radj[u].emplace_back(i);
		}
	}
	stack<int> s;
	vb seen(n, false);
	for(int i = 0; i < n; ++i)
	{
		if(!seen[i])
			DFS(i, adj, s, seen);
	}
	seen.assign(n, false);
	int cnt = 0;
	while(s.size())
	{
		int cur = s.top();
		s.pop();
		if(!seen[cur])
		{
			vi cc;
			newDFS(cur, radj, seen, cc);
			ans.emplace_back(cc);
			for(int u : cc)
			{
				mcc[u] = cnt;			// mark vertices in the current connected component
			}
			cnt++;
		}
	}
	return ans;
}

struct _scc
{
	bool priv;
	int enemy;
	int sz;
	_scc(bool priv = false, int enemy = 0, int sz = 0) : priv(priv), enemy(enemy), sz(sz) {}
	inline void init() { priv = false; enemy = 0; sz = 0; }
};

int mcc[MAXN];
bool enemy[MAXN];
_scc sccInfo[MAXN];

void markEnemy(int cur, vi* adj, vb& seen)
{
	seen[cur] = true;
	sccInfo[cur].priv = true;
	for(int& u : adj[cur])
	{
		if(!seen[u])
			markEnemy(u, adj, seen);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> e >> m)
	{
		vi adj[n];
		fill(enemy, enemy+n, false);
		int a, b;
		FOR(i, 0, m)
		{
			cin >> a >> b;
			adj[a].emplace_back(b);
		}
		FOR(i, 0, e)
		{
			cin >> a;
			enemy[a] = true;
		}
		vvi component = scc(n, adj, mcc);
		int sz = (int) component.size();
		FOR(i, 0, sz) sccInfo[i].init(); 
		vi nadj[sz];
		vi nradj[sz];
		set<ii> s;
		for(vi& cc : component)
		{
			for(int& u : cc)
			{
				sccInfo[mcc[u]].sz++;
				if(enemy[u])
				{
					sccInfo[mcc[u]].enemy++;
					sccInfo[mcc[u]].priv = true;
				}
				for(int& v : adj[u])
				{
					if(mcc[u] == mcc[v]) continue;
					if(s.find(mp(mcc[u], mcc[v])) == s.end())
					{
						nadj[mcc[u]].emplace_back(mcc[v]);
						nradj[mcc[v]].emplace_back(mcc[u]);
						s.insert(mp(mcc[u], mcc[v]));
					}
				}
			}
		}
		vb seen(sz, false);
		FOR(i, 0, sz)
		{
			if(seen[i]) continue;
			if(sccInfo[i].enemy > 0)
			{
				markEnemy(i, nradj, seen);
			}
		}
		vi inDeg(sz, 0);
		int ans = 0;
		FOR(i, 0, sz)
		{
			if(sccInfo[i].priv)
			{
				ans += sccInfo[i].sz - sccInfo[i].enemy;
			}
			else
			{
				for(int& u : nadj[i])
				{
					inDeg[u]++;
				}
			}
		}
		FOR(i, 0, sz)
		{
			if(sccInfo[i].priv) continue;
			if(inDeg[i] == 0) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}