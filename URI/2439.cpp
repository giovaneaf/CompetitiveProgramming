/*
It's similar to the problem called Onibus but with a different recurrence relation,
you can do it in paper and find the recurrence.
Aqui a ideia é semelhante com a questão do ônibus discutida anteriormente porém com um padrão diferente, 
fazer os casos há mão e encontrar a recorrência.

This blog explain how to transform the recurrence relation into matrix: 
http://fusharblog.com/solving-linear-recurrence-for-programming-contest/
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; a++)
#define RFOR(a, b, c) for(int a = b; a >= c; a--)
#define mp(a, b) make_pair(a, b)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vii vector<ii>

const int N = 2;
const int mod = 1e9+7;

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
	ll n;
	while(cin >> n)
	{
		M[0][0] = 2; M[0][1] = 2;
		M[1][0] = 2; M[1][1] = 3;
		if(n == 1)
		{
			printf("12\n");
			continue;
		}
		expbysquaring(n-1);
		printf("%lld\n", (6*(ans[0][0] + ans[0][1] + ans[1][0] + ans[1][1]))%mod);
	}
}