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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n, m;
		cin >> n >> m;
		vi adj[n];
		int mcc[n];
		FOR(i, 0, m)
		{
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].emplace_back(b);
		}
		vvi ans = scc(n, adj, mcc);
		int N = ans.size();
		if(N == 1)
		{
			printf("0\n");
			continue;
		}
		vi indeg(N, 0);
		vi outdeg(N, 0);
		FOR(i, 0, n)
		{
			int a, b;
			a = mcc[i];
			for(int x : adj[i])
			{
				b = mcc[x];
				if(a == b) continue;
				indeg[b]++;
				outdeg[a]++;
			}
		}
		int x, y;
		x = y = 0;
		FOR(i, 0, N)
		{
			if(indeg[i] == 0) x++;
			if(outdeg[i] == 0) y++;
		}
		printf("%d\n", max(x, y));
	}
    return 0;
}
