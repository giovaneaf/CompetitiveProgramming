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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
#define TABLE 1

ll n, sum;

#if TABLE
vector<int> phi(MAXN);
vector<ll> acc(MAXN);

void phi_1_to_n(int n) {
    phi[0] = 0;
    phi[1] = 1;
	acc[0] = 0;
	acc[1] = 2;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
		acc[i] = phi[i] + acc[i-1];
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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	sum = 1LL;
	phi_1_to_n(MAXN-1);
	while(cin >> n)
	{
		if(n == 0) break;
		if(n == 1) printf("0/1\n");
		else if(n == 2) printf("1/1\n");
		else
		{
			auto it = lower_bound(acc.begin(), acc.end(), n);
			it--;
			n -= *it;
			it++;
			int idx = distance(acc.begin(), it);
			int a = 0;
			while(n > 0)
			{
				a++;
				if(__gcd(a, idx) == 1) n--;
			}
			printf("%d/%d\n", a, idx);
		}
	}
	return 0;
}