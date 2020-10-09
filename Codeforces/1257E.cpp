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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define DEBUG 0

int sz[3];
ii v[MAXN];
int memo[MAXN][5];
int n;

int solve(int pos, int k)
{
	if(pos == n) return 0;
	if(memo[pos][k] == -1)
	{
		int ans = solve(pos+1, k) + (v[pos].snd != k);
		if(k < 2)
		{
			ans = min(ans, solve(pos, k+1));
		}
		memo[pos][k] = ans;
	}
	return memo[pos][k];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> sz[0] >> sz[1] >> sz[2])
	{
		n = 0;
		FOR(i, 0, 3)
		{
			FOR(j, 0, sz[i])
			{
				int x;
				cin >> x;
				v[n++] = mp(x, i);
			}
		}
		sort(v, v+n);
		if(DEBUG)
		{
			FOR(i, 0, n)
			{
				printf("%d %d\n", v[i].fst, v[i].snd);
			}
		}
		FOR(i, 0, n)
		{
			FOR(j, 0, 3)
			{
				memo[i][j] = -1;
			}
		}
		printf("%d\n", solve(0, 0));
	}
	return 0;
}

