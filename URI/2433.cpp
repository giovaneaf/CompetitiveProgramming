#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
const ll mod = 1000000007LL;
int n, k;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		vector<ll> v(n);
		FOR(i, 0, n) cin >> v[i];
		sort(v.begin(), v.end());
		ll ans = INFLL;
		int cur = 0;
		while(cur+1 < n-k)
		{
			cur++;
		}
		while(cur < n)
		{
			ans = min(ans, v[cur] - v[cur-(n-k-1)]);
			cur++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}