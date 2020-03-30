#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
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
 
int n, m, k, s, t;
 
struct door
{
	int to, l, h;
	door(int to, int l, int h) : to(to), l(l), h(h) {}
};
 
vector<door> adj[MAXN];
bool seen[MAXN];
 
void dfs(int cur, int id)
{
	seen[cur] = true;
	for(door d : adj[cur])
	{
		if(!seen[d.to] && d.l <= id && id <= d.h) dfs(d.to, id);
	}
}
 
bool can(int id)
{
	FOR(i, 0, n) seen[i] = false;
	dfs(s, id);
	return seen[t];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> k)
	{
		cin >> s >> t;
		s--, t--;
		set<int> values;
		FOR(i, 0, m)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--, b--;
			adj[a].emplace_back(door(b, c, d));
			values.insert(c); values.insert(d+1);
		}
		int last = 0;
		bool lastIt = false;
		int ans = 0;
		for(int id : values)
		{
			if(lastIt) 
			{
				ans += id - last;
			}
			lastIt = can(id);
			last = id;
		}
		printf("%d\n", ans);
		FOR(i, 0, n) adj[i].clear();
	}		
	return 0;
} 
close