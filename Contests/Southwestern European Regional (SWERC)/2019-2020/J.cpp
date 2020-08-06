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
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n;
int v[MAXN];
ll cat[MAXN];
 
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
 
ll modInverse(ll b, ll m)
{
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
 
    if (g != 1LL)
        return -1LL;
 
    return (x%m + m) % m;
}
 
ll catalan(int n)
{
	if(n == 0) return 1LL;
	if(cat[n] == -1LL) cat[n] = (((2*(2*n-1)*catalan(n-1))%MOD)*modInverse(n+1, MOD))%MOD;
	return cat[n];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(cat, -1LL, sizeof(cat));
	cin >> n;
	ll ans = 1LL;
	FOR(i, 0, n)
	{
		cin >> v[i];
	}
	stack<int> s;
	FOR(i, 0, n)
	{
		if(s.empty())
		{
			s.push(v[i]);
		}
		else
		{
			while(s.size() && s.top() > v[i])
			{
				int cn = 1;
				int lst = s.top();
				s.pop();
				while(s.size() && lst == s.top())
				{
					lst = s.top();
					s.pop();
					cn++;
				}
				ans = (ans * catalan(cn))%MOD;
			}
			s.push(v[i]);
		}
	}
	while(s.size())
	{
		int cn = 1;
		int lst = s.top();
		s.pop();
		while(s.size() && lst == s.top())
		{
			lst = s.top();
			s.pop();
			cn++;
		}
		ans = (ans * catalan(cn))%MOD;
	}
	printf("%lld\n", ans);
	return 0;
}