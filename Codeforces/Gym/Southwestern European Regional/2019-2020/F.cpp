#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
	int n;
	cin >> n;
	double area = 0;
	for(int i = 0; i < n; ++i)
	{
		double a = 0.0;
		int p;
		cin >> p;
		vector<ll> x(p);
		vector<ll> y(p);
		for(int j = 0; j < p; ++j)
		{
			cin >> x[j] >> y[j];
		}
		for(int j = 0; j < p; ++j)
		{
			a += x[j]*y[(j+1)%p] - y[j]*x[(j+1)%p];
		}
		area += fabs(a)/2.0;
	}
	printf("%lld\n", (ll) floor(area));
	return 0;
}