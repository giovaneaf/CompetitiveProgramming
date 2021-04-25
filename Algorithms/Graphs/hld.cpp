/*
	Implementation of Heavy Light Decomposition (not optimized)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
const ll mod = 1000000007LL;
int n, m;

struct HLD
{
	vector<vii> adj;
	vi subtreeSz;
	vi dad;
	int n;
	int logn;
	vvi P;
	vi L;
	vi heavy;
	vi heavyIdx;
	vi data;
	int num;
	vvi trees;
	vector<vector<ll>> st;
	vector<vector<ll>> lazy;
	HLD(int n) : n(n)
	{
		logn = log2(n)+1;
		adj.resize(n, vii());
	}
	void add(int a, int b, int c)
	{
		adj[a].push_back(mp(b, c));
		adj[b].push_back(mp(a, c));
	}
	int compSubtree(int cur)
	{
		subtreeSz[cur] = 1;
		int u;
		for(ii& p : adj[cur])
		{
			u = p.fst;
			if(u == dad[cur])
				continue;
			dad[u] = cur;
			data[u] = p.snd;
			L[u] = L[cur]+1;
			subtreeSz[cur] += compSubtree(u);
		}
		return subtreeSz[cur];	
	}
	void decomp(int cur, bool newHeavy)
	{
		heavy[cur] = (newHeavy ? num++ : heavy[dad[cur]]);
		heavyIdx[cur] = (newHeavy ? 0 : heavyIdx[dad[cur]]+1);
		int nxt = -1;
		int u;
		for(ii& p : adj[cur])
		{
			u = p.fst;
			if(u == dad[cur])
				continue;
			if(nxt == -1 || subtreeSz[u] > subtreeSz[nxt])
				nxt = u;
		}
		if(nxt > -1)
		{
			for(ii& p : adj[cur])
			{
				u = p.fst;
				if(u == dad[cur])
					continue;
				if(u == nxt)
					decomp(u, false);
				else
					decomp(u, true);
			}
		}
	}
	void buildTree(int cur)
	{
		trees[heavy[cur]].push_back(cur);
		int u;
		for(ii& p : adj[cur])
		{
			u = p.fst;
			if(u == dad[cur])
				continue;
			buildTree(u);
		}
	}
	void updateST(int cur, int l, int r, int ql, int qr, int val, vector<ll>& st, vector<ll>& lazy)
	{
		int lc, rc;
		lc = 2*cur+1; rc = lc+1;
		if(lazy[cur])
		{
			st[cur] += lazy[cur];
			if(l != r)
			{
				lazy[lc] += lazy[cur]; 
				lazy[rc] += lazy[cur];
			}
			lazy[cur] = 0;
		}
		if(ql > r || qr < l)
			return ;
		if(ql <= l && r <= qr)
		{
			st[cur] += val;
			if(l != r)
			{
				lazy[lc]++; 
				lazy[rc]++;
			}
			return;
		}
		int m = (l+r)/2;
		updateST(lc, l, m, ql, qr, val, st, lazy);
		updateST(rc, m+1, r, ql, qr, val, st, lazy);
		st[cur] = st[lc] + st[rc];
	}
	ll queryST(int cur, int l, int r, int ql, int qr, vector<ll>& st, vector<ll>& lazy)
	{
		int lc, rc;
		lc = 2*cur+1; rc = lc+1;
		if(lazy[cur])
		{
			st[cur] += lazy[cur];
			if(l != r)
			{
				lazy[lc] += lazy[cur]; 
				lazy[rc] += lazy[cur];
			}
			lazy[cur] = 0;
		}
		if(ql > r || qr < l)
			return 0;
		if(ql <= l && r <= qr)
		{
			return st[cur];
		}
		int m = (l+r)/2;
		lc = 2*cur+1; rc = lc+1;
		return queryST(lc, l, m, ql, qr, st, lazy) + queryST(rc, m+1, r, ql, qr, st, lazy);
	}
	void decompose()
	{
		subtreeSz.resize(n);
		L.resize(n);
		dad.resize(n);
		data.resize(n);
		dad[0] = -1;
		L[0] = 0;
		data[0] = 0;
		compSubtree(0);
		P.resize(n, vi(logn, -1));
		FOR(i, 0, n)
			P[i][0] = dad[i];
		FOR(j, 1, logn)
			FOR(i, 0, n)
				if(P[i][j-1] > -1)
					P[i][j] = P[P[i][j-1]][j-1];
		heavy.resize(n);
		heavyIdx.resize(n);
		vb seen(n, false);
		num = 0;
		decomp(0, true);
		int nTrees = 0;
		FOR(i, 0, n)
		{
			nTrees = max(nTrees, heavy[i]);
		}
		trees.resize(nTrees+1, vi());
		buildTree(0);
		for(vi& aa : trees)
		{
			st.push_back(vector<ll>(4*(int) aa.size(), 0));
			lazy.push_back(vector<ll>(4*(int) aa.size(), 0));
			/*for(int& v : aa)
			{
				printf("%d ", v);
			}
			putchar('\n');*/
		}
		int idx;
		/*FOR(i, 0, n)
		{
			idx = heavy[i];
			updateST(0, 0, (int) trees[idx].size()-1, heavyIdx[i], heavyIdx[i], data[i], st[idx], lazy[idx]);
		}*/
	}
	int LCA(int a, int b)
	{
		if(L[a] < L[b]) swap(a, b);
		RFOR(i, logn-1, 0)
		{
			if(L[a] - (1 << i) >= L[b])
				a = P[a][i];
		}
		if(a == b) return a;
		RFOR(i, logn-1, 0)
		{
			if(P[a][i] != P[b][i])
			{
				a = P[a][i];
				b = P[b][i];
			}
		}
		return dad[a];
	}
	void updateAux(int x, int lca)
	{
		int idx;
		while(heavy[x] != heavy[lca])
		{
			idx = heavy[x];
			updateST(0, 0, (int) trees[idx].size()-1, 0, heavyIdx[x], 1, st[idx], lazy[idx]);
			x = dad[trees[idx][0]];
		}
		if(x != lca)
		{
			idx = heavy[x];
			updateST(0, 0, (int) trees[idx].size()-1, heavyIdx[lca]+1, heavyIdx[x], 1, st[idx], lazy[idx]);
		}
	}
	void update(int a, int b)
	{
		if(a == b)
			return ;
		int lca = LCA(a, b);
		updateAux(a, lca);
		updateAux(b, lca);
	}
	int queryAux(int x, int lca)
	{
		int ans = 0;
		int idx;
		while(heavy[x] != heavy[lca])
		{
			idx = heavy[x];
			ans += queryST(0, 0, (int) trees[idx].size()-1, 0, heavyIdx[x], st[idx], lazy[idx]);
			x = dad[trees[idx][0]];
		}
		if(x != lca)
		{
			idx = heavy[x];
			ans += queryST(0, 0, (int) trees[idx].size()-1, heavyIdx[lca]+1, heavyIdx[x], st[idx], lazy[idx]);
		}
		return ans;
	}
	int query(int a, int b)
	{
		if(a == b)
			return 0;
		int lca = LCA(a, b);
		return queryAux(a, lca) + queryAux(b, lca);
	}
};

// SPOJ - GRASSPLA 

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> n >> m;
	HLD hld(n);
	int a, b, c;
	FOR(i, 0, n-1)
	{
		cin >> a >> b;
		a--, b--;
		hld.add(a, b, 0);
	}
	hld.decompose();
	string s;
	FOR(i, 0, m)
	{
		cin >> s;
		cin >> a >> b;
		if(s == "Q")
			printf("%d\n", hld.query(a-1, b-1));
		else
			hld.update(a-1, b-1);
	}
	return 0;
}