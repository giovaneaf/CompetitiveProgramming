#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 50010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vector<ll> v(n);
		FOR(i, 0, n) cin >> v[i];
		cin >> q;
		FOR(i, 0, q)
		{
			ll x;
			cin >> x;
			auto it = lower_bound(v.begin(), v.end(), x);
			ll a, b;
			a = -1, b = -1;
			if(it != v.begin())
			{
				--it;
				a = *it;
			}
			it = upper_bound(v.begin(), v.end(), x);
			if(it != v.end())
			{
				b = *it;
			}
			if(a == -1) printf("X ");
			else printf("%lld ", a);
			if(b == -1) printf("X\n");
			else printf("%lld\n", b);
		}
	}
    return 0;
}