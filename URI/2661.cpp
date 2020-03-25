#include <stdio.h>
#include <math.h>
#define MAXN 1000001

typedef long long int ll;

int main()
{
	ll N;
	scanf("%lld", &N);
	ll f = 0;
	if(N%2 == 0)
		f++;
	while(N%2 == 0)
	{
		N /= 2;
	}
	for(int i = 3; i <= sqrt(N) && N > 1; i += 2)
	{
		if(N%i == 0)
		{
			f++;
			while(N%i == 0)
			{
				N /= i;
			}
		}
	}
	if(N > 1)
		f++;
	double ans = pow(2.0, f) - f - 1.0;
	printf("%.0f\n", ans);
	return 0;
}