#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, n) for(int i = 0; i < n; ++i)

int main()
{
	vector<ll> v(14);
	REP(i, 14)
	{
		cin >> v[i];
	}
	ll mx = 0;
	for(int i = 0; i < 14; ++i)
	{
		if(v[i] == 0) continue;
		ll qty = v[i];
		vector<ll> tmp(14);
		for(int j = 0; j < 13; ++j)
		{
			int pos = (i+1+j)%14;
			tmp[pos] = v[pos] + (qty-1)/14 + (qty > 0);
			qty--;
		}
		tmp[i] = (qty-1)/14 + (qty > 0);
		ll stones = 0;
		REP(i, 14)
		{
			if(tmp[i] & 1) continue;
			stones += tmp[i];
		}
		mx = max(stones, mx);
	}
	cout << mx << "\n";
	return 0;
}