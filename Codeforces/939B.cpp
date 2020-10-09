#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for(int i = 0; i < n; ++i)

#define forr(i, a, b) for(int i = a; i <= b; ++i)

#define EPS 1e-9

int main()
{
	ll n, k;
	cin >> n >> k;
	ll a;
	cin >> a;
	ll b, c, hamster;
	b = 1;
	hamster = (n/a)*a;
	c = n/a;
	for(int i = 1; i < k; ++i) {
		cin >> a;
		ll tmp = (n/a)*a;
		if(tmp > hamster) {
			b = i+1;
			c = n/a;
			hamster = tmp;
		}
	}
	cout << b << " " << c << endl;
    return 0;
}