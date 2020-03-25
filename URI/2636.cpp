#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1000010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

//int n, m, s;

vi primes;


void Sieve()
{
	vb prime(MAXN, true);
	prime[0] = prime[1] = false;
	for(int i = 2; i < MAXN; ++i)
	{
		if(prime[i])
		{
			primes.emplace_back(i);
			for(ll j = (ll) i*i; j < MAXN; j += i) prime[j] = false;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	Sieve();
	ll n;
	while(cin >> n && n)
	{
		printf("%lld = ", n);
		ll ans[2];
		int i = 0;
		for(int v : primes)
		{
			if((n%v) == 0)
			{
				ans[i++] = (ll) v;
				n /= v;
				if(i == 2) break;
			}
		}
		printf("%lld x %lld x %lld\n", ans[0], ans[1], n);
	}
	return 0;
} 