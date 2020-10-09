#include <stdio.h>
 
int main()
{
	int t[100001];
	int v[100001];
	int dp[100001];
	for(int i = 0; i < 100001; i++)
	{
		t[i] = 0;
		dp[i] = 0;
	}
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &v[i]);
	}
	dp[N-1] = 1;
	t[v[N-1]]++;
	for(int i = N-2; i >= 0; i--)
	{
		if(t[v[i]] > 0)
		{
			dp[i] = dp[i+1];
		}
		else
		{
			t[v[i]]++;
			dp[i] = 1 + dp[i+1];
		}
	}
	for(int i = 0; i < M; i++)
	{
		int a;
		scanf("%d", &a);
		printf("%d\n", dp[a-1]);
	}
	return 0;
}