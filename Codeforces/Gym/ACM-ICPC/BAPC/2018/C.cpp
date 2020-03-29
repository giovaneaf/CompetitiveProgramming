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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL

int v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> v)
	{
		int sqrtv = sqrt(v)+1;
		ll ans = INFLL, z;
		FOR(x, 1, sqrtv)
		{
			FOR(y, 1, sqrtv)
			{
				z = v/(x*y);
				if(x*y*z >= v)
					ans = min(ans, 2*(x*y + x*z + y*z));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}