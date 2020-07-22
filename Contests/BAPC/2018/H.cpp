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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
 
int n, m, s, t;
vector<pair<int, ll>> radj[MAXN];
pair<ll, ll> dist[MAXN];
vi inDeg;

ll Dijkstra()
{
	FOR(i, 0, n)
	{
		dist[i].fst = INFLL;
		dist[i].snd = 0LL;
	}
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	queue<int> q;
	dist[t].fst = dist[t].snd = 0LL;
	pq.push(mp(dist[t].fst, t));
	q.push(t);
	int cur, v, w, cost;
	bool ended = false;
	while(pq.size())
	{
		while(q.size())
		{
			cur = q.front();
			q.pop();
			if(cur == s) ended = true;
			for(pair<int, ll>& p : radj[cur])
			{
				v = p.fst; w = p.snd;
				if(dist[v].fst > dist[cur].snd + w)
				{
					dist[v].fst = dist[cur].snd + w;
					pq.push(mp(dist[v].fst, v));
				}
			}
		}
		cost = pq.top().fst;
		cur = pq.top().snd;
		pq.pop();
		if(cost > dist[cur].fst) continue;
		for(pair<int, ll>& p : radj[cur])
		{
			v = p.fst; w = p.snd;
			inDeg[v]--;
			if(inDeg[v] == 0) q.push(v);
			if(dist[v].snd < dist[cur].fst + w)
			{
				dist[v].snd = dist[cur].fst + w;
			}
		}
		while(q.size())
		{
			cur = q.front();
			q.pop();
			if(cur == s) ended = true;
			for(pair<int, ll>& p : radj[cur])
			{
				v = p.fst; w = p.snd;
				if(dist[v].fst > dist[cur].snd + w)
				{
					dist[v].fst = dist[cur].snd + w;
					pq.push(mp(dist[v].fst, v));
				}
			}
		}
	}
	return ended ? dist[s].snd : 0LL;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n >> m >> s >> t)
	{
		int a, b;
		ll c;
		inDeg.assign(n, 0);
		FOR(i, 0, m)
		{
			cin >> a >> b >> c;
			radj[b].push_back(mp(a, c));
			inDeg[a]++;
		}
		ll ans = Dijkstra();
		if(ans == 0LL && s != t) printf("infinity\n");
		else printf("%lld\n", ans);
		FOR(i, 0, n)
		{
			radj[i].clear();
		}
	}
	return 0;
}