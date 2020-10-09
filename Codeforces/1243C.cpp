#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 10000010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define DEBUG 0

int spf[MAXN];
int primes[MAXN];
int n;

void Sieve()
{
	FOR(i, 0, MAXN) spf[i] = i;
	for(ll i = 2; i < MAXN; ++i)
	{
		if(spf[i] == i)
		{
			primes[n++] = i;
			for(ll j = i*i; j < MAXN; j += i)
			{
				spf[j] = i;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n = 0;
	Sieve();
	ll num;
	while(cin >> num)
	{
		if(num == 1)
		{
			printf("1\n");
			continue;
		}
		ll gcd = -1;
		for(int i = 0; (ll) primes[i] <= num && i < n; ++i)
		{
			if(num%primes[i] == 0)
			{
				if(gcd == -1)
					gcd = primes[i];
				else
					gcd = __gcd((ll)primes[i], gcd);
				num /= primes[i];
				while(num%primes[i] == 0) num /= primes[i];
			}
		}
		if(num > 1)
		{
			if(gcd == -1)
					gcd = num;
			else
				gcd = __gcd(num, gcd);
		}
		printf("%lld\n", gcd);
	}
	return 0;
}

