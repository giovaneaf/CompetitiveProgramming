/*
You need to check each possible start (x) apart and reset the memoization table dp(i) that stores what is the minimum length
needed to patch the interval [i, x+n) and the transition is to get the minimum between put the patch 1 and go to
the next uncovered patch (can be used a binary search) or put the patch 2 and go to the next uncovered patch 
(can be used a binary search too). The expected time complexity is O((n^2)*log(n)).
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

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

int n, c, t1, t2, m, k;
vi acc;
vi memo;

int solve(int cur, int st)
{
	if(cur - st >= n) return 0;
	if(memo[cur] == -1)
	{
		auto it1 = upper_bound(acc.begin(), acc.end(), acc[cur] + t1);
		auto it2 = upper_bound(acc.begin(), acc.end(), acc[cur] + t2);
		int ans = min(t1 + solve((int) distance(acc.begin(), it1), st), t2 + solve((int) distance(acc.begin(), it2), st));
		memo[cur] = ans;
	}
	return memo[cur];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> c >> t1 >> t2)
	{
		int v[MAXN];
		FOR(i, 0, n) cin >> v[i];
		acc.assign(2*n, 0);
		FOR(i, 0, n)
			acc[i] = v[i];
		FOR(i, n, 2*n)
			acc[i] = c+v[i-n];
		int ans = -1;
		FOR(i, 0, n)
		{
			memo.assign(2*n, -1);
			int cur = solve(i, i);
			if(ans == -1 || ans > cur) ans = cur;
		}
		printf("%d\n", ans);
	}
    return 0;
}

