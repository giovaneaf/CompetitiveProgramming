#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 100010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;
int n, sz;
int spf[MAXN];
int prime[MAXN];
bool used[MAXN];

void Sieve()
{
	FOR(i, 2, MAXN) spf[i] = i;
	for(int i = 4; i < MAXN; i += 2) spf[i] = 2;
	prime[0] = 2;
	sz = 1;
	for(int i = 3; i < MAXN; i += 2)
	{
		if(spf[i] == i)
		{
			prime[sz++] = i;
			for(ll j = (ll)i*i; j < MAXN; j += i)
			{
				spf[j] = min(spf[j], i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	Sieve();
	while(cin >> n)
	{
		memset(used, false, sizeof(used));
		int auxn = n;
		while(auxn > 1) 	// n is square free so n = p1*p2*p3*...*pk
		{
			used[spf[auxn]] = true;
			auxn /= spf[auxn];
		}
		FOR(i, 0, sz) 		// find the first prime that doesn't divide n
		{
			assert(prime[i] < n);
			if(!used[prime[i]])
			{
				printf("%d\n", prime[i]);
				break;
			}
		}
	}
	return 0;
}
