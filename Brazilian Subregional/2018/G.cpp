#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 2010
#define MAXM 45010
#define MOD 2147483647
#define INF 1e9
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, bool> ib;
 
int ned, first[MAXN], work[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM], dist[MAXN];
 
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
 
int dfs(int u, int f, int s, int t) {
	if (u == t) return f;
	int v, df;
	for(int & e = work[u]; e!=-1; e = nxt[e]) {
        v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			df = dfs(v, min(f, cap[e]), s, t);
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
	int u, v;
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		u = q.front(); q.pop();
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist[t] >= 0;
}
 
int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, s, t)) result += f;
	}
	return result;
}
 
int p, r, c, sum;
int d[MAXN];
int e[MAXN];
 
bool solvable(vii* adj, int t)
{
	init();
	for(int i = 0; i < r; ++i)
	{
		add(p+r, i, e[i]);
		for(int j = 0; j < adj[i].size(); ++j)
		{
			if(adj[i][j].second <= t)
			{
				add(i, adj[i][j].first, INF);
			}
		}
	}
	for(int i = 0; i < p; ++i)
		add(i+r, p+r+1, d[i]);
	return dinic(p+r, p+r+1) == sum;
}
 
int main()
{
	scanf("%d %d %d", &p, &r, &c);
	sum = 0;
	for(int i = 0; i < p; ++i)
	{
		cin >> d[i];
		sum += d[i];
	}
	for(int i = 0; i < r; ++i)
	{
		cin >> e[i];
	}
	vii adj[MAXN];
	int maxT = 1;
	for(int i = 0; i < c; ++i)
	{
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		a--, b--;
		adj[b].push_back({a+r, t});
		maxT = max(maxT, t);
	}
	if(!solvable(adj, maxT))
	{
		printf("-1\n");
	}
	else
	{
		int l = 1;
		int h = maxT;
		while(h - l > 1)
		{
			int mid = (l+h) >> 1;
			if(solvable(adj, mid))
				h = mid;
			else
				l = mid+1;
		}
		int ans = (solvable(adj, l) ? l : h);
		printf("%d\n", ans);
	}
    return 0;
}