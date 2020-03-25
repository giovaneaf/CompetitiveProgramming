/*
    Sieve of Eratosthenes to find all primes until MAXN in O(n*log(log(n)))
    Implementation of Sieve of Eratosthenes
*/

#include <bits/stdc++.h>
using namespace std;


typedef long long ll; 

#define MAXN 100010

int spf[MAXN];

void Sieve()
{
    for(int i = 0; i < MAXN; ++i) spf[i] = i;
    spf[0] = spf[1] = -1;
    for(int i = 2; i < MAXN; ++i)
    {
        if(spf[i] == i) // Check if it is prime
        {
            for(ll j = (ll) i*i; j < MAXN; j += i)
            {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    Sieve();
    for(int i = 1; i < 101; ++i) // Show primes from 1 to 100
    {
        if(spf[i] == i)
            printf("%d ", i);
    }
    putchar('\n');
    return 0;
} 