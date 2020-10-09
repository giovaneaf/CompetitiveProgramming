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
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int T;

struct Edge
{
	int to;
	ll cost;
	Edge(int to = 0, ll cost = 0LL) : to(to), cost(cost) {}
};

struct centroid
{
	int n, root;
	int size[MAXN];
	vector<vector<Edge>> adj;
	vb isCentroid;
	vi L, dad;
	vvi P;
	centroid(int sz, vector<vector<Edge>>& tmp)
	{
		n = sz;
		isCentroid.assign(n, false);
		adj.assign(n, vector<Edge>());
		root = decompose(0, tmp);
		computeLCA();
	}
	int lca(int a, int b)
	{
		if(L[a] < L[b]) swap(a, b);
		RFOR(i, LOGMAXN-1, 0)
		{
			if(L[a] - (1 << i) >= L[b])
				a = P[a][i];
		}
		if(a == b) return a;
		RFOR(i, LOGMAXN-1, 0)
		{
			if(P[a][i] != P[b][i])
			{
				a = P[a][i];
				b = P[b][i];
			}
		}
		return dad[a];
	}
private:
	int decompose(int cur, vector<vector<Edge>>& tmp)
	{
		int curCentroid, childCentroid;
		curCentroid = getCentroid(cur, tmp);
		isCentroid[curCentroid] = true;
		for(Edge& e : tmp[curCentroid])
		{
			if(!isCentroid[e.to])
			{
				childCentroid = decompose(e.to, tmp);
				adj[curCentroid].emplace_back(childCentroid);
				adj[childCentroid].emplace_back(curCentroid);
			}
		}
		return curCentroid;
	}
	int getCentroid(int cur, vector<vector<Edge>>& tmp)
	{
		dfs(cur, -1, tmp);
		if(size[cur] == 1) 
			return cur;
		else 
			return findCentroid(cur, mp(cur, 0), size[cur], tmp);
	}
	int dfs(int cur, int par, vector<vector<Edge>>& tmp)
	{
		size[cur] = 1;
		for(Edge& e : tmp[cur])
		{
			if(par != e.to && !isCentroid[e.to])
			{
				size[cur] += dfs(e.to, cur, tmp);
			}
		}
		return size[cur];
	}
	int findCentroid(int cur, ii p, int subtreeSize, vector<vector<Edge>>& tmp)
	{
		int nxt = p.fst;
		int maxChild = p.snd;
		for(Edge& e : tmp[cur])
		{
			if(!isCentroid[e.to] && p.fst != e.to)
			{
				if(size[e.to] > maxChild)
				{
					nxt = e.to;
					maxChild = size[e.to];
				}
			}
		}
		if(maxChild <= subtreeSize/2)
			return cur;
		else
			return findCentroid(nxt, mp(cur, subtreeSize - size[nxt]), subtreeSize, tmp);
	}
	void computeLCA()
	{
		L.assign(n, -1);
		dad.assign(n, -1);
		L[root] = 0;
		dfsLCA(root);
		P.assign(n, vi(LOGMAXN, -1));
		FOR(i, 0, n) P[i][0] = dad[i];
		FOR(j, 1, LOGMAXN)
			FOR(i, 0, n)
				if(P[i][j-1] != -1) P[i][j] = P[P[i][j-1]][j-1];
	}
	void dfsLCA(int cur)
	{
		for(Edge& e : adj[cur])
		{
			if(L[e.to] == -1)
			{
				L[e.to] = 1 + L[cur];
				dad[e.to] = cur;
				dfsLCA(e.to);
			}
		}
	}
};

void dfs(int cur, centroid& c, vi& ans, int depth)
{
	if(ans[cur] == -1)
	{
		ans[cur] = depth;
		for(Edge& e : c.adj[cur])
		{
			if(ans[e.to] == -1) dfs(e.to, c, ans, depth+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		vector<vector<Edge>> tmp(n, vector<Edge>());
		int a, b;
		FOR(i, 0, n-1)
		{
			cin >> a >> b;
			a--, b--;
			tmp[a].emplace_back(Edge(b, 0LL));
			tmp[b].emplace_back(Edge(a, 0LL));
		}
		centroid c(n, tmp);
		vi ans(n, -1);
		dfs(c.root, c, ans, 0);
		FOR(i, 0, n)
		{
			if(i > 0) putchar(' ');
			printf("%c", ans[i]+'A');
		}
		putchar('\n');
	}
	return 0;
}
