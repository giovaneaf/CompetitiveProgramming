/*
Binary search the answer and for each mid value(x) check if with this time (x),
C or less people can eat all the popcorn. Then update the pointers in binary search.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXN 100010
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

ll p[MAXN];
int n, c, t;

bool can(ll x)
{
	int cc = 0;
	int i = 0;
	while(i < n)
	{
		cc++;
		ll acc = 0LL;
		while(i < n && (acc+p[i]+t-1)/t <= x)
		{
			acc += p[i++];
		}
	}
	return cc <= c;
}

int main()
{
	while(cin >> n >> c >> t)
	{
		ll mx = -1;
		FOR(i, 0, n)
		{
			cin >> p[i];
			mx = max(mx, p[i]);
		}
		ll l = (mx+t-1)/t;
		ll r = 1e9;
		while(r - l > 1)
		{
			ll mid = (r+l)/2LL;
			if(can(mid))
				r = mid;
			else
				l = mid+1;
		}
		printf("%lld\n", can(l) ? l : r);
	}
	return 0;
}