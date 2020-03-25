#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, k;
 
int dist(ii& p1, ii& p2)
{
	return (p1.fst-p2.fst)*(p1.fst-p2.fst) + (p1.snd-p2.snd)*(p1.snd-p2.snd);
}
 
void DFS(int cur, vi* adj, vb& seen)
{
	seen[cur] = true;
	for(int u : adj[cur])
	{
		if(!seen[u])
		{
			DFS(u, adj, seen);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n && n)
	{
		vii v(n);
		vi adj[n];
		FOR(i, 0, n)
		{
			cin >> v[i].fst >> v[i].snd;
		}
		FOR(i, 0, n)
		{
			priority_queue<pair<ii, ii>, vector<pair<ii, ii>>, greater<pair<ii, ii>>> pq;
			FOR(j, 0, n)
			{
				if(i == j) continue;
				pq.push(mp(mp(dist(v[i], v[j]), v[j].fst), mp(v[j].snd, j)));
			}
			FOR(j, 0, 2)
			{
				if(pq.size())
				{
					pair<ii, ii> p = pq.top();
					pq.pop();
					adj[i].emplace_back(p.snd.snd);
				}
			}
		}
		vb seen(n, false);
		DFS(0, adj, seen);
		bool can = true;
		FOR(i, 0, n)
		{
			if(!seen[i])
			{
				can = false;
				break;
			}
		}
		printf("%s\n", can ? "All stations are reachable." : "There are stations that are unreachable.");
	}
    return 0;
}