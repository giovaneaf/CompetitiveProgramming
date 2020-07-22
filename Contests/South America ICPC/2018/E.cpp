/*
Iterate over all sides of the polygon counter clockwise.
When you're processing a side you need to find which other side has greater than 180º degrees
with respect to horizontal (you can do it in O(n) with two pointers technique).
Then if you choose any combination of two sides that doesn't have side greater than 180º degrees the 
polygon will escape (you can count this for every side and this will count every combination exactly
once).
The answer will be all possible triples (Combination(n, 3)) - number of escaped triples counted.
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
#define MAXN 500010
#define MAXM 44100
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

struct Tvec
{
	ll x, y;
	Tvec(ll x = 0LL, ll y = 0LL) : x(x), y(y) {}
	ll operator^ (const Tvec& v) { return x*v.y - y*v.x; }
	Tvec operator- (const Tvec& v) { return Tvec(x-v.x, y-v.y); }
};

ll n;

inline int nxt(int a)
{
	return (a+1 == n ? 0 : a+1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vector<Tvec> v(n);
		FOR(i, 0, n)
		{
			cin >> v[i].x >> v[i].y;
		}
		ll ans = 0LL;
		int o, nxi, nxo;
		ll escaped;
		o = 1;
		nxo = 2;
		escaped = 0LL;
		FOR(i, 0, n)
		{
			nxi = nxt(i);
			while(((v[nxi] - v[i])^(v[nxo]-v[o])) >= 0LL)
			{
				o = nxt(o);
				nxo = nxt(nxo);
				escaped++;
			}
			ans += (escaped*(escaped-1))/2LL;
			escaped = max(0LL, escaped-1LL);
		}
		printf("%lld\n", (n*(n-1)*(n-2))/6-ans);
	}
	return 0;
}
