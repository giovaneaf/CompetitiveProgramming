#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define MAXN 10010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
const int mod = 1000000;

ll fastExp(ll n, ll e)
{
	if(e == 1) return n;
	if(e&1) return (n*fastExp((n*n)%mod, e/2))%mod;
	return fastExp((n*n)%mod, e/2);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		int h, c, l;
		cin >> h >> c >> l;
		double hm, hc, hl;
		hm = n*h/100.0;
		hc = n*c/100.0;
		hl = l/100.0;
		double length = sqrt(hm*hm+hc*hc);
		printf("%.4f\n", hl*length);
	}
	return 0;
}