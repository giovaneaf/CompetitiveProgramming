#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() 
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ll d;
		int ing, b;
		scanf("%lld %d %d", &d, &ing, &b);
		vector<ll> v(ing);
		for(int i = 0; i < ing; ++i) 
		{
			scanf("%lld", &v[i]);
		}
		ll price = 0;
		int qty;
		scanf("%d", &qty);
		for(int i = 0; i < qty; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			price += v[x]*(ll) y;
		}
		for(int i = 1; i < b; ++i)
		{
			ll tmp = 0;
			scanf("%d", &qty);
			for(int j = 0; j < qty; ++j)
			{
				int x, y;
				scanf("%d %d", &x, &y);
				tmp += v[x]*(ll) y;
			}
			price = min(price, tmp);
		}
		printf("%lld\n", d/price);
	}
	return 0;
}