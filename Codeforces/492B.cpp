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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, l;
	while(cin >> n >> l)
	{
		vector<int> v(n);
		FOR(i, 0, n) cin >> v[i];
		sort(v.begin(), v.end());
		double ans = max(v[0], l-v[n-1]);
		for(int i = 0; i < n-1; ++i)
		{
			ans = max(ans, (v[i+1]-v[i])/2.0);
		}
		printf("%.10f\n", ans);
	}
	return 0;
}