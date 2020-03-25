/*
	Fast Modular Exponentiation O(log e) computing (x^e)%mod
	Implementation of Fast Modular Exponentiation
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;	// modulus given by the problem

ll fastPow(ll x, ll exp)
{
	ll ans = 1LL;
	while(exp > 0LL)
	{
		if(exp&1LL)
		{
			ans = (ans*x)%mod;
		}
		x = (x*x)%mod;
		exp >>= 1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	printf("%lld\n", fastPow(2, 10));	// calling 2^10
	return 0;
} 