/*
Here you can use dp(i, j, k) where i is the current row, j is the current column and k is if the current row is flipped
So you can solve for 'G' or 'B' only because you can choose because you can flip rows.
I'll solve for 'G' for example. M[i][j] is the current value (not flipped) at position i, j.
dp(i, j, 0) = (M[i][j] == 'G'), if i or j = 0
dp(i, j, 1) = (M[i][j] == 'B'), if i or j = 0
dp(i, j, 0) = 0, if (M[i][j] == 'B')
dp(i, j, 1) = 0, if (M[i][j] == 'G')
dp(i, j, 0) = 1 + min(dp(i, j-1, 0), bestRow(i, j)), if (M[i][j] == 'G')
dp(i, j, 1) = 1 + min(dp(i, j-1, 1), bestRow(i, j)), if (M[i][j] == 'B')
where bestRow(i, j) = max(min(dp(i-1, j, 0), dp(i-1, j-1, 0)), min(dp(i-1, j, 1), dp(i-1, j-1, 1)))
Basically you need to force the left to be of the same type (row is flipped or not) and for the row above
you can choose the best between beeing fliped or not.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int n, m;

int dp[MAXN][MAXN][2];
string s[MAXN];

int solve(char c)
{
	int ans = 1;
	FOR(i, 0, n)
	{
		dp[i][0][0] = (s[i][0] == c);
		dp[i][0][1] = dp[i][0][0]^1;
	}
	FOR(j, 0, m)
	{
		dp[0][j][0] = (s[0][j] == c);
		dp[0][j][1] = dp[0][j][0]^1;
	}
	int bestRow;
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			bestRow = max(min(dp[i-1][j][0], dp[i-1][j-1][0]), min(dp[i-1][j][1], dp[i-1][j-1][1]));
			if(s[i][j] != c)
			{
				dp[i][j][0] = 0;
				dp[i][j][1] = 1 + min(dp[i][j-1][1], bestRow);
				ans = max(ans, dp[i][j][1]);
			}
			else
			{
				dp[i][j][1] = 0;
				dp[i][j][0] = 1 + min(dp[i][j-1][0], bestRow);
				ans = max(ans, dp[i][j][0]);
			}
		}
	}
	return ans*ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		FOR(i, 0, n)
		{
			cin >> s[i];
		}
		printf("%d\n", solve('G'));
	}
	return 0;
}

