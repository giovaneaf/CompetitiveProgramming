#include <bits/stdc++.h>

#define INF 1000000000
#define MAXN 100010

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

string s;
int dp[40][40];

int solve(int l, int r)
{
	if(l > r) return 1;
	if((r-l+1)%3) return 0;
	if(dp[l][r] == -1)
	{
		int ans = 0;
		int nl, nm, nr;
		for(int i = l+1; i <= r; ++i)
		{
			for(int j = i+1; j <= r; ++j)
			{
				int red = (s[l] == 'R') + (s[i] == 'R') + (s[j] == 'R');
				if(red > 1) continue;
				nl = solve(l+1, i-1);
				nm = solve(i+1, j-1);
				nr = solve(j+1, r);
				ans += (nl*nm*nr);
			}
		}
		dp[l][r] = ans;
	}
	return dp[l][r];
}

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		int n;
		cin >> n;
		cin >> s;
		memset(dp, -1, sizeof(dp));
		printf("Case %d: %d\n", t, solve(0, n-1));
	}
	return 0;
}

