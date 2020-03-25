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
vector<ll> acc(MAXN);
 
void fillphi(int n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
			phi[i] -= phi[i] / i;
            for (int j = i+i; j <= n; j += i)
			{
                phi[j] -= phi[j] / i;
			}
        }
    }
}
 
#else
 
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
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
 
int t, n;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	fillphi(MAXN-1);
	fill(acc.begin(), acc.end(), 0LL);
	FOR(i, 1, MAXN) 
    {
		for (int j = 2; i*j<MAXN; ++j) 
            acc[i*j] += i*phi[j];  
    } 
	FOR(i, 2, MAXN) 
		acc[i] += acc[i-1];
	while(cin >> n)
	{
		if(n == 0) break;
		printf("%lld\n", acc[n]);
	}
	return 0;
} 