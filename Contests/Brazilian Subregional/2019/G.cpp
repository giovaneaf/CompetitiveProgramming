/*
This problem is the assigment problem, but you need to note that you're multiplying the values and
you are asked to maximize the answer. You can solve the multiplication problem by applying the logarithm
because log(a*b) = log(a)+log(b), so you can treat it as sum (as in the assignment problem). The other issue is
that you need to maximize the answer, you can change it by negating all values then you need to minimize it and
you have the assignment problem and this problem can be solved with the Hungarian Algorithm or with min cost flow.
*/
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
#define MAXN 210
#define MAXM 44100
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9
 
int ned;
int first[MAXN], to[MAXM], nxt[MAXM], prv[MAXN];
double cost[MAXM], dist[MAXN], pot[MAXN]; 
ll cap[MAXM];
 
void init() {
	memset(first, -1, sizeof first);
	ned = 0;
}
 
void add(int u, int v, ll f, double c) {
	to[ned] = v, cap[ned] = f;
	cost[ned] = c, nxt[ned] = first[u];
	first[u] = ned++;
	to[ned] = u, cap[ned] = 0;
	cost[ned] = -c, nxt[ned] = first[v];
	first[v] = ned++;
}
 
bool dijkstra(int s, int t, int n) {
	memset(&prv, -1, sizeof prv);
	for(int i = 0; i <= n; i++) dist[i] = -1.0;
	set< pair<double, int> > q;
	q.insert(make_pair(0.0, s));
	prv[s] = 0;
	dist[s] = 0.0;
	while(!q.empty()) {
		int u = q.begin()->second;
		q.erase(q.begin());
		for(int e = first[u]; e != -1; e = nxt[e]) {
			if (cap[e] <= 0) continue;
			int v = to[e];
			double new_dist = dist[u] + cost[e] + pot[u] - pot[v];
			if (new_dist < dist[v] || fabs(dist[v] + 1.0) < EPS) {
				q.erase(make_pair(dist[v], v));
				dist[v] = new_dist;
				prv[v] = e;
				q.insert(make_pair(new_dist, v));
			}
		}
	}
	return prv[t] != -1;
}
 
double augment(int s, int t, ll &maxflow, int n) {
	ll flow = maxflow;
	for(int i = t; i != s; i = to[prv[i]^1])
		flow = min(flow, cap[prv[i]]);
	for(int i = t; i != s; i = to[prv[i]^1]) {
		cap[prv[i]] -= flow;
		cap[prv[i]^1] += flow;
	}
	maxflow -= flow;
	double flowCost = flow*(dist[t]-pot[s]+pot[t]);
	for(int i = 1; i <= n; i++)
		if (prv[i] != -1) pot[i] += dist[i];
	return flowCost;
}
 
double mincostmaxflow(int s, int t, ll &maxflow, int n) {
	double flowCost = 0;
	memset(pot, 0, sizeof pot);
	while(maxflow > 0 && dijkstra(s, t, n)) {
		flowCost += augment(s, t, maxflow, n);
	}
	return flowCost;
}
 
int M[MAXN][MAXN];
int ans[MAXN];
 
void findAns(int n) {
	queue<int> q;
	FOR(i, 0, n)
		q.push(i);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int e = first[u]; e != -1; e = nxt[e]) {
			if (cap[e] <= 0) 
			{
				ans[to[e]-n] = u;
				continue;
			}
		}
	}
}
 
int main()
{
	int n;
	while(cin >> n)
	{
		int s, t;
		s = 2*n;
		t = s+1;
		init();
		int toJ = n;
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				cin >> M[i][j];
				add(i, toJ + j, 1LL, -log2(M[i][j]));
			}
			add(s, i, 1LL, 0.0);
			add(toJ + i, t, 1LL, 0.0);
		}
		ll maxflow = n;
		mincostmaxflow(s, t, maxflow, t);
		findAns(n);
		FOR(i, 0, n)
		{
			if(i > 0) putchar(' ');
			printf("%d", ans[i]+1);
		}
		putchar('\n');
	}
	return 0;
}