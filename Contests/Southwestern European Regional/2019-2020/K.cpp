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
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 10000000
 
#define DEBUG 0
 
int n, m, t;
int sz;
int cc[MAXN];
vi adj[MAXN];
vi radj[MAXN];
vb marked;
vb near;
vi cand;
vi ccradj[MAXN];
vb seen;
 
void mark(int cur)
{
	seen[cur] = true;
	for(int& u : ccradj[cur])
	{
		//printf("%d %d\n", cur, u);
		marked[u] = true;
		if(!seen[u])
		{
			mark(u);
		}
	}
}
 
void DFS(int cur, vi* adj, stack<int>& s, vb& seen)
{
	seen[cur] = true;
	for(int u : adj[cur])
	{
		if(!seen[u])
			DFS(u, adj, s, seen);
	}
	s.push(cur);
}
 
void newDFS(int cur, vi* adj, vb& seen, vi& cc)
{
	seen[cur] = true;
	cc.emplace_back(cur);
	for(int u : adj[cur])
	{
		if(!seen[u])
			newDFS(u, adj, seen, cc);
	}
}
 
vvi scc(int n, vi* adj, int* mcc)
{
	vvi ans;
	/*vi radj[n];
	FOR(i, 0, n)
	{
		for(int u: adj[i])
		{
			radj[u].emplace_back(i);
		}
	}*/
	stack<int> s;
	vb seen(n, false);
	FOR(i, 0, n)
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
			//printf("%d: ", cnt);
			for(int u : cc)
			{
				//printf("%d ", u);
				mcc[u] = cnt;
			}
			//putchar('\n');
			cnt++;
		}
	}
	sz = cnt;
	return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> t;
	near.assign(n, false);
	FOR(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		if(v == t)
		{
			near[u] = true;
			continue;
		}
		else if(u == t) continue;
		adj[u].emplace_back(v);
		radj[v].emplace_back(u);
	}
	vvi vscc = scc(n, adj, cc);
	marked.assign(sz, false);
	int idscc = 0;
	for(vi& vv : vscc)
	{
		int cntm = 0;
		for(int& x : vv)
		{
			if(near[x]) cntm++;
		}
		if(cntm > 0)
		{
			cand.emplace_back(idscc);
			if(cntm > 1)
			{
				marked[idscc] = true;
			}
		}
		idscc++;
	}
	FOR(u, 0, n)
	{
		for(int& v : radj[u])
		{
			if(cc[u] != cc[v])
			{
				//printf("edge = %d %d\n", cc[u], cc[v]);
				ccradj[cc[u]].emplace_back(cc[v]);
			}
		}
	}
	seen.assign(sz, false);
	for(int& u : cand)
	{
		if(!seen[u])
		{
			mark(u);
		}
	}
	set<int> ans;
	for(int& u : cand)
	{
		if(!marked[u])
		{
			for(int& x : vscc[u])
			{
				if(near[x]) ans.insert(x);
			}
		}
	}
	printf("%d\n", (int) ans.size());
	for(auto it = ans.begin(); it != ans.end(); it++)
	{
		printf("%d\n", *it);
	}
	return 0;
}