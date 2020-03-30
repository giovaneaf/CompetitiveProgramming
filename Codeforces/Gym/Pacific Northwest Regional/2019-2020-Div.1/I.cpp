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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n;
 
int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];
 
void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}
 
void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}
 
int dfs(int u, int f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			int df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}
 
bool bfs(int s, int t) {
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}
 
int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}
 
bool swapFree(int i, int j, vector<string>& v)
{
	int diff = 0;
	FOR(k, 0, (int) v[i].size())
	{
		if(v[i][k] != v[j][k])
		{
			diff++;
			if(diff > 2) break;
		}
	}
	return diff != 2;
}
 
void DFS(int cur, vi& curSet, vi* adj, int label)
{
	curSet[cur] = label;
	for(int& u : adj[cur])
	{
		if(curSet[u] == -1)
		{
			DFS(u, curSet, adj, label^1);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vector<string> v(n);
		vi adj[n];
		FOR(i, 0, n)
		{
			cin >> v[i];
		}
		FOR(i, 0, n)
		{
			FOR(j, i+1, n)
			{
				if(!swapFree(i, j, v))
				{
					adj[i].emplace_back(j);
					adj[j].emplace_back(i);
				}
			}
		}
		vi curSet(n, -1);
		FOR(i, 0, n)
		{
			if(curSet[i] == -1)
			{
				DFS(i, curSet, adj, 0);
			}
		}
		init();
		int s, t;
		s = 501, t = 502;
		FOR(u, 0, n)
		{
			if(curSet[u] == 0)
			{
				for(int& v : adj[u])
				{
					add(u, v, INF);
				}
				add(s, u, 1);
			}
			else
			{
				add(u, t, 1);
			}
		}
		printf("%d\n", n - dinic(s, t));
	}
	return 0;
}