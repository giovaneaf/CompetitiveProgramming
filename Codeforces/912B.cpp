#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
 
int main()
{
	ll n, k;
	cin >> n >> k;
	if(k == 1LL) printf("%lld\n", n);
	else {
		ll i;
		for(i = 0; (1LL << i) <= n; ++i);
		cout << (1LL << i) - 1LL << endl;
	}
    return 0;
}