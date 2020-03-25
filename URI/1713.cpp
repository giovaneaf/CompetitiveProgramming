#include <stdio.h>
#include <math.h>

#define mod 10000

typedef unsigned long long int ull;

int N, S, T;
ull L;
int M[100][100];
int ans[100][100];

void ones(int y[100][100])
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			y[i][j] = (i == j ? 1 : 0);
}

void mul(int a)
{
	int tmp[100][100];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			tmp[i][j] = 0;
	if(a == 0)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				for(int k = 0; k < N; k++)
				{
					tmp[i][j] += (M[i][k]*M[k][j]);
					tmp[i][j] %= mod;
				}
			}
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				M[i][j] = tmp[i][j];
	}
	else
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				for(int k = 0; k < N; k++)
				{
					tmp[i][j] += (ans[i][k]*M[k][j]);
					tmp[i][j] %= mod;
				}
			}
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				ans[i][j] = tmp[i][j];
	}
}

void expbysquaring()
{
	ones(ans);
	while(L > 0)
	{
		if(L & 1)
			mul(1);
		L >>= 1;
		mul(0);
	}
}

int main()
{
	while(scanf("%d %llu", &N, &L) != EOF)
	{
		scanf("%d %d", &S, &T);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				M[i][j] = 0;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				int a;
				scanf("%d", &a);
				M[i][a-1]++;
			}
		}
		expbysquaring();
		printf("%d\n", ans[S-1][T-1]);
	}
	return 0;
}