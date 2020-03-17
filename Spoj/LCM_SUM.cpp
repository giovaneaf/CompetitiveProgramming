// ∑LCM(i, n) = ((∑(d * ETF(d)) + 1) * n) / 2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
#define TABLE 1

#if TABLE
vector<ll> phi(MAXN);

void phi_1_to_n(int n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

#else

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

#endif

int n, t;

ll solve(int n)
{
	if(n == 1) return 1;
	ll ans = 2LL;
	int sqr = sqrt(n);
	FOR(i, 2, sqrt(n))
	{
		if(n%i == 0)
		{
			ll comp = n/i;
			ans += (ll)i*phi[i] + comp*phi[comp];
		}
	}
	if(sqr*sqr == n)
	{
		ans += sqr*phi[sqr];
	}
	ans += n*phi[n];
	ans = (n*ans)/2LL;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	phi_1_to_n(MAXN-1);
	while(cin >> t)
	{
		while(t--)
		{
			cin >> n;
			printf("%lld\n", solve(n));
		}
	}
	return 0;
}