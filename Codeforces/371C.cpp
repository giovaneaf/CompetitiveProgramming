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
#define MAXN 1010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define ITER 10000000

#define DEBUG 0

string s;
ll a, b, c;
ll ca, cb, cc;
ll na, nb, nc;
ll r;

bool can(ll mid)
{
	ll money = r;
	money -= max(0LL, mid*na - a)*ca;
	money -= max(0LL, mid*nb - b)*cb;
	money -= max(0LL, mid*nc - c)*cc;
	return money >= 0LL;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> s)
	{
		na = nb = nc = 0;
		for(char& c : s)
		{
			if(c == 'B')
				na++;
			else if(c == 'S')
				nb++;
			else
				nc++;
		}
		cin >> a >> b >> c;
		cin >> ca >> cb >> cc;
		cin >> r;
		ll l, h;
		l = 0;
		h = 1000000000000000LL;
		while(h - l > 1)
		{
			ll mid = l + (h-l)/2LL;
			if(can(mid))
				l = mid;
			else
				h = mid-1;
		}
		printf("%lld\n", can(h) ? h : l);
	}
	return 0;
}
