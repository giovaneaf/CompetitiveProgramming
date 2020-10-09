#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int dp[4010];
 
int B(int N, int* v)
{
	if(N < v[0] && N < v[1] && N < v[2])
		return -1000000000;
	if(dp[N] != -1)
		return dp[N];
	int ans = -1000000000;
	if(N == v[0] || N == v[1] || N == v[2])
	{
		ans = 1;
	}
	for(int i = 1; i < N; i++)
	{
		ans = max(ans, B(i, v) + B(N - i, v));
	}
	return dp[N] = ans;
}
 
int main()
{
	int N;
	int v[3];
	scanf("%d", &N);
	for(int i = 0; i < 3; i++)
		scanf("%d", &v[i]);
	for(int i = 0; i <= N; i++)
		dp[i] = -1;
	printf("%d\n", B(N, v));
	return 0;
}