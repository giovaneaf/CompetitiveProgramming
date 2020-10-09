#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 210
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<ii> vii;

ll n, m, k, l;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> k >> l)
	{
		ll x = (l+k+m-1LL)/m;
		if(l+k > n || m*x > n)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n", x);
	}
	return 0;
}