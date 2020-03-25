#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 210
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<ii> vii;

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	bool hasP = false;
	int dp[n];
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == 'P')
		{
			hasP = true;
			break;
		}
	}
	if(!hasP)
	{
		printf("%d\n", n-1);
	}
	else
	{
		int ans = 0;
		for(int gap = 2; gap < n; ++gap)
		{
			int gcd = __gcd(gap, n);
			if(gcd == 1) continue;
			if(dp[gcd] != -1)
			{
				ans += dp[gcd];
				continue;
			}
			for(int i = 0; i < gcd; ++i)
			{
				bool can = true;
				for(int j = i; j < n; j += gcd)
				{
					if(s[j] == 'P')
					{
						can = false;
						break;
					}
				}
				if(can)
				{
					ans++;
					dp[gcd] = 1;
					break;
				}
			}
			if(dp[gcd] == -1) dp[gcd] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}