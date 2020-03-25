#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
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
 
inline int mymap(int x)
{
	if(x >= 2) return x;
	if(x >= 1) return 0;
	return 1;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n, m;
		cin >> n >> m;
		init();
		memset(&cap, 0, sizeof cap);
		FOR(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			a = mymap(a);
			b = mymap(b);
			if(a > b) swap(a, b);
			if(a == 0)
			{
				add(a, b, 1);
			}
			else
			{
				add(n+a, b, 1);
				add(n+b, a, 1);
			}
		}
		FOR(i, 0, n)
		{
			add(i, n+i, 1);
		}
		add(n+1, 2*n, 1);
		add(n+2, 2*n, 1);
		int mf = dinic(0, 2*n);
		printf("%s\n", mf == 2 ? "YES" : "NO");
	}
	return 0;
}
 