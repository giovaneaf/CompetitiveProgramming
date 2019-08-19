/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/2291
Using Sieve Of Eratosthenes you can store the smallest prime factor of each number to decompose the number n in prime
factor in O(log(n)), with the prime factor you can compute the sum of divisors with the geometric progression formula.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 1000010

int spf[MAXN];

ll memo[MAXN];

void sieve()
{
	for(int i = 0; i < MAXN; ++i)
		spf[i] = i;
	for(int i = 4; i < MAXN; i += 2)
		spf[i] = 2;
	for(int i = 3; i*i < MAXN; i += 2) 
	{
		if(spf[i] == i)
		{
			for(int j = i*i; j < MAXN; j += i)
			{
				if(spf[j] == j)
				{
					spf[j] = i;
				}
			}
		}
	}
}

ll sum(int n)
{
    ll s = 1;
    while(n > 1)
    {
        int cnt = 0;
        int curPrime = spf[n];
        while(spf[n] == spf[n/spf[n]])
        {
            cnt++;
            n = n/spf[n];
        }
        cnt++;
        s *= ((ll) round(pow(curPrime, cnt+1)) - 1)/(curPrime-1);
        n = n/spf[n];
    }
    return s;
}

int main()
{
	sieve();
	memo[1] = 1LL;
	for(int i = 2; i < MAXN; ++i)
	{
	    memo[i] = memo[i-1] + sum(i);
	}
	int n;
	scanf("%d", &n);
	while(n)
	{
	    printf("%lld\n", memo[n]);
		scanf("%d", &n);
	}
	return 0;
}