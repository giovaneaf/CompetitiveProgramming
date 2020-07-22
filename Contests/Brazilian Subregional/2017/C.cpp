#include <stdio.h>
#include<algorithm>

typedef long long int ll;

ll mmc(ll a, ll b)
{
	return (a*b)/std::__gcd(a, b);
}

int main()
{
	int N, L;
	scanf("%d %d", &N, &L);
	ll MMC = 1;
	for(int i = 0; i < N; i++)
	{
		ll a;
		scanf("%lld", &a);
		MMC = mmc(MMC, a);
	}
	ll maior = MMC;
	ll ans = 1;
	for(int i = 2; i <= L; i++)
	{
		ll tmp = mmc(MMC, i);
		if(tmp > maior && tmp <= L)
		{
			maior = tmp;
			ans = i;
		}
	}
	printf("%lld\n", ans);
}