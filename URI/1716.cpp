#include <bits/stdc++.h>

#define INF 1e9
#define MAXN 100001

using namespace std;

typedef long long ll;

int n, e, c;

bitset<MAXN> isPrime;
vector<int> Prime;
ll phin;

void sieve()
{
	isPrime.set();
	isPrime.reset(0);
	isPrime.reset(1);
	for(int i = 4; i < MAXN; i += 2)
		isPrime.reset(i);
	for(int i = 3; i < MAXN; i += 2)
	{
		if(isPrime.test(i))
		{
			Prime.push_back(i);
			if((ll) i*i >= MAXN)
	        {
	            continue;
	        }
			for(int j = i*i; j < MAXN; j += i)
			{
				isPrime.reset(j);
			}
		}
	}
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
 
ll modInverse(ll b, ll m)
{
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
 
    if (g != 1LL)
        return -1LL;
 
    return (x%m + m) % m;
}

ll fastexp(ll x, ll n, ll mod)
{
	if(n == 0) return 1LL;
	if(n&1) return (x*fastexp((x*x)%mod, n/2, mod))%mod;
	return fastexp((x*x)%mod, n/2, mod);
}

int main()
{
    sieve();
	int n, e, c;
	while(cin >> n >> e >> c)
	{
	    int sqrtn = sqrt(n);
		phin = e+1;
		for(int i = 0; Prime[i] <= sqrtn; ++i)
		{
		    if(n%Prime[i] == 0)
			{
				int q = n/Prime[i];
				if(isPrime.test(q))
				{
					ll auxphin = ((ll) (q-1))*(Prime[i]-1);
					if(auxphin > (ll) e)
					{
						phin = auxphin;
						break;
					}
				}
			}
		}
		ll d = modInverse((ll) e, phin);
		cout << fastexp((ll) c, d, n) << "\n";
	}
	return 0;
}