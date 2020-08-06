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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007;
const int maxn = sqrt(mod)+1;

int n, k;

vi prime(maxn);

void Sieve()
{
	vb isPrime(maxn, true);
	n = 0;
	prime[n++] = 2;
	for(int i = 4; i < maxn; i += 2)
		isPrime[i] = false;
	for(int i = 3; i < maxn; i += 2)
	{
		if(isPrime[i])
		{
			prime[n++] = i;
			for(int j = i*i; j < maxn; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
		
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	Sieve();
	while(cin >> k)
	{
		if(k == 1)
		{
			printf("no\n");
			continue;
		}
		bool isFF = true;
		FOR(i, 0, n)
		{
			if((k%prime[i]) == 0)
			{
				while((k%prime[i]) == 0)
				{
					k /= prime[i];
				}
				if(k > 1)
				{
					isFF = false;
					break;
				}
			}
			if(prime[i]*prime[i] > k)
				break;
		}
		printf("%s\n", isFF ? "yes" : "no");
	}
	return 0;
}

