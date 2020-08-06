#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 300010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
 
int n, m;
 
inline ll f(ll a, ll b, ll c)
{
	return a*a + b*b + c*c + 7*min(a,min(b,c));
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	while(n--)
	{
		ll d;
		vector<ll> v(3);
		cin >> v[0] >> v[1] >> v[2] >> d;
		sort(v.begin(), v.end());
		ll ans = f(v[0], v[1], v[2]+d);
		if(d > v[1] - v[0])
		{
			d -= (v[1] - v[0]);
			v[0] = v[1];
			if(d > 2*(v[2] - v[1]))
			{
				d -= 2*(v[2] - v[1]);
				v[0] = v[1] = v[2];
				ll gap = d/3;
				v[0] += gap;
				v[1] += gap;
				v[2] += gap;
				d = d%3;
				while(d > 0)
				{
					v[2]++;
					d--;
				}
			}
			else
			{
				ll gap = d/2;
				v[0] += gap;
				v[1] += gap;
				if(d&1)
				{
					v[2]++;
				}
			}
		}
		else
			v[0] += d;
		printf("%lld\n", max(ans, f(v[0], v[1], v[2])));
	}
	return 0;
}