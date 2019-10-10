/*
Given n, when you choose a jump with size x then you can simulate it as you're jumping gcd(n, x), try it out.
The number of possible gcd's for n is the #divisors of n.
A good aproximation for #divisors for n is the cube root of n.
Given the gap = gcd(n, x) you can simulate for each starting point from 0 to gap-1 and check if you'll pass only
in rocks, if at least one starting point is true then the answer is 1 otherwise is 0, store this gap in a memoization
table. (This step requires O(n)).
Since there are approximately cube root of n different gaps the complexity is O(n*n^(1/3)) = O(n^(4/3)) and this is
enough.
*/
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
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(cin >> s)
	{
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
	}
	return 0;
}