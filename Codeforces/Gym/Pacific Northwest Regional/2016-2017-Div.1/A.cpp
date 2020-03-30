// The answer is 26 - LIS (Longest Increasing Subsequence)
// Time Complexity: O(n²) - LIS "easy" DP solution

// LIS here: https://www.geeksforgeeks.org/longest-increasing-subsequence/ - O(n²)
// or here: 
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/ - O(n*log(n))

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define LOGMAXN 20
#define INF 1000000010

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(cin >> s)
	{
		vector<int> dp;
		dp.assign(s.size(), 1);
		for(int i = 1; i < s.size(); ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				if(s[j] < s[i])
					dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
		cout << 26 - *max_element(dp.begin(), dp.end()) << "\n";
	}
	return 0;
}