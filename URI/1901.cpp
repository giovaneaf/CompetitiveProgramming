#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 60
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m;
bool seen[1010];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		memset(seen, false, sizeof(seen));
		int ans = 0;
		int M[210][210];
		FOR(i, 0, n) FOR(j, 0, n) cin >> M[i][j];
		FOR(i, 0, 2*n)
		{
			int r, c;
			cin >> r >> c;
			r--, c--;
			if(!seen[M[r][c]])
			{
				seen[M[r][c]] = true;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
