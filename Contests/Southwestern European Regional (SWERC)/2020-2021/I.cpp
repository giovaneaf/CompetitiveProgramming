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

int n, m;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vi adj[n];
		int a, b, c;
		FOR(i, 0, m)
		{
			cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		if(n == 1)
		{
			printf("0\n");
			continue;
		}
		vi dist(n, -1);
		dist[0] = 0;
		queue<int> q;
		q.push(0);
		int depth = 0;
		int cur;
		while(q.size())
		{
			cur = q.front();
			depth = max(depth, dist[cur]);
			q.pop();
			for(int& v : adj[cur])
			{
				if(dist[v] == -1)
				{
					dist[v] = dist[cur]+1;
					q.push(v);
				}
			}
		}
		bool connected = true;
		FOR(i, 0, n)
		{
			if(dist[i] == -1)
			{
				connected = false;
				break;
			}
		}
		int ans = -1;
		if(connected)
			ans = (int) ceil(log2(depth)) + 1;
		printf("%d\n", ans);
	}
	return 0;
}