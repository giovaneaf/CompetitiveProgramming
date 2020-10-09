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
const double pi = atan(1)*4.0;

int n, f;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, t;
	while(cin >> n >> t)
	{
		vector<ll> v(n+1);
		v[0] = 0;
		for(int i = 1; i <= n; ++i)
		{
			cin >> v[i];
			v[i] += v[i-1];
		}
		int mx = 0;
		for(int i = 0; i < n; ++i)
		{
			auto it = upper_bound(v.begin(), v.end(), t+v[i]);
			it--;
			mx = max(mx, (int) distance(v.begin()+i, it));
		}
		printf("%d\n", mx);
	}
	return 0;
}