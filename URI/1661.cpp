#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() 
{
	int n;
	while(scanf("%d", &n) and n) 
	{
		vector<ll> v(n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%lld", &v[i]);
		}
		ll ans = 0;
		for(int i = 1; i < n; ++i) {
			ans += llabs(v[i-1]);
			v[i] += v[i-1];
		}
		printf("%lld\n", ans);
	}
	return 0;
}