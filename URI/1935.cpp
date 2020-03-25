#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll n, b;

ll _beans(ll layer)
{
	return 4LL*layer*n - ((2LL*layer)*(2LL*layer));
}

int main()
{
	while(scanf("%lld %lld", &n, &b) == 2)
	{
		if(b <= n)
		{
			printf("1 %lld\n", b);
		}
		else if(b <= 2LL*n-1LL)
		{
			printf("%lld %lld\n", 1 + b-n, n);
		}
		else if(b <= 3LL*n-2LL)
		{
			printf("%lld %lld\n", n, n - (b-(2LL*n-1LL)));
		}
		else if(b <= 4LL*n-4LL)
		{
			printf("%lld 1\n", n - (b-(3LL*n-2LL)));
		}
		else
		{
			ll l = 1LL;
			ll h = (n-1LL)/2LL;
			while(h - l > 1)
			{
				ll mid = (l+h)/2LL;
				if(b < _beans(mid))
				{
					h = mid-1;
				}
				else
				{
					l = mid;
				}
			}
			if(_beans(h) <= b)
				l = h;
			ll aux = n-l*2LL;
			ll beans = _beans(l);
			b -= beans;
			ll row = 1LL + l;
			ll col = l;
			if(b <= aux)
			{
				col += b;
			}
			else if(b <= 2LL*aux - 1LL)
			{
				col += aux;
				row += (b - aux);
			}
			else if(b <= 3LL*aux - 2LL)
			{
				col += (aux - (b - (2LL*aux - 1LL)));
				row += aux-1LL;
			}
			else
			{
				col++;
				row += (aux-1LL) - (b-(3LL*aux - 2LL));
			}
			printf("%lld %lld\n", row, col);
		}
	}
	return 0;
}