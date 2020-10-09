#include <iostream>
#include <cstdio>
#include <cstring>
 
int dp[3][100];
 
int Best(int i, int* v, int N, int last)
{
	if(i >= N)
		return 0;
	if(dp[last][i] != -1)
		return dp[last][i];
	else
	{
		if(v[i] == 0)
			return dp[0][i] = dp[1][i] = dp[2][i] = 1 + Best(i+1, v, N, 0);
		if(v[i] == 1)
		{
			if(last == 1)
				return dp[last][i] =  1 + Best(i+1, v, N, 0);
			else
				return dp[0][i] = dp[2][i] = Best(i+1, v, N, 1);
		}
		if(v[i] == 2)
		{
			if(last == 2)
				return dp[last][i] = 1 + Best(i+1, v, N, 0);
			else
				return dp[0][i] = dp[1][i] = Best(i+1, v, N, 2);
		}
		if(v[i] == 3)
		{
			if(last == 1)
				return dp[last][i] = Best(i+1, v, N, 2);
			if(last == 2)
				return dp[last][i] = Best(i+1, v, N, 1);
			if(dp[1][i] != -1 && dp[2][i] != -1)
				return dp[last][i] = std::min(dp[1][i], dp[2][i]);
			if(dp[1][i] != -1)	
				return dp[last][i] = std::min(dp[1][i], Best(i+1, v, N, 1));
			if(dp[2][i] != -1)
				return dp[last][i] = std::min(Best(i+1, v, N, 2), dp[2][i]);
			return dp[last][i] = std::min(Best(i+1, v, N, 2), Best(i+1, v, N, 1));
		}
	}
}
 
int main()
{
	int N;
	scanf("%d", &N);
	int v[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < N; j++)
			dp[i][j] = -1;
	printf("%d\n", Best(0, v, N, 0));
	return 0;
}
