#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

typedef long long int ll;

ll getSum(ll BITree[], int index)
{
    ll sum = 0;
 
    index = index + 1;

    while (index>0)
    {
        sum += BITree[index];
        index -= (index & -index);
    }
    return sum;
}
 

void updateBIT(ll BITree[], int n, int index, ll val)
{
    index = index + 1;
 
    while (index <= n)
    {
       BITree[index] += val;
       index += (index & -index);
    }
}

int main()
{
	int N;
	while(scanf("%d", &N) != EOF)
	{
		int K = 3;
		int array[N];
		int higher = -1;
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &array[N-1-i]);
			if(higher < array[N-1-i])
				higher = array[N-1-i];
		}
		ll dp[N][K];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < N; i++)
			dp[i][0] = 1;
		for(int p = 1; p < K; p++)
		{
			ll BIT[higher+1];
			for(int k = 0; k <= higher; k++)
				BIT[k] = 0;
			for(int i = 1; i < N; i++)
			{
				updateBIT(BIT, higher, array[i-1]-1, dp[i-1][p-1]);
				if(array[i]-2 >= 0)
					dp[i][p] += getSum(BIT, array[i]-2);
			}
		}
		ll sum = 0;
		for(int i = 0; i < N; i++)
			sum += dp[i][2];
		printf("%lld\n", sum);
	}
	return 0;
}