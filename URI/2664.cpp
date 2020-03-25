#include <stdio.h>
#include <algorithm>

#define mod 1000000007

using namespace std;

typedef long long int ll;

int T, M, N;

ll dp[51][100010];

ll B(int idx, int size)
{
	if(idx < M || idx > N)
		return 0;
	if(size == T-1)
		return 1;
	if(dp[size][idx] != -1)
		return dp[size][idx];
	return dp[size][idx] = (B(idx+1, size + 1) + B(idx-1, size + 1))%mod;
}

int main()
{
	scanf("%d %d %d", &T, &M, &N);
	for(int i = 1; i <= T; i++)
		for(int j = M; j <= N; j++)
			dp[i][j] = -1;
	ll ans = 0;
	for(int i = M; i <= N; i++)
	{
		ans += (B(i+1, 1) + B(i-1, 1));
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}