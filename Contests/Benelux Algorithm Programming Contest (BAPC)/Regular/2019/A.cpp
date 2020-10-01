#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define LOGMAXN 21
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n, k;
ll s[MAXN];
int L[MAXN];
int nxt[MAXN];
priority_queue<ii> pq;

int DFS(int cur, int p, vi* adj)
{
	int mx = 0;
	for(int& v : adj[cur])
	{
		if(v == p) continue;
		DFS(v, cur, adj);
		if(mx < L[v])
		{
			mx = L[v];
			nxt[cur] = v;
		}
	}
	L[cur] = 1 + mx;
	pq.push(mp(L[cur], cur));
	return L[cur];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		vi adj[n];
		FOR(i, 0, k) cin >> s[i];
		sort(s, s+k);
		int x;
		FOR(i, 1, n)
		{
			cin >> x;
			adj[x].emplace_back(i);
			adj[i].emplace_back(x);
		}
		memset(nxt, -1, sizeof(nxt));
		DFS(0, -1, adj);
		vb seen(n, false);
		bool fs = true;
		int cur;
		int pos = k-1;
		ll ans = 0LL;
		while(pq.size())
		{
			cur = pq.top().snd;
			pq.pop();
			if(seen[cur]) continue;
			ans += (ll) (L[cur]-fs)*s[pos--];
			while(cur > -1)
			{
				seen[cur] = true;
				cur = nxt[cur];
			}
			fs = false;
		}
		printf("%lld\n", ans);
	}
	return 0;
}