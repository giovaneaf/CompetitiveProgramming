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
#define INF 0x3f3f3f3f
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int x, r, b;
 
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
 
double pairDist(ii& p1, ii& p2)
{
	return sqrt((p1.fst-p2.fst)*(p1.fst-p2.fst) + (p1.snd-p2.snd)*(p1.snd-p2.snd));
}
 
bool can(double mid, vector<pair<double, ii>>& v)
{
	init();
	int s = 501, t = 502;
	FOR(i, 0, b*r)
	{
		if(v[i].fst > mid) break;
		add(v[i].snd.fst, v[i].snd.snd, INF);
	}
	FOR(i, 0, b)
	{
		add(s, i, 1);
	}
	FOR(i, 0, r)
	{
		add(i+b, t, 1);
	}
	int mf = dinic(s, t);
	int MIS = b+r-mf;
	return MIS >= x;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> x >> b >> r)
	{
		vector<pair<double, ii>> v(b*r);
		vector<ii> blue(b); vector<ii> red(r);
		FOR(i, 0, b)
		{
			cin >> blue[i].fst >> blue[i].snd;
		}
		FOR(i, 0, r)
		{
			cin >> red[i].fst >> red[i].snd;
		}
		FOR(i, 0, b)
		{
			FOR(j, 0, r)
			{
				v[i*r+j] = mp(pairDist(blue[i], red[j]), mp(i, j+b));
			}
		}
		sort(v.begin(), v.end());
		double l, h, mid;
		l = 0.0; h = v[b*r-1].fst;
		while(h-l > EPS)
		{
			mid = (l+h)/2.0;
			if(can(mid, v))
			{
				l = mid;
			}
			else
			{
				h = mid;
			}
		}
		printf("%.10f\n", l);
	}
	return 0;
}