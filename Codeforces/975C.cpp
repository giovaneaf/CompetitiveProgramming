#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i = 0; i < n; ++i)

int main()
{
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	REP(i, n)
	{
		cin >> a[i];
	}
	vector<ll> dmg(q);
	REP(i, q)
	{
		cin >> dmg[i];
	}
	vector<ll> sum(n);
	sum[0] = a[0];
	REP(i, n-1)
	{
		sum[i+1] = sum[i] + a[i+1];
	}
	pair<ll, ll> p;
	p = make_pair(a[0], 0);
	REP(i, q)
	{
		ll d = dmg[i];
		ll pos = p.second;
		ll health = p.first;
		ll ans;
		if(health > d)
		{
			cout << (n - pos) << "\n";
			p = make_pair(health - d, pos);
		}
		else if(health == d)
		{
			if(pos == n-1)
			{
				ans = n;
				p = make_pair(a[0], 0);
			}
			else
			{
				ans = n-(pos+1);
				p = make_pair(a[pos+1], pos+1);
			}
			cout << ans << "\n";
		}
		else if(pos == n-1)
		{
			ans = n;
			p = make_pair(a[0], 0);
			cout << ans << "\n";
		}
		else
		{
			d -= health;
			auto it = upper_bound(sum.begin(), sum.end(), d + sum[pos]);
			if(it == sum.end())
			{
				ans = n;
				p = make_pair(a[0], 0);
			}
			else
			{
				ll npos = (ll) (it - sum.begin());
				ans = n - npos;
				p = make_pair(sum[npos] - (d + sum[pos]), npos);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}