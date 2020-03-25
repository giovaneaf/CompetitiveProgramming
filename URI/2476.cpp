#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; a++)
#define RFOR(a, b, c) for(int a = b; a >= c; a--)
#define mp(a, b) make_pair(a, b)

struct Node
{
	int s, f;
	Node(int s = 0, int f = 0) : s(s), f(f) {}
};

int n, q, sqrtn;
int dad[MAXN];
int visited[MAXN];
int L[MAXN];
int P[MAXN][LOGMAXN];
Node node[MAXN]; 
int idx;

void makeList(int cur, vi* adj, int* list)
{
	visited[cur] = true;
	list[idx] = cur;
	node[cur].s = idx++;
	FOR(i, 0, adj[cur].size())
	{
		int u = adj[cur][i];
		if(!visited[u]) makeList(u, adj, list);
	}
	list[idx] = cur;
	node[cur].f = idx++;
}

void DFS(int cur, vi* adj)
{
	visited[cur] = true;
	FOR(i, 0, adj[cur].size())
	{
		int u = adj[cur][i];
		if(!visited[u])
		{
			L[u] = L[cur]+1;
			dad[u] = cur;
			DFS(u, adj);
		}
	}
}

void init()
{
	FOR(i, 0, n)
	{
		P[i][0] = dad[i];
	}
	FOR(j, 1, LOGMAXN)
		FOR(i, 0, n)
			if(P[i][j-1] > -1)
				P[i][j] = P[P[i][j-1]][j-1];
			else
				P[i][j] = -1;
}

int queryLCA(int a, int b)
{
	if(L[a] < L[b]) swap(a, b);
	RFOR(i, LOGMAXN-1, 0)
	{
		if(L[a] - (1 << i) >= L[b]) 
		{
			a = P[a][i];
		}
	}
	if(a == b) return b;
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

bool cmp(const pair<ii, int>& p1, const pair<ii, int>& p2)
{
	int block1 = p1.first.first/sqrtn;
	int block2 = p2.first.first/sqrtn;
	if(block1 < block2 || (block1 == block2 && (p1.first.second < p2.first.second || 
		(p1.first.second == p2.first.second && p1.first.first < p2.first.first))))
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	sqrtn = sqrt(n);
	map<string, int> mp;
	int v[n];
	int count = 0;
	FOR(i, 0, n)
	{
		visited[i] = false;
		dad[i] = -1;
		string s;
		cin >> s;
		if(mp.find(s) == mp.end())
		{
			v[i] = count;
			mp[s] = count++;
		}
		else
		{
			v[i] = mp[s];
		}
	}
	vi adj[n];
	FOR(i, 0, n-1)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	L[0] = 0;
	dad[0] = -1;
	DFS(0, adj);
	init();
	int list[2*n];
	idx = 0;
	FOR(i, 0, n)
	{
		visited[i] = false;
	}
	makeList(0, adj, list);
	vector<pair<ii, int>> query(q);
	int LCA[q];
	FOR(i, 0, q)
	{
		LCA[i] = -1;
		int a, b;
		cin >> a >> b;
		a--, b--;
		if(node[a].s > node[b].s) swap(a, b);
		int lca = queryLCA(a, b);
		if(lca == a)
		{
			query[i] = mp(mp(node[a].s, node[b].s), i);
		}
		else
		{
			query[i] = mp(mp(node[a].f, node[b].s), i);
			LCA[i] = lca;
		}
	}
	sort(query.begin(), query.end(), cmp);
	vector<int> num(n, 0);
	vector<int> f(count, 0);
	int cl, cr;
	cl = cr = query[0].first.first;
	int cnt = 1;
	f[v[list[cl]]]++;
	num[list[cl]]++;
	int ans[q];
	FOR(i, 0, q)
	{
		int l, r;
		l = query[i].first.first; r = query[i].first.second;
		int index = query[i].second;
		while(cr < r)
		{
			cr++;
			int u = list[cr];
			num[u]++;
			if(num[u] == 1)
			{
				f[v[u]]++;
				if(f[v[u]] == 1) cnt++;
			}
			else
			{
				f[v[u]]--;
				if(f[v[u]] == 0) cnt--;
			}
		}
		while(cr > r)
		{
			int u = list[cr];
			num[u]--;
			if(num[u] == 1) 
			{
				f[v[u]]++;
				if(f[v[u]] == 1) cnt++;
			}
			else
			{
				f[v[u]]--;
				if(f[v[u]] == 0) cnt--;
			}
			cr--;
		}
		while(cl < l)
		{
			int u = list[cl];
			num[u]--;
			if(num[u] == 1) 
			{
				f[v[u]]++;
				if(f[v[u]] == 1) cnt++;
			}
			else
			{
				f[v[u]]--;
				if(f[v[u]] == 0) cnt--;
			}
			cl++;
		}
		while(cl > l)
		{
			cl--;
			int u = list[cl];
			num[u]++;
			if(num[u] == 1)
			{
				f[v[u]]++;
				if(f[v[u]] == 1) cnt++;
			}
			else
			{
				f[v[u]]--;
				if(f[v[u]] == 0) cnt--;
			}
		}
		int ansQ = cnt;
		if(LCA[index] > -1 && f[v[LCA[index]]] == 0) 
		{
			ansQ++;
		}
		ans[index] = ansQ;
	}
	FOR(i, 0, q)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}