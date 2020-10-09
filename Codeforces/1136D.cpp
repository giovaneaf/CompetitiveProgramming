#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 300010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n, m;
int v[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> v[i];
		v[i]--;
	}
	vi adj[n];
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
	}
	int cnt = 0;
	int tgt = v[n-1];
	vi can(n, true);
	RFOR(i, n-2, 0)
	{
		int cur = v[i];
		bool has = false;
		int c = 0;
		FOR(j, 0, adj[cur].size())
		{
			int u = adj[cur][j];
			if(u == tgt) has = true;
			else if(!can[u]) c++;
		}
		if(!has || c != cnt)
		{
			can[cur] = false;
			cnt++;
		}
	}
	printf("%d\n", n-1-cnt);
	return 0;
}