#include <bits/stdc++.h>
 
#define MAXN 1001
#define MAXL 300001
#define MOD 1000000007
#define INF 1000000000
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
 
ll dp[70];
 
ll f(ll number)
{
	if(number == 0) return 0LL;
	if(number == 1) return 1LL;
	int size = (int) ceil(log2(number));
	if((number & (number-1)) == 0LL) size++;
	int sz = size-1;
	ll ans = 1LL;
	ll tmp = 0LL;
	for(int i = 2; i <= sz; ++i)
	{
		if(dp[i] != -1LL)
		{
			ans += dp[i];
			continue;
		}
		tmp = 0LL;
		tmp++;
		for(int n = 1; n <= i; ++n)
		{
			for(int m = i-n; m > 0; --m)
			{
				ll num = 0LL;
				bool one = true;
				int s = n;
				for(int k = i-1; k >= 0; --k)
				{
					if(one)
						num |= (1LL << k);
					if(--s == 0)
					{
						one = !one;
						s = (one ? n : m);
					}
				}
				int r = i%(n+m);
				if((r == 0) || (r-n == 0))
				{
					tmp++;
				}
			}
		}
		dp[i] = tmp;
		ans += tmp;
	}
	bool greater = false;
	tmp = ((number == ((1LL << size) - 1LL)) ? 1LL : 0LL);
	for(int n = 1; n <= size && !greater; ++n)
	{
		for(int m = size-n; m > 0; --m)
		{
			ll num = 0LL;
			bool one = true;
			int s = n;
			for(int k = size-1; k >= 0; --k)
			{
				if(one)
					num |= (1LL << k);
				if(--s == 0)
				{
					one = !one;
					s = (one ? n : m);
				}
			}
			if(num > number)
			{
				greater = true;
				break;
			}
			int r = size%(n+m);
			if((r == 0) || (r-n == 0))
			{
				tmp++;
			}
		}
	}
	return ans+tmp;
}
 
int main()
{
	ll x, y;
	memset(dp, -1LL, sizeof(dp));
	while(cin >> x >> y)
	{
		ll ans = f(y) - f(max(0LL, x-1LL));
		cout << ans << '\n';
	}		
	return 0;
}
close