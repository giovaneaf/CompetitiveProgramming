#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
const int mod = 1000000;
const double pi = atan(1)*4.0;

ll n, k;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		vector<ll> v(n);
		map<ll, int> m;
		FOR(i, 0, n)
		{
			cin >> v[i];
		}
		if(k == 1)
		{
			printf("%d\n", n);
			continue;
		}
		sort(v.begin(), v.end());
		FOR(i, 0, n)
		{
			m[v[i]] = i;
		}
		int ans = 0;
		FOR(i, 0, n)
		{
			if(v[i] == -1LL) continue;
			ans++;
			ll t = v[i]*k;
			if(m.find(t) != m.end()) v[m[t]] = -1LL;
		}
		printf("%d\n", ans);
	}
	return 0;
}