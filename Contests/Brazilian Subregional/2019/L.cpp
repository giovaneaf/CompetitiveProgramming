/*
You need to compute the number of odd numbers in n-th pascal triangle line.
The answer is 2^(nº of bits turned on in binary representation of n).
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

int main()
{
	long long n;
	while(cin >> n)
	{
		ll bits = 0LL;
		for(ll i = 0; (1LL << i) <= n; ++i)
		{
			if(n & (1LL << i))
			{
				bits++;
			}
		}
		ll ans = 1LL;
		FOR(i, 0, bits)
			ans *= 2LL;
		printf("%lld\n", ans);
	}
	return 0;
}