#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll a, b;
	while(scanf("%lld %lld", &a, &b) != EOF)
	{
		printf("%lld\n", abs(a-b));
	}
	return 0;
}