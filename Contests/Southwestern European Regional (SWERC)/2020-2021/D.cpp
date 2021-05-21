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
#define MAXN 1010
#define LOGMAXN 23
#define MAXM 1010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

int n, m, l, u;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> l >> u)
	{
		vii adj[n];
		int a, b, c;
		FOR(i, 0, m)
		{
			cin >> a >> b >> c;
			adj[a].push_back(mp(b, c));
			adj[b].push_back(mp(a, c));
		}
		set<ii> edges;
		vi dist(n, INF);
		dist[0] = 0;
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push(mp(0, 0));
		int cur, len, nb, w;
		int maxLen = (u+1)/2;
		while(pq.size())
		{
			cur = pq.top().snd;
			len = pq.top().fst;
			pq.pop();
			if(len != dist[cur] || len >= maxLen)
				continue;
			for(ii& p : adj[cur])
			{
				nb = p.fst;
				w = p.snd;
				edges.insert(mp(min(cur, nb), max(cur, nb)));
				if(dist[nb] > dist[cur] + w)
				{
					dist[nb] = dist[cur] + w;
					pq.push(mp(dist[nb], nb));
				}
			}
		}
		printf("%d\n", (int) edges.size());
	}
	return 0;
}