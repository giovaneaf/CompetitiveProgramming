#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 300010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;
ll n, m, a;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m >> a)
	{
		if(a%n == 0 || a%m == 0) 
			printf("1\n");
		else
		{
			ll na = n*m-a;
			ll y;
			bool can = false;
			for(ll x = 1LL; x <= n; ++x)
			{
				if(a%x == 0)
				{
					y = a/x;
					if(y <= m && x*y == a)
					{
						printf("2\n");
						can = true;
						break;
					}
				}
				if(na%x == 0)
				{
					y = na/x;
					if(y <= m && x*y == na)
					{
						printf("2\n");
						can = true;
						break;
					}
				}
			}
			if(!can) printf("3\n");
		}
	}
	return 0;
}