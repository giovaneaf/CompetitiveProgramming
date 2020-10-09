#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <stdlib.h>
#include <math.h>
#include <tuple>

using namespace std;

int dp[51][2];
int N;
int s[51];
int acc[51];

int main()
{
	scanf("%d", &N);
	int total = 0;
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &s[i]);
		total += s[i];
	}
	acc[N-1] = s[N-1];
	for(int i = N-2; i >= 0; i--)
		acc[i] = acc[i+1] + s[i];
	dp[N-1][0] = dp[N-1][1] = s[N-1];
	for(int i = N-2; i >= 0; i--)
	{
		for(int j = 0; j < 2; j++)
		{
			dp[i][j] = max(s[i] + acc[i+1] - dp[i+1][j == 0 ? 1 : 0] , dp[i+1][j]);
		}
	}
	printf("%d %d\n", total - dp[0][1], dp[0][1]);
	return 0;
}