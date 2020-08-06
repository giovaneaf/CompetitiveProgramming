#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n, m;
bool hasPos, hasNeg;

inline int getId(int x, bool negated)
{
	if(negated) x = -x;
	return abs(x) - 1 + (x < 0 ? n : 0);
}

void DFS(int cur, vi* adj, vb& seen)
{
	if(cur < n) hasPos = true;
	else hasNeg = true;
	seen[cur] = true;
	for(int& v : adj[cur])
	{
		if(!seen[v])
		{
			DFS(v, adj, seen);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vi adj[2*n], radj[2*n];
		int a, b;
		FOR(i, 0, m)
		{
			cin >> a >> b;
			adj[getId(a, true)].emplace_back(getId(b, false));
			adj[getId(b, true)].emplace_back(getId(a, false));
			radj[getId(b, false)].emplace_back(getId(a, true));
			radj[getId(a, false)].emplace_back(getId(b, true));
		}
		vb seen(2*n, false);
		int ans, tmp;
		ans = -1;
		FOR(i, 0, n)
		{
			hasPos = hasNeg = false;
			tmp = 2;
			DFS(i, adj, seen);
			if(hasNeg)
			{
				if(seen[i+n]) tmp--;
				fill(seen.begin(), seen.end(), false);
				DFS(i+n, adj, seen);
				if(seen[i])
				{
					tmp--;
					if(ans == -1 || ans > tmp) ans = tmp;
					if(ans == 0) 
					{
						break;
					}
				}
				else
				{
					fill(seen.begin(), seen.end(), false);
					hasPos = hasNeg = false;
					DFS(i+n, radj, seen);
					if(hasPos)
					{
						if(ans == -1 || ans > tmp) ans = tmp;
					}
				}
				fill(seen.begin(), seen.end(), false);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

