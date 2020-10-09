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
#define MAXN 3010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 10000000
 
#define DEBUG 0

int n;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int memo[MAXN][2][2];

int solve(int pos, bool l, bool r)
{
	if(pos == n-1) return (l ? b[pos] : a[pos]);
	if(memo[pos][l][r] == -1)
	{
		int joy;
		if(l && r) joy = c[pos];
		else if(l || r) joy = b[pos];
		else joy = a[pos];
		int ans = joy + max(solve(pos+1, !r, false), solve(pos+1, !r, true));
		memo[pos][l][r] = ans;
	}
	return memo[pos][l][r];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		memset(memo, -1, sizeof(memo));
		FOR(i, 0, n) cin >> a[i];
		FOR(i, 0, n) cin >> b[i];
		FOR(i, 0, n) cin >> c[i];
		printf("%d\n", max(solve(0, false, true), solve(0, false, false)));
	}
	return 0;
}