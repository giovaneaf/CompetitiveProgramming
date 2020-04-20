#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vii vector<ii>

const int N = 2;
const ll mod = 1e6;

ll M[2][2];
ll ans[2][2];

inline void ones(ll y[2][2])
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			y[i][j] = (i == j ? 1LL : 0LL);
}

void mul(int a)
{
	ll tmp[2][2];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			tmp[i][j] = 0LL;
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

void expbysquaring(ll L)
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
	ll n, k, l;
	while(cin >> n >> k >> l)
	{
		M[0][0] = 0; M[0][1] = 1;
		M[1][0] = l%mod; M[1][1] = k%mod;
		expbysquaring(n/5);
		printf("%06lld\n", ans[1][1]);
	}
}