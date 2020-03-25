#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll cost(ll cwh)
{
	if(cwh <= 100LL)
		return cwh*2LL;
	if(cwh <= 10000LL)
		return 200LL + (cwh-100LL)*3LL;
	if(cwh <= 1000000LL)
		return 200LL + 3LL*9900LL + 5LL*(cwh-10000LL);
	return 200LL + 3LL*9900LL + 5LL*990000LL + (cwh-1000000LL)*7LL;
}

ll cwh(ll cost)
{
	if(cost <= 200LL)
		return cost/2;
	cost -= 200LL;
	if(cost <= 3LL*9900LL)
		return 100LL + cost/3LL;
	cost -= 3LL*9900LL;
	if(cost <= 5LL*990000LL)
		return 10000LL + cost/5LL;
	cost -= 5LL*990000LL;
	return 1000000LL + cost/7LL;
}

int main()
{
	ll a, b;
	while(cin >> a >> b)
	{
		if(a == 0LL and b == 0LL)
			break;
		ll sum = cwh(a);
		ll low = 0LL;
		ll high = sum;
		while(low < high)
		{
			ll mid = (low+high)/2LL;
			ll rem = sum - mid;
			ll f = cost(rem) - cost(mid);
			if(f == b)
			{
				low = mid;
				break;
			}
			else if(f < b)
			{
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		printf("%lld\n", cost(low));
	}
	return 0;
}