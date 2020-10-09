#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAXN 200
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define DEBUG 0

int enter[MAXM];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while(cin >> n >> m)
	{
		vector<ll> v(n);
		FOR(i, 0, n) cin >> v[i];
		sort(v.begin(), v.end());
		vector<ll> toSum(n, 0LL);
		FOR(i, 0, m)
		{
			ll x = v[i];
			for(int j = i+m; j < n; j += m)
			{
				toSum[j] = x;
				x += v[j];
			}
		}
		ll ans = 0LL;
		FOR(i, 0, n)
		{
			if(i > 0) putchar(' ');
			ans += v[i] + toSum[i];
			printf("%lld", ans);
		}
		putchar('\n');
	}
	return 0;
}

