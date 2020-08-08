/*
	Presentation error... Live Archive is showing an yellow thing on this problem
*/

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
#define MAXN 1251
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n, m;
double memo[MAXN][MAXN];
int c[MAXN], w[MAXN], r[MAXN];

double solve(int pos, int rm)
{
	if(pos == n) return 15000.0;
	if(memo[pos][rm] == 20000)
	{
		double ans = (double) c[pos]/100.0*solve(pos+1, rm) - (double) w[pos]/100.0*solve(pos+1, rm);
		double tmp = solve(pos+1, rm);
		if(rm > 0) tmp = min(tmp, -solve(pos+1, rm-1));
		tmp *= (double) r[pos]/100.0;
		ans += tmp;
		memo[pos][rm] = ans;
	}
	return memo[pos][rm];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		cin >> n >> m;
		FOR(i, 0, n) cin >> c[i];
		FOR(i, 0, n) 
		{
			cin >> w[i];
			r[i] = 100 - c[i] - w[i];
		}
		FOR(i, 0, n)
		{			
			FOR(j, 0, m+1)
			{
				memo[i][j] = 20000.0;
			}
		}
		printf("Case #%d: %.3f\n", t+1, solve(0, m));
	}
	return 0;
}
