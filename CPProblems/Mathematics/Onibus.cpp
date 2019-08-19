/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/1474
There are two possibilites: You can be in the middle (building a bus of size 10) or in a ¬middle (you can choose between
bus or microbus), if you're in the middle then the unique way is to go to the one ¬middle (you already picked the bus color)
if you are in a ¬middle then there are L possibilities going to a middle (bus) and K possibilities going to ¬middle.
Because N is too big it's needed to do an algorithm better than O(N). Therefore, you can use a recurrence relation matrix
and use fast matrix exponentiation to solve this problem.

This blog explain how to transform the recurrence relation into matrix: 
http://fusharblog.com/solving-linear-recurrence-for-programming-contest/
*/

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