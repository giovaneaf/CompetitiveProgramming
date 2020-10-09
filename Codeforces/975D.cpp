#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, a, b;
	cin >> n >> a >> b;
	unordered_map<ll, ll> qty;
	map<pair<ll, ll>, ll> m;
	ll ans = 0LL;
	for(int i = 0; i < n; ++i)
	{
		ll x, vx, vy;
		cin >> x >> vx >> vy;
		ll val = a*vx - vy;
		ans += qty[val] - m[{vx, vy}];
		qty[val]++;
		m[{vx, vy}]++;
	}
	cout << 2LL*ans << "\n";
    return 0;
}
