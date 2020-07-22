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
 
int n, m, s;
bool prime[MAXN];
vi primes;
 
void Sieve()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 4; i < MAXN; i += 2) prime[i] = false;
	primes.emplace_back(2);
	for(int i = 3; i < MAXN; i += 2)
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
	while(cin >> n)
	{
		int times = 0;
		while(n >= 4)
		{
			int m = sqrt(n);
			for(int i : primes)
			{
				if(prime[i] && prime[n-i])
				{
					n = n-2*i;
					times++;
					break;
				}
			}
		}
		printf("%d\n", times);
	}
	return 0;
} 