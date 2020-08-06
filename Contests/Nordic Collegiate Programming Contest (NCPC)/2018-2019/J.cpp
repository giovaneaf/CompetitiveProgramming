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
#define MAXN 2510
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007;

ll a, b, c, d;

ll getCount(ll x)
{
	ll val = 1 + 8*x;
	ll sqrtv = sqrt(1+8*x);
	if(sqrtv*sqrtv != (1+8*x) || ((1LL+sqrtv)&1LL)) return -1LL;
	return (1LL+sqrtv)/2LL;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> a >> b >> c >> d)
	{
		ll num0 = getCount(a);
		ll num1 = getCount(d);
		ll n = getCount(a+b+c+d);
		if(num0 + num1 != n)
		{
			if(n == 1)
			{
				num0 = 1;
				num1 = 0;
			}
			else if(b + c == 0)
			{
				if(a > 0)
				{
					num1 = 0;
				}
				else
				{
					num0 = 0;
				}
			}
		}
		//printf("%lld %lld\n", num0, num1);
		if(num0 == -1LL || num1 == -1LL)
		{
			printf("impossible\n");
			continue;
		}
		string ans;
		FOR(i, 0, n)
		{
			if(b >= num1 && num0 > 0)
			{
				num0--;
				b -= num1;
				ans += '0';
			}
			else if(c >= num0 && num1 > 0)
			{
				num1--;
				c -= num0;
				ans += '1';
			}
			else if(num0 > 0)
			{
				num0--;
				b -= num1;
				ans += '0';
			}
			else
			{
				num1--;
				c -= num0;
				ans += '1';
			}
		}
		printf("%s\n", (b == 0 && c == 0) ? ans.c_str() : "impossible");
	}
	return 0;
}
