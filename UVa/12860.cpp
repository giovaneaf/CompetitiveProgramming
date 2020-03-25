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
#define MAXN 500010
#define MAXM 44100
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int n;

struct point 
{
	int x, y;
	point(int x = 0LL, int y = 0LL) : x(x), y(y) {}
	bool operator< (const point& p) const 
	{
		if(x == p.x) return y < p.y;
		return x < p.x;
	}
};

int freq[2];

void DFS(int cur, vi* adj, int color, vb& seen)
{
	freq[color]++;
	seen[cur] = true;
	for(int u : adj[cur])
	{
		if(!seen[u])
		{
			DFS(u, adj, color^1, seen);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		map<point, int> mm;
		vector<point> v(n);
		vi adj[n];
		FOR(i, 0, n)
		{
			cin >> v[i].x >> v[i].y;
			mm[v[i]] = i;
		}
		FOR(i, 0, n)
		{
			int j;
			for(int x = -5; x <= 5; ++x)
			{
				for(int y = -5; y <= 5; ++y)
				{
					if(x*x + y*y > 25) continue;
					point tgt = point(v[i].x + x, v[i].y+y);
					if(mm.count(tgt))
					{
						j = mm[tgt];
						adj[i].emplace_back(j);
						adj[j].emplace_back(i);
					}
				}
			}
		}
		vb seen(n, false);
		int ans = 0;
		FOR(i, 0, n)
		{
			if(!seen[i])
			{
				freq[0] = freq[1] = 0;
				DFS(i, adj, 0, seen);
				ans += min(freq[0], freq[1]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}