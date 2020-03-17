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
#define MAXN 2000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
#define TABLE 1

ll n, t;

#if TABLE
vector<int> phi(MAXN);
vector<ll> depth(MAXN);

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

int depthphi(int n)
{
	if(n == 1) return depth[n] = 0;
	if(depth[n] == -1)
		depth[n] = 1 + depthphi(phi[n]);
	return depth[n];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	phi_1_to_n(MAXN-1);
	fill(depth.begin(), depth.end(), -1LL);
	depth[0] = 0;
	FOR(i, 1, MAXN)
	{
		if(depth[i] == -1)
		{
			depthphi(i);
		}
	}
	FOR(i, 1, MAXN)
	{
		depth[i] += depth[i-1];
	}
	while(cin >> t)
	{
		int a, b;
		while(t--)
		{
			cin >> a >> b; 
			printf("%lld\n", depth[b] - depth[a-1]);
		}
	}
	return 0;
}