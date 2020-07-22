/*
Compute the height of every node in the tree and mark it's path.
Then add every single node to a priority queue sorted by height.
Get the top of the priority queue if it's not visited then add it to the answer and mark all nodes in the path as visited.
Remove from priority queue K times (Check if the priority queue is empty).
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
#define MAXN 100010
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

vi adj[MAXN];
int L[MAXN];
int nxt[MAXN];
bool seen[MAXN];

int DFS(int cur, priority_queue<ii>& pq)
{
	int mx = 0;
	for(int u : adj[cur])
	{
		if(L[u] == 0)
		{
			DFS(u, pq);
		}
		if(L[u] > mx)
		{
			mx = L[u];
			nxt[cur] = u;
		}
	}
	L[cur] = 1 + mx;
	pq.push(mp(L[cur], cur));
	return L[cur];
}

int main()
{
	int n, k;
	while(cin >> n >> k)
	{
		int dad;
		FOR(i, 1, n)
		{
			cin >> dad;
			dad--;
			adj[dad].emplace_back(i);
		}
		priority_queue<ii> pq;
		memset(L, 0, sizeof(L));
		memset(nxt, -1, sizeof(nxt));
		DFS(0, pq);
		FOR(i, 0, n)
		{
			adj[i].clear();
		}
		int ans = 0;
		memset(seen, false, sizeof(seen));
		while(pq.size() && k > 0)
		{
			int cur = pq.top().snd;
			pq.pop();
			if(!seen[cur])
			{
				while(cur != -1)
				{
					ans++;
					seen[cur] = true;
					cur = nxt[cur];
				}
				k--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}