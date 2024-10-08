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
#define MAXN 40000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while(cin >> n >> m)
	{
		vi adj[n];
		FOR(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		vi L(n, -1);
		L[0] = 0;
		queue<int> q;
		q.push(0);
		while(q.size())
		{
			int cur = q.front();
			q.pop();
			if(cur == n-1) break;
			for(int& u : adj[cur])
			{
				if(L[u] == -1)
				{
					L[u] = 1 + L[cur];
					q.push(u);
				}
			}
		}
		printf("%d\n", max(0, L[n-1]-1));
	}
	return 0;
}