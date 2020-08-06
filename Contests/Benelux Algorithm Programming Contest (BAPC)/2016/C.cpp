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
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007;

int n, m, x, l;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> x >> l)
	{
		x--; l--;
		vb dead(n, false);
		vii deg(n, mp(0, 0));
		vi adj[n];
		int a, b;
		FOR(i, 0, m)
		{
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
			deg[a].fst++; deg[a].snd++; deg[b].fst++; deg[b].snd++;
		}
		queue<int> q;
		q.push(l);
		dead[l] = true;
		int cur;
		while(q.size())
		{
			cur = q.front();
			q.pop();
			for(int& v : adj[cur])
			{
				if(!dead[v])
				{
					deg[v].snd--;
					if(2*deg[v].snd <= deg[v].fst)
					{
						q.push(v);
						dead[v] = true;
					}
				}
			}
		}
		printf("%s\n", dead[x] ? "leave" : "stay");
	}
	return 0;
}

