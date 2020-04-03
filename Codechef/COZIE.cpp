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

#if TABLE
vector<int> phi(MAXN);

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

bool phiPrime(int n)
{
	return n == 3 || n == 4 || n == 6;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, q;
	while(cin >> n >> q)
	{
		int v[n];
		vi acc(n, 0);
		FOR(i, 0, n)
		{
			cin >> v[i];
		}
		acc[0] = (phiPrime(v[0]) ? 1 : 0);
		FOR(i, 1, n)
		{
			acc[i] = acc[i-1] + (phiPrime(v[i]) ? 1 : 0);
		}
		int l, r;
		FOR(i, 0, q)
		{
			cin >> l >> r;
			l--, r--;
			if(l > r)
				printf("0\n");
			else
			{
				printf("%d\n", acc[r] - (l == 0 ? 0 : acc[l-1]));
			}
		}
	}
	return 0;
}