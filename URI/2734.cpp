#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		vector<int> v(2*n);
		int maxSum = 0;
		for(int i = 0; i < 2*n; ++i)
		{
			cin >> v[i];
			maxSum += v[i];
		}
		bool dp[210][1010];
		bool cp[210][1010];
		for(int i = 0; i <= v.size(); ++i)
		{
			for(int j = 0; j <= maxSum; ++j)
			{
				cp[i][j] = (j == 0);
			}
		}
		for(int k = 1; k <= n; ++k)
		{
			for(int i = 0; i <= v.size(); ++i)
				dp[i][0] = false;
			for(int i = 0; i <= maxSum; ++i)
				dp[0][i] = false;
			for(int i = 1; i <= v.size(); ++i)
			{
				for(int j = 1; j <= maxSum; ++j)
				{
					dp[i][j] = dp[i-1][j];
					if(v[i-1] <= j)
					{
						dp[i][j] = dp[i][j] || cp[i-1][j - v[i-1]];
					}
				}
			}
			for(int i = 0; i <= v.size(); ++i)
			{
				for(int j = 0; j <= maxSum; ++j)
				{
					cp[i][j] = dp[i][j];
				}
			}
		}
		/*for(int i = 0; i <= v.size(); ++i)
		{
			for(int j = 0; j <= maxSum; ++j)
			{
				cout << dp[i][j] << " ";
			}
			putchar('\n');
		}*/
		int lbest = 0;
		for(int i = 1; i <= maxSum/2; ++i)
			if(dp[v.size()][i])
				lbest = i;
		cout << maxSum - 2*lbest << '\n';
	}
	return 0;
}