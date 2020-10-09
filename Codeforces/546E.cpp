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

int ans[110][110];

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

int n, m;

void computeAns()
{
	for(int u = 1; u <= n; ++u)
	{
		for(int e = first[u]; e!=-1; e = nxt[e]) 
		{
			int v = to[e];
			if(v > n)
			{
				ans[u-1][v-n-1] += INF - cap[e];
			}
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		memset(&ans, 0, sizeof(ans));
		init();
		memset(&cap, 0, sizeof cap);
		int suma = 0, sumb = 0;;
		int a, b;
		for(int i = 1; i <= n; ++i)
		{
			cin >> a;
			suma += a;
			add(0, i, a);
			add(i, n+i, INF);
		}
		for(int i = n+1; i <= 2*n; ++i)
		{
			cin >> b;
			sumb += b;
			add(i, 2*n+1, b);
		}
		FOR(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			add(a, n+b, INF);
			add(b, n+a, INF);
		}
		if(suma != sumb)
		{
			printf("NO\n");
		}
		else
		{
			int mf = dinic(0, 2*n+1);
			if(mf < sumb)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
				computeAns();
				FOR(i, 0, n)
				{
					FOR(j, 0, n)
					{
						if(j > 0) putchar(' ');
						printf("%d", ans[i][j]);
					}
					putchar('\n');
				}
			}
		}
	}
	return 0;
}
